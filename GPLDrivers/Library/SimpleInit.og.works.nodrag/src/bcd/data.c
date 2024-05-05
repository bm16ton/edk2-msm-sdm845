/*
 *
 * Copyright (C) 2021 BigfootACA <bigfoot@classfun.cn>
 *
 * SPDX-License-Identifier: LGPL-3.0-or-later
 *
 */

#ifdef ENABLE_HIVEX
#include"array.h"
#include"bcdstore.h"
const char*bcd_type_debugger_type_name[]={
	[BCD_DebuggerType_Serial]      = "Serial",
	[BCD_DebuggerType_1394]        = "1394",
	[BCD_DebuggerType_Usb]         = "Usb",
	[BCD_DebuggerType_Net]         = "Net",
	[BCD_DebuggerType_Local]       = "Local",
};
const char*bcd_type_safe_boot_name[]={
	[BCD_SafeBoot_Minimal]         = "Minimal",
	[BCD_SafeBoot_Network]         = "Network",
	[BCD_SafeBoot_DsRepair]        = "DsRepair",
};
const char*bcd_type_nx_policy_name[]={
	[BCD_NxPolicy_OptIn]           = "OptIn",
	[BCD_NxPolicy_OptOut]          = "OptOut",
	[BCD_NxPolicy_AlwaysOff]       = "AlwaysOff",
	[BCD_NxPolicy_AlwaysOn]        = "AlwaysOn",
};
const char*bcd_type_pae_policy_name[]={
	[BCD_PAEPolicy_Default]        = "Default",
	[BCD_PAEPolicy_ForceEnable]    = "ForceEnable",
	[BCD_PAEPolicy_ForceDisable]   = "ForceDisable",
};
const char*bcd_type_device_type_name[]={
	[BCD_DT_DiskDevice]            = "DiskDevice",
	[BCD_DT_Unknown0]              = NULL,
	[BCD_DT_LegacyPartitionDevice] = "LegacyPartitionDevice",
	[BCD_DT_SerialDevice]          = "SerialDevice",
	[BCD_DT_UdpDevice]             = "UdpDevice",
	[BCD_DT_BootDevice]            = "BootDevice",
	[BCD_DT_PartitionDevice]       = "PartitionDevice",
	[BCD_DT_Unknown1]              = NULL,
	[BCD_DT_LocateDevice]          = "LocateDevice",
};
const char*bcd_type_boot_menu_policy_name[]={
	[BCD_BootMenuPolicy_Legacy]    = "Legacy",
	[BCD_BootMenuPolicy_Standard]  = "Standard",
};
const char*bcd_type_local_device_type_name[]={
	[BCD_LDT_LocalDevice]          = "LocalDevice",
	[BCD_LDT_FloppyDevice]         = "FloppyDevice",
	[BCD_LDT_CdRomDevice]          = "CdRomDevice",
	[BCD_LDT_RamDiskDevice]        = "RamDiskDevice",
	[BCD_LDT_Unknown0]             = NULL,
	[BCD_LDT_FileDevice]           = "FileDevice",
	[BCD_LDT_VirtualDiskDevice]    = "VirtualDiskDevice",
};
const char*bcd_type_boot_ux_display_message_name[]={
	[BCD_BDM_Default]              = "Default",
	[BCD_BDM_Resume]               = "Resume",
	[BCD_BDM_HyperV]               = "HyperV",
	[BCD_BDM_Recovery]             = "Recovery",
	[BCD_BDM_StartupRepair]        = "StartupRepair",
	[BCD_BDM_SystemImageRecovery]  = "SystemImageRecovery",
	[BCD_BDM_CommandPrompt]        = "CommandPrompt",
	[BCD_BDM_SystemRestore]        = "SystemRestore",
	[BCD_BDM_PushButtonReset]      = "PushButtonReset",
	[BCD_BDM_FactoryReset]         = "FactoryReset",
	[BCD_BDM_FveRecovery]          = "FveRecovery",
};
#define BCD_DECLARE_SPEC_TYPE(_id,_table) {.type=(_id),.table=(_table),.length=ARRLEN(_table)}
struct bcd_spec_type_table BcdSpecTypes[]={
	BCD_DECLARE_SPEC_TYPE(0x15000011, bcd_type_debugger_type_name           ), // DebuggerType
	BCD_DECLARE_SPEC_TYPE(0x15000065, bcd_type_boot_ux_display_message_name ), // BootUxDisplayMessage
	BCD_DECLARE_SPEC_TYPE(0x15000066, bcd_type_boot_ux_display_message_name ), // BootUxDisplayMessageOverride
	BCD_DECLARE_SPEC_TYPE(0x25000020, bcd_type_nx_policy_name               ), // NxPolicy
	BCD_DECLARE_SPEC_TYPE(0x25000021, bcd_type_pae_policy_name              ), // PAEPolicy
	BCD_DECLARE_SPEC_TYPE(0x25000080, bcd_type_safe_boot_name               ), // SafeBoot
	BCD_DECLARE_SPEC_TYPE(0x250000C2, bcd_type_boot_menu_policy_name        ), // BootMenuPolicy
	BCD_DECLARE_SPEC_TYPE(0x250000F3, bcd_type_debugger_type_name           ), // HypervisorDebuggerType
	{0,NULL,0}
};
struct bcd_object_type_table BcdObjectType[]={
	{ 0x10000000, "Inherit"             },
	{ 0x10100000, "Firmware"            },
	{ 0x10100001, "Firmware-FWBootMgr"  },
	{ 0x10100002, "Firmware-BootMgr"    },
	{ 0x101FFFFF, "Firmware-Firmware"   },
	{ 0x10200000, "Boot"                },
	{ 0x10200003, "Boot-OSLoader"       },
	{ 0x10200004, "Boot-Resume"         },
	{ 0x10200005, "Boot-MemDiag"        },
	{ 0x10300000, "Legacy"              },
	{ 0x10300006, "Legacy-NtLdr"        },
	{ 0x10300007, "Legacy-SetupLdr"     },
	{ 0x10300008, "Legacy-BootSector"   },
	{ 0x10400000, "RealMode"            },
	{ 0x10400008, "RealMode-BootSector" },
	{ 0x10400009, "RealMode-Startup"    },
	{ 0x1020000A, "RealMode-BootApp"    },
	{ 0x20000000, "Inherit"             },
	{ 0x20100000, "Inherit-Any"         },
	{ 0x20200001, "Inherit-FWBootMgr"   },
	{ 0x20200002, "Inherit-BootMgr"     },
	{ 0x20200003, "Inherit-OSLoader"    },
	{ 0x20200004, "Inherit-Resume"      },
	{ 0x20200005, "Inherit-MemDiag"     },
	{ 0x20200006, "Inherit-NtLdr"       },
	{ 0x20200008, "Inherit-BootSector"  },
	{ 0x20300000, "Inherit-Device"      },
	{ 0x30000000, "Device"              },
	{0,NULL}
};
struct bcd_element_type_table BcdElementType[]={
	{ 0x24000001, "DisplayOrder"                     ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x24000002, "BootSequence"                     ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x23000003, "DefaultObject"                    ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x25000004, "Timeout"                          ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x26000005, "AttemptResume"                    ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x23000006, "ResumeObject"                     ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x24000010, "ToolsDisplayOrder"                ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x26000020, "DisplayBootMenu"                  ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x26000021, "NoErrorDisplay"                   ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x21000022, "BcdDevice"                        ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x22000023, "BcdFilePath"                      ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x26000028, "ProcessCustomActionsFirst"        ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x27000030, "CustomActionsList"                ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x26000031, "PersistBootSequence"              ,(int32_t[]){ 0x10100001, 0x10100002, 0x20200001, 0x20200002, 0 }},
	{ 0x35000001, "RamdiskImageOffset"               ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x35000002, "TftpClientPort"                   ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x31000003, "SdiDevice"                        ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x32000004, "SdiPath"                          ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x35000005, "RamdiskImageLength"               ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x36000006, "RamdiskExportAsCd"                ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x36000007, "RamdiskTftpBlockSize"             ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x36000008, "RamdiskTftpWindowSize"            ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x36000009, "RamdiskMulticastEnabled"          ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x3600000A, "RamdiskMulticastTftpFallback"     ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x3600000B, "RamdiskTftpVarWindow"             ,(int32_t[]){ 0x10300000, 0 }},
	{ 0x25000001, "PassCount"                        ,(int32_t[]){ 0x10200005, 0x20200005, 0 }},
	{ 0x25000003, "FailureCount"                     ,(int32_t[]){ 0x10200005, 0x20200005, 0 }},
	{ 0x21000001, "OSDevice"                         ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x22000002, "SystemRoot"                       ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x23000003, "AssociatedResumeObject"           ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000010, "DetectKernelAndHal"               ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x22000011, "KernelPath"                       ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x22000012, "HalPath"                          ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x22000013, "DbgTransportPath"                 ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000020, "NxPolicy"                         ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000021, "PAEPolicy"                        ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000022, "WinPEMode"                        ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000024, "DisableCrashAutoReboot"           ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000025, "UseLastGoodSettings"              ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000027, "AllowPrereleaseSignatures"        ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000030, "NoLowMemory"                      ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000031, "RemoveMemory"                     ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000032, "IncreaseUserVa"                   ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000040, "UseVgaDriver"                     ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000041, "DisableBootDisplay"               ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000042, "DisableVesaBios"                  ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000043, "DisableVgaMode"                   ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000050, "ClusterModeAddressing"            ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000051, "UsePhysicalDestination"           ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000052, "RestrictApicCluster"              ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000054, "UseLegacyApicMode"                ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000055, "X2ApicPolicy"                     ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000060, "UseBootProcessorOnly"             ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000061, "NumberOfProcessors"               ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000062, "ForceMaximumProcessors"           ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000063, "ProcessorConfigurationFlags"      ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000064, "MaximizeGroupsCreated"            ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000065, "ForceGroupAwareness"              ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000066, "GroupSize"                        ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000070, "UseFirmwarePciSettings"           ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000071, "MsiPolicy"                        ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000080, "SafeBoot"                         ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000081, "SafeBootAlternateShell"           ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000090, "BootLogInitialization"            ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000091, "VerboseObjectLoadMode"            ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x260000A0, "KernelDebuggerEnabled"            ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x260000A1, "DebuggerHalBreakpoint"            ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x260000A2, "UsePlatformClock"                 ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x260000A3, "ForceLegacyPlatform"              ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000A6, "TscSyncPolicy"                    ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x260000B0, "EmsEnabled"                       ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000C1, "DriverLoadFailurePolicy"          ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000C2, "BootMenuPolicy"                   ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x260000C3, "AdvancedOptionsOneTime"           ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x260000C4, "OptionsEditOneTime"               ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000E0, "BootStatusPolicy"                 ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x260000E1, "DisableElamDrivers"               ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000F0, "HypervisorLaunchType"             ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x260000F2, "HypervisorDebuggerEnabled"        ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000F3, "HypervisorDebuggerType"           ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000F4, "HypervisorDebuggerPortNumber"     ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000F5, "HypervisorDebuggerBaudrate"       ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000F6, "HypervisorDebugger1394Channel"    ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000F7, "BootUxPolicy"                     ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x220000F9, "HypervisorDebuggerBusParams"      ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000FA, "HypervisorNumProc"                ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000FB, "HypervisorRootProcPerNode"        ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x260000FC, "HypervisorUseLargeVTlb"           ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000FD, "HypervisorDebuggerNetHostIp"      ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x250000FE, "HypervisorDebuggerNetHostPort"    ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000100, "TpmBootEntropyPolicy"             ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x22000110, "HypervisorDebuggerNetKey"         ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x26000114, "HypervisorDebuggerNetDhcp"        ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x25000115, "HypervisorIommuPolicy"            ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x2500012B, "XSaveDisable"                     ,(int32_t[]){ 0x10200003, 0x20200003, 0 }},
	{ 0x21000001, "Reserved1"                        ,(int32_t[]){ 0x10200004, 0x20200004, 0 }},
	{ 0x22000002, "Reserved2"                        ,(int32_t[]){ 0x10200004, 0x20200004, 0 }},
	{ 0x26000003, "UseCustomSettings"                ,(int32_t[]){ 0x10200004, 0x20200004, 0 }},
	{ 0x21000005, "AssociatedOsDevice"               ,(int32_t[]){ 0x10200004, 0x20200004, 0 }},
	{ 0x26000006, "DebugOptionEnabled"               ,(int32_t[]){ 0x10200004, 0x20200004, 0 }},
	{ 0x25000008, "BootMenuPolicy"                   ,(int32_t[]){ 0x10200004, 0x20200004, 0 }},
	{ 0x11000001, "ApplicationDevice"                ,NULL },
	{ 0x12000002, "ApplicationPath"                  ,NULL },
	{ 0x12000004, "Description"                      ,NULL },
	{ 0x12000005, "PreferredLocale"                  ,NULL },
	{ 0x14000006, "InheritedObjects"                 ,NULL },
	{ 0x15000007, "TruncatePhysicalMemory"           ,NULL },
	{ 0x14000008, "RecoverySequence"                 ,NULL },
	{ 0x16000009, "AutoRecoveryEnabled"              ,NULL },
	{ 0x1700000A, "BadMemoryList"                    ,NULL },
	{ 0x1600000B, "AllowBadMemoryAccess"             ,NULL },
	{ 0x1500000C, "FirstMegabytePolicy"              ,NULL },
	{ 0x1500000D, "RelocatePhysicalMemory"           ,NULL },
	{ 0x1500000E, "AvoidLowPhysicalMemory"           ,NULL },
	{ 0x16000010, "DebuggerEnabled"                  ,NULL },
	{ 0x15000011, "DebuggerType"                     ,NULL },
	{ 0x15000012, "SerialDebuggerPortAddress"        ,NULL },
	{ 0x15000013, "SerialDebuggerPort"               ,NULL },
	{ 0x15000014, "SerialDebuggerBaudRate"           ,NULL },
	{ 0x15000015, "1394DebuggerChannel"              ,NULL },
	{ 0x12000016, "UsbDebuggerTargetName"            ,NULL },
	{ 0x16000017, "DebuggerIgnoreUsermodeExceptions" ,NULL },
	{ 0x15000018, "DebuggerStartPolicy"              ,NULL },
	{ 0x12000019, "DebuggerBusParameters"            ,NULL },
	{ 0x1500001A, "DebuggerNetHostIP"                ,NULL },
	{ 0x1500001B, "DebuggerNetPort"                  ,NULL },
	{ 0x1600001C, "DebuggerNetDhcp"                  ,NULL },
	{ 0x1200001D, "DebuggerNetKey"                   ,NULL },
	{ 0x16000020, "EmsEnabled"                       ,NULL },
	{ 0x15000022, "EmsPort"                          ,NULL },
	{ 0x15000023, "EmsBaudRate"                      ,NULL },
	{ 0x12000030, "LoadOptionsString"                ,NULL },
	{ 0x16000040, "DisplayAdvancedOptions"           ,NULL },
	{ 0x16000041, "DisplayOptionsEdit"               ,NULL },
	{ 0x11000043, "BsdLogDevice"                     ,NULL },
	{ 0x12000044, "BsdLogPath"                       ,NULL },
	{ 0x16000045, "PreserveBsdLog"                   ,NULL },
	{ 0x16000046, "GraphicsModeDisabled"             ,NULL },
	{ 0x15000047, "ConfigAccessPolicy"               ,NULL },
	{ 0x16000048, "DisableIntegrityChecks"           ,NULL },
	{ 0x16000049, "AllowPrereleaseSignatures"        ,NULL },
	{ 0x1200004A, "FontPath"                         ,NULL },
	{ 0x1500004B, "SiPolicy"                         ,NULL },
	{ 0x1500004C, "FveBandId"                        ,NULL },
	{ 0x16000050, "ConsoleExtendedInput"             ,NULL },
	{ 0x15000052, "GraphicsResolution"               ,NULL },
	{ 0x15000065, "BootUxDisplayMessage"             ,NULL },
	{ 0x15000066, "BootUxDisplayMessageOverride"     ,NULL },
	{ 0x15000075, "UndocumentedMagic"                ,NULL },
	{ 0x16000053, "RestartOnFailure"                 ,NULL },
	{ 0x16000054, "GraphicsForceHighestMode"         ,NULL },
	{ 0x16000060, "IsolatedExecutionContext"         ,NULL },
	{ 0x1600006C, "BootUxDisable"                    ,NULL },
	{ 0x16000074, "BootShutdownDisabled"             ,NULL },
	{ 0x17000077, "AllowedInMemorySettings"          ,NULL },
	{ 0x16000079, "ForceFipsCrypto"                  ,NULL },
	{ 0x1600007A, "MobileGraphics"                   ,NULL },
	{ 0x46000010, "RecoveryOs"                       ,NULL },
	{0,0,NULL}
};
struct bcd_guid_table BcdGuidTable[]={
	{ "BOOTMGR",              {0x9d,0xea,0x86,0x2c,0x5c,0xdd,0x4e,0x70,0xac,0xc1,0xf3,0x2b,0x34,0x4d,0x47,0x95} },
	{ "FWBOOTMGR",            {0xa5,0xa3,0x0f,0xa2,0x3d,0x06,0x4e,0x9f,0xb5,0xf4,0xa0,0x1d,0xf9,0xd1,0xfc,0xba} },
	{ "MEMDIAG",              {0xb2,0x72,0x1d,0x73,0x1d,0xb4,0x4c,0x62,0xbf,0x78,0xc5,0x48,0xa8,0x80,0x14,0x2d} },
	{ "RESUME",               {0x14,0x7a,0xa5,0x09,0x03,0x58,0x44,0x73,0xb8,0x3b,0xd9,0x50,0xdd,0xa0,0x06,0x15} },
	{ "NTLDR",                {0x46,0x6f,0x5a,0x88,0x0a,0xf2,0x4f,0x76,0x90,0x38,0x09,0x5b,0x17,0x0d,0xc2,0x1c} },
	{ "CURRENT",              {0xfa,0x92,0x64,0x93,0x6f,0x1c,0x41,0x93,0xa4,0x14,0x58,0xf0,0xb2,0x45,0x6d,0x1e} },
	{ "BADMEMORY",            {0x51,0x89,0xb2,0x5c,0x55,0x58,0x4b,0xf2,0xbc,0xa4,0x28,0x9b,0x11,0xbd,0x29,0xe2} },
	{ "BOOTLOADERSETTINGS",   {0x6e,0xfb,0x52,0xbf,0x17,0x66,0x41,0xdb,0xa6,0xb3,0x0e,0xe5,0xef,0xf7,0x2b,0xd7} },
	{ "DBGSETTINGS",          {0x46,0x36,0x85,0x6e,0x54,0x0f,0x41,0x70,0xa1,0x30,0xa8,0x47,0x76,0xf4,0xc6,0x54} },
	{ "EMSSETTINGS",          {0x0c,0xe4,0x99,0x1b,0xe6,0xb3,0x4b,0x16,0xb2,0x3c,0x5e,0x0d,0x92,0x50,0xe5,0xd9} },
	{ "GLOBALSETTINGS",       {0x7e,0xa2,0xe1,0xac,0x2e,0x61,0x47,0x28,0xaa,0xa3,0x89,0x6d,0x9d,0x0a,0x9f,0x0e} },
	{ "RESUMELOADERSETTINGS", {0x1a,0xfa,0x9c,0x49,0x16,0xab,0x4a,0x5c,0x90,0x1b,0x21,0x28,0x02,0xda,0x94,0x60} },
	{ "HYPERVISORSETTINGS",   {0x7f,0xf6,0x07,0xe0,0x43,0x95,0x11,0xdb,0xb0,0xde,0x08,0x00,0x20,0x0c,0x9a,0x66} },
	{NULL,{0}}

};
#endif
