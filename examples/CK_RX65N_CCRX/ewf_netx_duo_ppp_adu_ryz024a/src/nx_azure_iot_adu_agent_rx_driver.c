/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

#include "nx_azure_iot_adu_agent.h"
#include <r_flash_rx_if.h>
#include <stdio.h>
#include "demo_printf.h"

/*
#define ENABLE_SECURE_BOOT
*/

void nx_azure_iot_adu_agent_driver(NX_AZURE_IOT_ADU_AGENT_DRIVER *driver_req_ptr);

/****** DRIVER SPECIFIC ******/
void nx_azure_iot_adu_agent_driver(NX_AZURE_IOT_ADU_AGENT_DRIVER *driver_req_ptr)
{
    static uint32_t nx_azure_iot_adu_agent_driver_firmware_size;

    /* Default to successful return.  */
    driver_req_ptr -> nx_azure_iot_adu_agent_driver_status = NX_AZURE_IOT_SUCCESS;
        
    /* Process according to the driver request type.  */
    switch (driver_req_ptr -> nx_azure_iot_adu_agent_driver_command)
    {
        
        case NX_AZURE_IOT_ADU_AGENT_DRIVER_INITIALIZE:
        {
           
            /* Process initialize requests.  */
        	R_FLASH_Open();
            uint32_t bank_info = 255;
            R_FLASH_Control(FLASH_CMD_BANK_GET, &bank_info);
            LOG_TERMINAL("bank info = %d. (start bank = %d)\r\n", bank_info, (bank_info ^ 0x01));
            break;
        }
            
        case NX_AZURE_IOT_ADU_AGENT_DRIVER_PREPROCESS:
        {
            /* Process firmware preprocess requests before writing firmware.
               Such as: erase the flash at once to improve the speed.  */

            /* step1: erase all buffer bank */
            /* R_FLASH_Erase() arguments: specify "high address (low block number)" and process to "low address (high block number)" */
        	LOG_TERMINAL("erase all buffer bank = 0x%02x...", FLASH_CF_LO_BANK_LO_ADDR);

#if 1 /* for ADU actual case: ADU agent refers to actual firmware received from internet. */

#ifndef ENABLE_SECURE_BOOT
#if defined(BSP_MCU_RX65N_2MB) || defined(BSP_MCU_RX671)
            /* Non secure boot */
            R_FLASH_Erase(FLASH_CF_BLOCK_38, FLASH_NUM_BLOCKS_CF);	/* Erase all from FLASH_CF_BLOCK_38 to FLASH_CF_BLOCK_75 */
#elif defined(BSP_MCU_RX72N)
            /* Non secure boot */
            R_FLASH_Erase(FLASH_CF_BLOCK_70, FLASH_NUM_BLOCKS_CF);    /* Erase all from FLASH_CF_BLOCK_70 to FLASH_CF_BLOCK_139 */
#endif
#else
#if defined(BSP_MCU_RX65N_2MB) || defined(BSP_MCU_RX671)
            /* For OTA using secure boot loader */
            /* Erase from FLASH_CF_BLOCK_52 to FLASH_CF_BLOCK_75. Boot loader(mirror) stored from FLASH_CF_BLOCK_38 to FLASH_CF_BLOCK_51 */
            //R_FLASH_Erase(FLASH_CF_BLOCK_52, 24); /* Boot loader ROM size = 256KB*/

            /* Erase from FLASH_CF_BLOCK_46 to FLASH_CF_BLOCK_75. Boot loader(mirror) stored from FLASH_CF_BLOCK_38 to FLASH_CF_BLOCK_45 */
            R_FLASH_Erase(FLASH_CF_BLOCK_46, 30); /* Boot loader ROM size = 64KB*/
#elif defined(BSP_MCU_RX72N)
            /* For OTA using secure boot loader */
            /* Erase from FLASH_CF_BLOCK_84 to FLASH_CF_BLOCK_139. Boot loader(mirror) stored from FLASH_CF_BLOCK_70 to FLASH_CF_BLOCK_83 */
            //R_FLASH_Erase(FLASH_CF_BLOCK_84, 56); /* Boot loader ROM size = 256KB*/

            /* Erase from FLASH_CF_BLOCK_78 to FLASH_CF_BLOCK_139. Boot loader(mirror) stored from FLASH_CF_BLOCK_70 to FLASH_CF_BLOCK_77 */
            R_FLASH_Erase(FLASH_CF_BLOCK_78, 62); /* Boot loader ROM size = 64KB*/
#endif

#endif /* ENABLE_SECURE_BOOT */

#else /* for ADU simulator case: ADU simulator refers to sample_firmware_ptr that is located in 0xffe00000-0xffe7ffff */
            R_FLASH_Erase(FLASH_CF_BLOCK_60, 16);					/* Erase all from FLASH_CF_BLOCK_60 to FLASH_CF_BLOCK_75 */
#endif

            LOG_TERMINAL("completed.\n");
        	nx_azure_iot_adu_agent_driver_firmware_size = driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_size;

        	break;
        }
            
        case NX_AZURE_IOT_ADU_AGENT_DRIVER_WRITE:
        {

#if 1 /* for ADU actual case: ADU agent refers to actual firmware received from internet. */
#if defined(BSP_MCU_RX65N_2MB) || defined(BSP_MCU_RX671)
        	static uint32_t current_physical_address_to_write = 0xffe00000;
        	//static uint32_t current_physical_address_to_write = 0xffe60000;
#elif defined(BSP_MCU_RX72N)
        	static uint32_t current_physical_address_to_write = 0xffc00000;
#endif
#else /* for ADU simulator case: ADU simulator refers to sample_firmware_ptr that is located in 0xffe00000-0xffe7ffff */
        	static uint32_t current_physical_address_to_write = 0xffe80000;
#endif
        	static uint8_t fragmented_data[FLASH_CF_MIN_PGM_SIZE];
        	static uint8_t fragmented_data_size = 0;
        	static uint32_t total_written_data_size = 0;
        	uint32_t remaining_bytes = driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_data_size;
        	uint32_t current_data_offset = 0;
        	UCHAR *nx_azure_iot_adu_agent_driver_firmware_data_ptr_temp;

        	flash_err_t flash_err;
        	uint32_t written_data_size = 0;

            /* Process firmware write requests.  */
            
            /* Write firmware contents.
               1. This function must support figure out which bank it should write to.
               2. Write firmware contents into new bank.
               3. Decrypt and authenticate the firmware itself if needed.
            */
            
            /* step2: copy from specified binary to buffer bank with specified offset */
            /* R_FLASH_Write() arguments: specify "low address" and process to "high address" */

        	uint32_t TARGET_ADDRESS = 0xffe15400;//0xffe15540;

        	/* assemble previous fragmented_data if fragmented_data_size would remain */
        	if(fragmented_data_size)
        	{
        		/* write fragmented_data and head of current data */
        		if(fragmented_data_size + remaining_bytes >= FLASH_CF_MIN_PGM_SIZE)
        		{
        		    if ((current_physical_address_to_write >= (TARGET_ADDRESS - fragmented_data_size - remaining_bytes)) && (current_physical_address_to_write < (TARGET_ADDRESS)))
        		        R_BSP_NOP();
					memcpy(&fragmented_data[fragmented_data_size], driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_data_ptr, FLASH_CF_MIN_PGM_SIZE - fragmented_data_size);
					flash_err = R_FLASH_Write((uint32_t)fragmented_data, current_physical_address_to_write, FLASH_CF_MIN_PGM_SIZE);
	                if (flash_err != FLASH_SUCCESS) LOG_TERMINAL("FLASH Write Error");
					current_physical_address_to_write += FLASH_CF_MIN_PGM_SIZE;
					remaining_bytes -= FLASH_CF_MIN_PGM_SIZE - fragmented_data_size;
					current_data_offset += FLASH_CF_MIN_PGM_SIZE - fragmented_data_size;
					written_data_size += FLASH_CF_MIN_PGM_SIZE;
					total_written_data_size += FLASH_CF_MIN_PGM_SIZE;
        		}
        		/* concatenate current data into tail of fragmented_data */
        		else
        		{
					memcpy(&fragmented_data[fragmented_data_size], driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_data_ptr, remaining_bytes);
					fragmented_data_size += remaining_bytes;
					break;
        		}
        	}

        	/* write the firmware per FLASH_CF_MIN_PGM_SIZE while remaining_bytes would exist */
        	while(remaining_bytes > FLASH_CF_MIN_PGM_SIZE)
        	{
                if ((current_physical_address_to_write >= TARGET_ADDRESS - FLASH_CF_MIN_PGM_SIZE) && (current_physical_address_to_write  < TARGET_ADDRESS ))
                    R_BSP_NOP();
                nx_azure_iot_adu_agent_driver_firmware_data_ptr_temp = (uint32_t)driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_data_ptr + current_data_offset;
                flash_err = R_FLASH_Write((uint32_t)nx_azure_iot_adu_agent_driver_firmware_data_ptr_temp, current_physical_address_to_write, FLASH_CF_MIN_PGM_SIZE);
        		//flash_err = R_FLASH_Write((uint32_t)driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_data_ptr + current_data_offset, current_physical_address_to_write, FLASH_CF_MIN_PGM_SIZE);
        		if (flash_err != FLASH_SUCCESS) LOG_TERMINAL("FLASH Write Error");
				current_physical_address_to_write += FLASH_CF_MIN_PGM_SIZE;
        		remaining_bytes -= FLASH_CF_MIN_PGM_SIZE;
        		current_data_offset += FLASH_CF_MIN_PGM_SIZE;
				written_data_size += FLASH_CF_MIN_PGM_SIZE;
				total_written_data_size += FLASH_CF_MIN_PGM_SIZE;
        	}

        	/* store the g_remaining_bytes into fragmented_data for next receiving. */
        	if(remaining_bytes)
        	{
        		memset(fragmented_data, 0, sizeof(fragmented_data));
        		memcpy(fragmented_data, driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_data_ptr + current_data_offset, remaining_bytes);
        	}
    		fragmented_data_size = remaining_bytes;

        	/* write last 1 block */
        	if((total_written_data_size + FLASH_CF_MIN_PGM_SIZE) == nx_azure_iot_adu_agent_driver_firmware_size)
        	{
        		flash_err = R_FLASH_Write((uint32_t)fragmented_data, current_physical_address_to_write, FLASH_CF_MIN_PGM_SIZE);
        		 if (flash_err != FLASH_SUCCESS) LOG_TERMINAL("FLASH Write Error");
        		current_physical_address_to_write += FLASH_CF_MIN_PGM_SIZE;
        		remaining_bytes -= FLASH_CF_MIN_PGM_SIZE;
        		current_data_offset += FLASH_CF_MIN_PGM_SIZE;
				written_data_size += FLASH_CF_MIN_PGM_SIZE;
				total_written_data_size += FLASH_CF_MIN_PGM_SIZE;
        	}
#if 0
        	LOG_TERMINAL("requested %4d bytes writing (address from %08x to %08x (128 byte block(s) = %2d)) are completed with %3d bytes are fragmented.\n",
        			driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_data_size,
					current_physical_address_to_write - written_data_size,
					current_physical_address_to_write,
					written_data_size / FLASH_CF_MIN_PGM_SIZE,
					remaining_bytes);
        	LOG_TERMINAL("Azure ADU library puts these arguments: \n\
        			nx_azure_iot_adu_agent_driver_firmware_size = %d,\n\
        			nx_azure_iot_adu_agent_driver_firmware_data_offset = %d,\n\
        			nx_azure_iot_adu_agent_driver_firmware_data_size = %d\n",\
					driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_size,
					driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_data_offset,
					driver_req_ptr->nx_azure_iot_adu_agent_driver_firmware_data_size);

#endif

            break;
        } 
            
        case NX_AZURE_IOT_ADU_AGENT_DRIVER_INSTALL:
        {

            /* Set the new firmware for next boot.  */

            /* step3: bankswap */
        	LOG_TERMINAL("starting software reset...\r\n");

#ifndef ENABLE_SECURE_BOOT
            R_BSP_SoftwareDelay(1, BSP_DELAY_SECS); /* wait all printf() outputs and interrupts */
            R_BSP_InterruptsDisable();
            R_FLASH_Control(FLASH_CMD_BANK_TOGGLE, NULL);
            R_BSP_InterruptsEnable();
#endif /* ENABLE_SECURE_BOOT */

            break;
        } 
            
        case NX_AZURE_IOT_ADU_AGENT_DRIVER_APPLY:
        {

            /* Apply the new firmware, and reboot device from that.*/
            /* step4: software reset */
            /* close all peripherals before software reset */
            R_BSP_InterruptsDisable();
            R_FLASH_Close();
            R_BSP_SoftwareReset();
            break;
        } 
        default:
        {
                
            /* Invalid driver request.  */

            /* Default to successful return.  */
            driver_req_ptr -> nx_azure_iot_adu_agent_driver_status =  NX_AZURE_IOT_FAILURE;
        }
    }
}
