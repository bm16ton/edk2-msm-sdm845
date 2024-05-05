#ifndef __EFI_QCOM_SMEM_H__
#define __EFI_QCOM_SMEM_H__

#define SMEM_VERSION_ID                     0x000C0000

#define SMEM_MAJOR_VERSION_MASK             0xFFFF0000
#define SMEM_MINOR_VERSION_MASK             0x0000FFFF
#define SMEM_FULL_VERSION_MASK              0xFFFFFFFF

#define SMEM_NUM_SMD_CHANNELS               64
#define SMEM_NUM_SMP2P_EDGES                8

typedef enum
{
  SMEM_MEM_FIRST,
  SMEM_RESERVED_PROC_COMM = SMEM_MEM_FIRST,
  SMEM_FIRST_FIXED_BUFFER = SMEM_RESERVED_PROC_COMM,
  SMEM_HEAP_INFO,
  SMEM_ALLOCATION_TABLE,
  SMEM_VERSION_INFO,
  SMEM_HW_RESET_DETECT,
  SMEM_RESERVED_AARM_WARM_BOOT,
  SMEM_DIAG_ERR_MESSAGE,
  SMEM_SPINLOCK_ARRAY,
  SMEM_MEMORY_BARRIER_LOCATION,
  SMEM_LAST_FIXED_BUFFER = SMEM_MEMORY_BARRIER_LOCATION,
  SMEM_AARM_PARTITION_TABLE,
  SMEM_AARM_BAD_BLOCK_TABLE,
  SMEM_ERR_CRASH_LOG_ADSP,
  SMEM_BOOT_BOARD_INFO,
  SMEM_CHANNEL_ALLOC_TBL,
  SMEM_SMD_BASE_ID,
  SMEM_SMEM_LOG_IDX = SMEM_SMD_BASE_ID + SMEM_NUM_SMD_CHANNELS,
  SMEM_SMEM_LOG_EVENTS,
  SMEM_RESERVED_SMEM_STATIC_LOG_IDX,
  SMEM_XBL_LOADER_CORE_INFO = 
  SMEM_RESERVED_SMEM_STATIC_LOG_IDX,
  SMEM_RESERVED_SMEM_STATIC_LOG_EVENTS,
  SMEM_CHARGER_BATTERY_INFO =
  SMEM_RESERVED_SMEM_STATIC_LOG_EVENTS,
  SMEM_RESERVED_SMEM_SLOW_CLOCK_SYNC,
  SMEM_WLAN_CONFIG =
  SMEM_RESERVED_SMEM_SLOW_CLOCK_SYNC,
  SMEM_RESERVED_SMEM_SLOW_CLOCK_VALUE,
  SMEM_RESERVED_BIO_LED_BUF,
  SMEM_SMSM_SHARED_STATE,
  SMEM_RESERVED_SMSM_INT_INFO,
  SMEM_RESERVED_SMSM_SLEEP_DELAY,
  SMEM_RESERVED_SMSM_LIMIT_SLEEP,
  SMEM_RESERVED_SLEEP_POWER_COLLAPSE_DISABLED,
  SMEM_RESERVED_KEYPAD_KEYS_PRESSED,
  SMEM_RESERVED_KEYPAD_STATE_UPDATED,
  SMEM_RESERVED_KEYPAD_STATE_IDX,
  SMEM_RESERVED_GPIO_INT,
  SMEM_ID_SMP2P_BASE_CDSP,
  SMEM_RESERVED_SMD_PROFILES = SMEM_ID_SMP2P_BASE_CDSP + 
                                 SMEM_NUM_SMP2P_EDGES,
  SMEM_RESERVED_TSSC_BUSY,
  SMEM_RESERVED_HS_SUSPEND_FILTER_INFO,
  SMEM_RESERVED_BATT_INFO,
  SMEM_RESERVED_APPS_BOOT_MODE,
  SMEM_VERSION_FIRST,
  SMEM_VERSION_SMD = SMEM_VERSION_FIRST,
  SMEM_VERSION_SMD_BRIDGE,
  SMEM_VERSION_SMSM,
  SMEM_VERSION_SMD_NWAY_LOOP,
  SMEM_VERSION_LAST = SMEM_VERSION_FIRST + 24,
  SMEM_RESERVED_OSS_RRCASN1_BUF1,
  SMEM_RESERVED_OSS_RRCASN1_BUF2,
  SMEM_ID_VENDOR0,
  SMEM_ID_VENDOR1,
  SMEM_ID_VENDOR2,
  SMEM_HW_SW_BUILD_ID,
  SMEM_RESERVED_SMD_BLOCK_PORT_BASE_ID,
  SMEM_RESERVED_SMD_BLOCK_PORT_PROC0_HEAP = 
                   SMEM_RESERVED_SMD_BLOCK_PORT_BASE_ID + 
                   SMEM_NUM_SMD_CHANNELS,
  SMEM_RESERVED_SMD_BLOCK_PORT_PROC1_HEAP = 
                   SMEM_RESERVED_SMD_BLOCK_PORT_PROC0_HEAP +
                   SMEM_NUM_SMD_CHANNELS,
  SMEM_I2C_MUTEX = SMEM_RESERVED_SMD_BLOCK_PORT_PROC1_HEAP + 
                   SMEM_NUM_SMD_CHANNELS,
  SMEM_SCLK_CONVERSION,
  SMEM_RESERVED_SMD_SMSM_INTR_MUX,
  SMEM_SMSM_CPU_INTR_MASK,
  SMEM_RESERVED_APPS_DEM_SLAVE_DATA,
  SMEM_RESERVED_QDSP6_DEM_SLAVE_DATA,
  SMEM_VSENSE_DATA,
  SMEM_RESERVED_CLKREGIM_SOURCES,
  SMEM_SMD_FIFO_BASE_ID,
  SMEM_USABLE_RAM_PARTITION_TABLE = SMEM_SMD_FIFO_BASE_ID +
                                    SMEM_NUM_SMD_CHANNELS,
  SMEM_POWER_ON_STATUS_INFO,
  SMEM_DAL_AREA,
  SMEM_SMEM_LOG_POWER_IDX,
  SMEM_SMEM_LOG_POWER_WRAP,
  SMEM_SMEM_LOG_POWER_EVENTS,
  SMEM_ERR_CRASH_LOG,
  SMEM_ERR_F3_TRACE_LOG,
  SMEM_SMD_BRIDGE_ALLOC_TABLE,
  SMEM_SMD_FEATURE_SET,
  SMEM_RESERVED_SD_IMG_UPGRADE_STATUS,
  SMEM_SEFS_INFO,
  SMEM_RESERVED_RESET_LOG,
  SMEM_RESERVED_RESET_LOG_SYMBOLS,
  SMEM_MODEM_SW_BUILD_ID,
  SMEM_SMEM_LOG_MPROC_WRAP,
  SMEM_RESERVED_BOOT_INFO_FOR_APPS,
  SMEM_SMSM_SIZE_INFO,
  SMEM_SMD_LOOPBACK_REGISTER,
  SMEM_SSR_REASON_MSS0,
  SMEM_SSR_REASON_WCNSS0,
  SMEM_SSR_REASON_LPASS0,
  SMEM_SSR_REASON_DSPS0,
  SMEM_SSR_REASON_VCODEC0,
  SMEM_VOICE,
  SMEM_ID_SMP2P_BASE_APPS,
  SMEM_ID_SMP2P_BASE_MODEM = SMEM_ID_SMP2P_BASE_APPS + 
                              SMEM_NUM_SMP2P_EDGES,
  SMEM_ID_SMP2P_BASE_ADSP = SMEM_ID_SMP2P_BASE_MODEM + 
                              SMEM_NUM_SMP2P_EDGES,
  SMEM_ID_SMP2P_BASE_WCN = SMEM_ID_SMP2P_BASE_ADSP + 
                              SMEM_NUM_SMP2P_EDGES,
  SMEM_ID_SMP2P_BASE_RPM = SMEM_ID_SMP2P_BASE_WCN + 
                              SMEM_NUM_SMP2P_EDGES,
  SMEM_FLASH_DEVICE_INFO = SMEM_ID_SMP2P_BASE_RPM + 
                              SMEM_NUM_SMP2P_EDGES,
  SMEM_BAM_PIPE_MEMORY,
  SMEM_IMAGE_VERSION_TABLE,
  SMEM_LC_DEBUGGER,
  SMEM_FLASH_NAND_DEV_INFO,
  SMEM_A2_BAM_DESCRIPTOR_FIFO,
  SMEM_CPR_CONFIG,
  SMEM_CLOCK_INFO,
  SMEM_IPC_INFO,
  SMEM_RF_EEPROM_DATA,
  SMEM_COEX_MDM_WCN,
  SMEM_GLINK_NATIVE_XPORT_DESCRIPTOR,
  SMEM_GLINK_NATIVE_XPORT_FIFO_0,
  SMEM_GLINK_NATIVE_XPORT_FIFO_1,
  SMEM_ID_SMP2P_BASE_SSC = 481,
  SMEM_ID_SMP2P_BASE_TZ  = SMEM_ID_SMP2P_BASE_SSC + 
                           SMEM_NUM_SMP2P_EDGES,
  SMEM_IPA_FILTER_TABLE  = SMEM_ID_SMP2P_BASE_TZ + 
                           SMEM_NUM_SMP2P_EDGES,   
  SMEM_MEM_LAST          = SMEM_IPA_FILTER_TABLE,						   
  SMEM_INVALID
} smem_mem_type;

