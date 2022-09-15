/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework linux interface implementation
 ****************************************************************************/

#include "ewf_interface.h"

#include <stdarg.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/signal.h>
#include <sys/ioctl.h>

#include "ewf_interface.h"
#include "ewf_lib.h"

/******************************************************************************
 * Serial Port Linux
 ******************************************************************************/

#define MODEMDEVICE "/dev/ttyUSB0"

int fd;
struct termios port_settings;
struct sigaction serial_irq;
static volatile uint8_t rx_flag = 0;

/* Serial RX thread */
#define EWF_SERIAL_RX_THREAD_STACK_SIZE (2048)
static TX_THREAD serial_rx_thread;
static void serial_rx_thread_entry(ULONG thread_input);
static ULONG serial_rx_thread_stack[EWF_SERIAL_RX_THREAD_STACK_SIZE / sizeof(ULONG)];

void signal_handler_IO(int status)
{
    rx_flag = 1;
}

ewf_result ewf_interface_hardware_start()
{
    int status;

    /* Initialize the serial port */
    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1)
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;

    serial_irq.sa_handler = signal_handler_IO;
    serial_irq.sa_flags = 0;
    serial_irq.sa_restorer = NULL;
    sigaction(SIGIO, &serial_irq, NULL);

    fcntl(fd, F_SETFL, FNDELAY);
    fcntl(fd, F_SETOWN, getpid());
    fcntl(fd, F_SETFL, FNDELAY | O_ASYNC | O_NONBLOCK);

    /* Get the current options */
    tcgetattr(fd, &port_settings);

    /* Setting the Baud rate */
    cfsetispeed(&port_settings, B115200);
    cfsetospeed(&port_settings, B115200);

    port_settings.c_cflag &= ~PARENB;                                                       // Disables the Parity Enable bit(PARENB),So No Parity
    port_settings.c_cflag &= ~CSTOPB;                                                       // CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit
    port_settings.c_cflag &= ~CSIZE;                                                       // Clears the mask for setting the data size
    port_settings.c_cflag |= CS8;                                                           // Set the data bits = 8
    port_settings.c_cflag &= ~CRTSCTS;                                                       // No Hardware flow Control
    port_settings.c_cflag |= CREAD | CLOCAL;                                               // Enable receiver,Ignore Modem Control lines
    port_settings.c_iflag &= ~(IXON | IXOFF | IXANY);                                       // Disable XON/XOFF flow control both i/p and o/p
    port_settings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);                               // Non Cannonical mode
    port_settings.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL); // Disable any special handling of received byte
    port_settings.c_oflag &= ~OPOST;                                                       // Disable output processing
    port_settings.c_cc[VMIN] = 0;
    port_settings.c_cc[VTIME] = 1;

    /* Set the options */
    status = tcsetattr(fd, TCSANOW, &port_settings);
    if (status != 0)
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;

    /* Create the Serial Recieve thread.  */
    status = tx_thread_create(
        &serial_rx_thread,
        "Serial Recieve",
        serial_rx_thread_entry, 0,
        serial_rx_thread_stack, EWF_SERIAL_RX_THREAD_STACK_SIZE,
        3, 3,
        TX_NO_TIME_SLICE,
        TX_AUTO_START);
    if (status != TX_SUCCESS)
    {
        exit(status);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_hardware_stop()
{
    int status;

    /* Close module */
    status = close(fd);

    if (!status)
    {
        printf("Failed to close the serial port.\n");
        return -1;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_hardware_send(const uint8_t *const buffer, uint32_t length)
{
    int status;

    /* Expect a valid buffer */
    if (!buffer)
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (length < 1)
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    /* Writing to the port */
    status = write(fd, buffer, length);
    if (status < 0)
    {
        return EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
    }
    return EWF_RESULT_OK;
}

/**
 *  @brief The Serial RX thread entry point
 */
void serial_rx_thread_entry(ULONG param)
{
    UINT status = 0;
    uint8_t rxbuf;
    int nbytes = 0;

    while (1)
    {
        while (rx_flag)
        {
            nbytes = 0;
            do
            {
                ioctl(fd, FIONREAD, &nbytes);
            } while (nbytes <= 0);

            for (int i = 0; i < nbytes; i++)
            {
                read(fd, &rxbuf, 1);

                const char *const log_msg = ewfl_escape_str_to_str_buffer((char *)&rxbuf, 1);
                EWF_LOG("[DEBG][%4u][%s]\n", 1, log_msg);
                /* Set the output parameters */
                ewf_interface_process_byte(rxbuf);
                fflush(stdout);
            }
            rx_flag = 0;
        }

        tx_thread_sleep(10);
    }
}
