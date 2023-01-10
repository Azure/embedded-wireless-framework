/* generated common source file - do not edit */
#include "common_data.h"

ether_phy_instance_ctrl_t g_ether_phy0_ctrl;

const ether_phy_cfg_t g_ether_phy0_cfg =
{

    .channel                   = 0,
    .phy_lsi_address           = 0,
    .phy_reset_wait_time       = 0x00020000,
    .mii_bit_access_wait_time  = 8,
    .flow_control              = ETHER_PHY_FLOW_CONTROL_DISABLE,
    .mii_type                  = ETHER_PHY_MII_TYPE_RMII,
    .p_context                 = NULL,
    .p_extend                  = NULL,

};
/* Instance structure to use this module. */
const ether_phy_instance_t g_ether_phy0 =
{
    .p_ctrl        = &g_ether_phy0_ctrl,
    .p_cfg         = &g_ether_phy0_cfg,
    .p_api         = &g_ether_phy_on_ether_phy
};
ether_instance_ctrl_t g_ether0_ctrl;

            uint8_t g_ether0_mac_address[6] = { 0x00,0x11,0x22,0x33,0x44,0x55 };

            __attribute__((__aligned__(16))) ether_instance_descriptor_t g_ether0_tx_descriptors[4] ETHER_BUFFER_PLACE_IN_SECTION;
            __attribute__((__aligned__(16))) ether_instance_descriptor_t g_ether0_rx_descriptors[4] ETHER_BUFFER_PLACE_IN_SECTION;

            

            

            const ether_cfg_t g_ether0_cfg =
            {
                .channel            = 0,
                .zerocopy           = ETHER_ZEROCOPY_ENABLE,
                .multicast          = ETHER_MULTICAST_ENABLE,
                .promiscuous        = ETHER_PROMISCUOUS_DISABLE,
                .flow_control       = ETHER_FLOW_CONTROL_DISABLE,
                .padding            = ETHER_PADDING_2BYTE,
                .padding_offset     = 14,
                .broadcast_filter   = 0,
                .p_mac_address      = g_ether0_mac_address,

                .p_rx_descriptors   = g_ether0_rx_descriptors,
                .p_tx_descriptors   = g_ether0_tx_descriptors,

                .num_tx_descriptors = 4,
                .num_rx_descriptors = 4,

                .pp_ether_buffers   = NULL,

                .ether_buffer_size  = 1536,

#if defined(VECTOR_NUMBER_EDMAC0_EINT)
                .irq                = VECTOR_NUMBER_EDMAC0_EINT,
#else
                .irq                = FSP_INVALID_VECTOR,
#endif

                .interrupt_priority = (12),

                .p_callback         = rm_netxduo_ether_callback,
                .p_ether_phy_instance = &g_ether_phy0,
                .p_context          = &g_netxduo_ether_0_instance,
                .p_extend           = NULL,
            };

/* Instance structure to use this module. */
const ether_instance_t g_ether0 =
{
    .p_ctrl        = &g_ether0_ctrl,
    .p_cfg         = &g_ether0_cfg,
    .p_api         = &g_ether_on_ether
};
static NX_PACKET * g_netxduo_ether_0_tx_packets[4];
static NX_PACKET * g_netxduo_ether_0_rx_packets[4];

static rm_netxduo_ether_ctrl_t g_netxduo_ether_0_ctrl;
static rm_netxduo_ether_cfg_t  g_netxduo_ether_0_cfg =
{
    .p_ether_instance = &g_ether0,
    .mtu              = 1500,
    .p_tx_packets     = g_netxduo_ether_0_tx_packets,
    .p_rx_packets     = g_netxduo_ether_0_rx_packets
};

rm_netxduo_ether_instance_t g_netxduo_ether_0_instance =
{
    .p_ctrl = &g_netxduo_ether_0_ctrl,
    .p_cfg  = &g_netxduo_ether_0_cfg
};


/*
 * NetX Duo Driver: g_netxduo_ether_0
 * Passes rm_netxduo_ether instance and driver request into the rm_netxduo_ether driver.
 */