typedef enum 
{
  SMEM_APPS         =  0, 
  SMEM_MODEM        =  1, 
  SMEM_ADSP         =  2, 
  SMEM_SSC          =  3, 
  SMEM_WCN          =  4, 
  SMEM_CDSP         =  5, 
  SMEM_RPM          =  6, 
  SMEM_TZ           =  7, 
  SMEM_SPSS         =  8, 
  SMEM_HYP          =  9, 
  SMEM_NUM_HOSTS    = 10, 

  SMEM_Q6        = SMEM_ADSP,   
  SMEM_RIVA      = SMEM_WCN,             
  SMEM_DSPS      = SMEM_SSC,   
  SMEM_CMDDB        = 0xFFFD,  
  SMEM_COMMON_HOST  = 0xFFFE,  
  SMEM_INVALID_HOST = 0xFFFF,  
}smem_host_type;

#define EFI_SMEM_PROTOCOL_REVISION 0x0000000000010001

#define EFI_SMEM_PROTOCOL_GUID \
  { 0xf4e5c7d0, 0xd239, 0x47cb, { 0xaa, 0xcd, 0x7f, 0x66, 0xef, 0x76, 0x32, 0x38 } }

typedef struct _EFI_QCOM_SMEM_PROTOCOL EFI_QCOM_SMEM_PROTOCOL;

extern EFI_GUID gQcomSMEMProtocolGuid;

typedef EFI_STATUS (EFIAPI *EFI_SMEM_ALLOC)(
  IN smem_mem_type        item,
  IN UINT32               size,
  OUT void               **addr
  );

typedef EFI_STATUS (EFIAPI *EFI_SMEM_GET_ADDR)(
  IN smem_mem_type        item,
  OUT UINT32              *size,
  OUT void               **addr
  );

struct _EFI_QCOM_SMEM_PROTOCOL {
  UINT64                Revision;
  EFI_SMEM_ALLOC        SmemAlloc;
  EFI_SMEM_GET_ADDR     SmemGetAddr;
};

#endif