void g_netxduo_ether_0(NX_IP_DRIVER * driver_req_ptr)
{
    rm_netxduo_ether(driver_req_ptr, &g_netxduo_ether_0_instance);
}
#ifndef NX_DISABLE_IPV6
NXD_ADDRESS g_ip0_ipv6_global_address = {
    .nxd_ip_version = NX_IP_VERSION_V6,
    .nxd_ip_address.v6 = {
        ((0x2001 << 16) | 0x0),
        ((0x0 << 16) | 0x0),
        ((0x0 << 16) | 0x0),
        ((0x0 << 16) | 0x1)
    }
};

NXD_ADDRESS g_ip0_ipv6_link_local_address = {
    .nxd_ip_version = NX_IP_VERSION_V6,
    .nxd_ip_address.v6 = {
        ((0x0 << 16) | 0x0),
        ((0x0 << 16) | 0x0),
        ((0x0 << 16) | 0x0),
        ((0x0 << 16) | 0x0)
    }
};

#endif
NX_AZURE_IOT    nx_azure_iot;
icu_instance_ctrl_t pushButtonS2_ctrl;
const external_irq_cfg_t pushButtonS2_cfg =
{
    .channel             = 11,
    .trigger             = EXTERNAL_IRQ_TRIG_RISING,
    .filter_enable       = true,
    .pclk_div            = EXTERNAL_IRQ_PCLK_DIV_BY_64,
    .p_callback          = pb_callback,
    /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
    .p_context           = &NULL,
#endif
    .p_extend            = NULL,
    .ipl                 = (10),
#if defined(VECTOR_NUMBER_ICU_IRQ11)
    .irq                 = VECTOR_NUMBER_ICU_IRQ11,
#else
    .irq                 = FSP_INVALID_VECTOR,
#endif
};
/* Instance structure to use this module. */
const external_irq_instance_t pushButtonS2 =
{
    .p_ctrl        = &pushButtonS2_ctrl,
    .p_cfg         = &pushButtonS2_cfg,
    .p_api         = &g_external_irq_on_icu
};
icu_instance_ctrl_t pushButtonS1_ctrl;
const external_irq_cfg_t pushButtonS1_cfg =
{
    .channel             = 10,
    .trigger             = EXTERNAL_IRQ_TRIG_RISING,
    .filter_enable       = true,
    .pclk_div            = EXTERNAL_IRQ_PCLK_DIV_BY_64,
    .p_callback          = pb_callback,
    /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
    .p_context           = &NULL,
#endif
    .p_extend            = NULL,
    .ipl                 = (10),
#if defined(VECTOR_NUMBER_ICU_IRQ10)
    .irq                 = VECTOR_NUMBER_ICU_IRQ10,
#else
    .irq                 = FSP_INVALID_VECTOR,
#endif
};
/* Instance structure to use this module. */
const external_irq_instance_t pushButtonS1 =
{
    .p_ctrl        = &pushButtonS1_ctrl,
    .p_cfg         = &pushButtonS1_cfg,
    .p_api         = &g_external_irq_on_icu
};
ioport_instance_ctrl_t g_ioport_ctrl;
const ioport_instance_t g_ioport =
        {
            .p_api = &g_ioport_on_ioport,
            .p_ctrl = &g_ioport_ctrl,
            .p_cfg = &g_bsp_pin_cfg,
        };


TX_QUEUE g_topic_queue;
                static uint8_t queue_memory_g_topic_queue[64];
                void tx_startup_err_callback(void *p_instance, void *p_data);
void g_common_init(void) {
UINT err_g_topic_queue;
                err_g_topic_queue = tx_queue_create(&g_topic_queue, (CHAR *) "Topic Queue", 16, &queue_memory_g_topic_queue, sizeof(queue_memory_g_topic_queue));
                if (TX_SUCCESS != err_g_topic_queue) {
                    tx_startup_err_callback(&g_topic_queue, 0);
                }
}
