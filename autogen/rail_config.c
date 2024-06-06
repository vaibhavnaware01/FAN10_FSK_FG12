/***************************************************************************//**
 * @brief RAIL Configuration
 * @details
 *   WARNING: Auto-Generated Radio Config  -  DO NOT EDIT
 *   Radio Configurator Version: 2204.6.2
 *   RAIL Adapter Version: 2.4.22
 *   RAIL Compatibility: 2.x
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/
#include "em_device.h"
#include "rail_config.h"

__ALIGNED(4) uint8_t convDecodeBuffer[64];

uint32_t RAILCb_CalcSymbolRate(RAIL_Handle_t railHandle)
{
  (void) railHandle;
  return 0U;
}

uint32_t RAILCb_CalcBitRate(RAIL_Handle_t railHandle)
{
  (void) railHandle;
  return 0U;
}

void RAILCb_ConfigFrameTypeLength(RAIL_Handle_t railHandle,
                                  const RAIL_FrameType_t *frameType)
{
  (void) railHandle;
  (void) frameType;
}

static const uint8_t irCalConfig_0[] = {
  25, 71, 3, 6, 4, 16, 0, 1, 1, 3, 1, 6, 0, 16, 39, 0, 0, 5, 0, 1, 1, 0, 0, 0, 0, 0
};

static const uint8_t irCalConfig_1[] = {
  25, 69, 3, 6, 4, 16, 0, 1, 1, 3, 1, 6, 0, 16, 39, 0, 0, 5, 0, 1, 1, 0, 0, 0, 0, 0
};

static const uint8_t irCalConfig_2[] = {
  25, 69, 3, 6, 4, 16, 0, 1, 1, 3, 1, 6, 0, 16, 39, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0
};

static const int32_t timingConfig[] = {
  0, 0
};

static RAIL_ChannelConfigEntryAttr_t channelConfigEntryAttr_0 = {
#if RAIL_SUPPORTS_OFDM_PA
  {
    { 0xFFFFFFFFUL },
    { 0xFFFFFFFFUL, 0xFFFFFFFFUL }
  }
#else // RAIL_SUPPORTS_OFDM_PA
  { 0xFFFFFFFFUL },
#endif // RAIL_SUPPORTS_OFDM_PA
};

static RAIL_ChannelConfigEntryAttr_t channelConfigEntryAttr_1 = {
#if RAIL_SUPPORTS_OFDM_PA
  {
    { 0xFFFFFFFFUL },
    { 0xFFFFFFFFUL, 0xFFFFFFFFUL }
  }
#else // RAIL_SUPPORTS_OFDM_PA
  { 0xFFFFFFFFUL },
#endif // RAIL_SUPPORTS_OFDM_PA
};

static RAIL_ChannelConfigEntryAttr_t channelConfigEntryAttr_2 = {
#if RAIL_SUPPORTS_OFDM_PA
  {
    { 0xFFFFFFFFUL },
    { 0xFFFFFFFFUL, 0xFFFFFFFFUL }
  }
#else // RAIL_SUPPORTS_OFDM_PA
  { 0xFFFFFFFFUL },
#endif // RAIL_SUPPORTS_OFDM_PA
};

static const uint32_t phyInfo_0[] = {
  15UL,
  0x000FAC68UL, // 15.673469387755103
  (uint32_t) NULL,
  (uint32_t) irCalConfig_0,
  (uint32_t) timingConfig,
  0x00000000UL,
  7620928UL,
  39200000UL,
  50000UL,
  0x00000101UL,
  0x0600231CUL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  0UL,
  0UL,
  50000UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
};

static const uint32_t phyInfo_1[] = {
  15UL,
  0x0013B13BUL, // 19.692307692307693
  (uint32_t) NULL,
  (uint32_t) irCalConfig_1,
  (uint32_t) timingConfig,
  0x00000000UL,
  7498816UL,
  36400000UL,
  50000UL,
  0x00000101UL,
  0x0600231CUL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  0UL,
  0UL,
  49994UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
};

static const uint32_t phyInfo_2[] = {
  15UL,
  0x001A98EFUL, // 26.597402597402603
  (uint32_t) NULL,
  (uint32_t) irCalConfig_2,
  (uint32_t) timingConfig,
  0x00000000UL,
  8566932UL,
  34650000UL,
  150000UL,
  0x00000101UL,
  0x06002D99UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  0UL,
  0UL,
  149995UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
};

const uint32_t WiSunConf_Protocol_Configuration_1_modemConfigBase[] = {
  0x01041FDCUL, 0x00000000UL,
  /*    1FE0 */ 0x00000000UL,
  /*    1FE4 */ 0x00000000UL,
  /*    1FE8 */ 0x00000000UL,
  0x01041FF0UL, 0x003F003FUL,
  /*    1FF4 */ 0x00000000UL,
  /*    1FF8 */ (uint32_t) &phyInfo_0,
  /*    1FFC */ 0x00000000UL,
  0x00020004UL, 0x0011B10CUL,
  /*    0008 */ 0x00000800UL,
  0x00020018UL, 0x00000000UL,
  /*    001C */ 0x00000000UL,
  0x00070028UL, 0x00000825UL,
  /*    002C */ 0x00000100UL,
  /*    0030 */ 0x000000FFUL,
  /*    0034 */ 0x00010301UL,
  /*    0038 */ 0x00000000UL,
  /*    003C */ 0x00000000UL,
  /*    0040 */ 0x000007A0UL,
  0x00010048UL, 0x0000000BUL,
  0x00020054UL, 0x00000D0FUL,
  /*    0058 */ 0x00000101UL,
  0x000400A0UL, 0x00004001UL,
  /*    00A4 */ 0x00000CFFUL,
  /*    00A8 */ 0x00004101UL,
  /*    00AC */ 0x00000DFFUL,
  0x00012000UL, 0x0000170EUL,
  0x00012010UL, 0xFFFFFFFFUL,
  0x00012018UL, 0xEDB88320UL,
  0x00013008UL, 0x0100AC13UL,
  0x00023030UL, 0x0010231CUL,
  /*    3034 */ 0x00000003UL,
  0x00013040UL, 0x00000000UL,
  0x000140A0UL, 0x0F0027AAUL,
  0x000140B8UL, 0x0023C000UL,
  0x000140F4UL, 0x00001020UL,
  0x00024134UL, 0x00000880UL,
  /*    4138 */ 0x000087F6UL,
  0x00024140UL, 0x00880020UL,
  /*    4144 */ 0x4D52E6C1UL,
  0x00044160UL, 0x00000000UL,
  /*    4164 */ 0x00000000UL,
  /*    4168 */ 0x00000006UL,
  /*    416C */ 0x00000006UL,
  0x00086014UL, 0x00000010UL,
  /*    6018 */ 0x04000000UL,
  /*    601C */ 0x0006400FUL,
  /*    6020 */ 0x00005000UL,
  /*    6024 */ 0x00000000UL,
  /*    6028 */ 0x03000000UL,
  /*    602C */ 0x00000000UL,
  /*    6030 */ 0x00000000UL,
  0x00066050UL, 0x00FF5FA0UL,
  /*    6054 */ 0x00000C41UL,
  /*    6058 */ 0x00020034UL,
  /*    605C */ 0x00200012UL,
  /*    6060 */ 0x00007209UL,
  /*    6064 */ 0x00000000UL,
  0x000C6078UL, 0x08E0281FUL,
  /*    607C */ 0x00000000UL,
  /*    6080 */ 0x003B0390UL,
  /*    6084 */ 0x00000000UL,
  /*    6088 */ 0x00000000UL,
  /*    608C */ 0x0A000000UL,
  /*    6090 */ 0x5454544AUL,
  /*    6094 */ 0x00000000UL,
  /*    6098 */ 0x00000000UL,
  /*    609C */ 0x00000000UL,
  /*    60A0 */ 0x00000000UL,
  /*    60A4 */ 0x00000000UL,
  0x000760E4UL, 0xCBF3087FUL,
  /*    60E8 */ 0x00000000UL,
  /*    60EC */ 0x07830464UL,
  /*    60F0 */ 0x3AC81388UL,
  /*    60F4 */ 0x0006209CUL,
  /*    60F8 */ 0x00206100UL,
  /*    60FC */ 0x208556B7UL,
  0x00036104UL, 0x0010BB3FUL,
  /*    6108 */ 0x00003020UL,
  /*    610C */ 0x0000BB88UL,
  0x00016120UL, 0x00000000UL,
  0x10017014UL, 0x0007F800UL,
  0x30017014UL, 0x000000FEUL,
  0x00067018UL, 0x00001300UL,
  /*    701C */ 0x870A0060UL,
  /*    7020 */ 0x00000000UL,
  /*    7024 */ 0x00000082UL,
  /*    7028 */ 0x00000000UL,
  /*    702C */ 0x000000D5UL,
  0x00027048UL, 0x0000383EUL,
  /*    704C */ 0x000025BCUL,
  0x00037070UL, 0x00120105UL,
  /*    7074 */ 0x00083031UL,
  /*    7078 */ 0x006D8480UL,
  0xFFFFFFFFUL,
};

const uint32_t WiSunConf_Protocol_Configuration_2_modemConfigBase[] = {
  0x01041FDCUL, 0x00000000UL,
  /*    1FE0 */ 0x00000000UL,
  /*    1FE4 */ 0x00000000UL,
  /*    1FE8 */ 0x00000000UL,
  0x01041FF0UL, 0x003F003FUL,
  /*    1FF4 */ 0x00000000UL,
  /*    1FF8 */ (uint32_t) &phyInfo_1,
  /*    1FFC */ 0x00000000UL,
  0x00020004UL, 0x0011B10CUL,
  /*    0008 */ 0x00000800UL,
  0x00020018UL, 0x00000000UL,
  /*    001C */ 0x00000000UL,
  0x00070028UL, 0x00000825UL,
  /*    002C */ 0x00000100UL,
  /*    0030 */ 0x000000FFUL,
  /*    0034 */ 0x00010301UL,
  /*    0038 */ 0x00000000UL,
  /*    003C */ 0x00000000UL,
  /*    0040 */ 0x000007A0UL,
  0x00010048UL, 0x0000000BUL,
  0x00020054UL, 0x00000D0FUL,
  /*    0058 */ 0x00000101UL,
  0x000400A0UL, 0x00004001UL,
  /*    00A4 */ 0x00000CFFUL,
  /*    00A8 */ 0x00004101UL,
  /*    00AC */ 0x00000DFFUL,
  0x00012000UL, 0x0000170EUL,
  0x00012010UL, 0xFFFFFFFFUL,
  0x00012018UL, 0xEDB88320UL,
  0x00013008UL, 0x0100AC13UL,
  0x00023030UL, 0x0010231CUL,
  /*    3034 */ 0x00000003UL,
  0x00013040UL, 0x00000000UL,
  0x000140A0UL, 0x0F0027AAUL,
  0x000140B8UL, 0x0023C000UL,
  0x000140F4UL, 0x00001020UL,
  0x00024134UL, 0x00000880UL,
  /*    4138 */ 0x000087F6UL,
  0x00024140UL, 0x00880020UL,
  /*    4144 */ 0x4D52E6C1UL,
  0x00044160UL, 0x00000000UL,
  /*    4164 */ 0x00000000UL,
  /*    4168 */ 0x00000006UL,
  /*    416C */ 0x00000006UL,
  0x00086014UL, 0x00000010UL,
  /*    6018 */ 0x04000000UL,
  /*    601C */ 0x0001400FUL,
  /*    6020 */ 0x00005000UL,
  /*    6024 */ 0x00000000UL,
  /*    6028 */ 0x03000000UL,
  /*    602C */ 0x00000000UL,
  /*    6030 */ 0x00000000UL,
  0x00066050UL, 0x00FF5FA0UL,
  /*    6054 */ 0x00000C41UL,
  /*    6058 */ 0x00020062UL,
  /*    605C */ 0x00200012UL,
  /*    6060 */ 0x00007209UL,
  /*    6064 */ 0x00000000UL,
  0x000C6078UL, 0x08E01810UL,
  /*    607C */ 0x00000000UL,
  /*    6080 */ 0x001A0370UL,
  /*    6084 */ 0x00000000UL,
  /*    6088 */ 0x00000000UL,
  /*    608C */ 0x0A000000UL,
  /*    6090 */ 0x5454544AUL,
  /*    6094 */ 0x00000000UL,
  /*    6098 */ 0x00000000UL,
  /*    609C */ 0x00000000UL,
  /*    60A0 */ 0x00000000UL,
  /*    60A4 */ 0x00000000UL,
  0x000760E4UL, 0xCC300881UL,
  /*    60E8 */ 0x00000000UL,
  /*    60EC */ 0x07830464UL,
  /*    60F0 */ 0x3AC81388UL,
  /*    60F4 */ 0x0006209CUL,
  /*    60F8 */ 0x00206100UL,
  /*    60FC */ 0x208556B7UL,
  0x00036104UL, 0x00105D9FUL,
  /*    6108 */ 0x00003020UL,
  /*    610C */ 0x0000BB88UL,
  0x00016120UL, 0x00000000UL,
  0x10017014UL, 0x0007F800UL,
  0x30017014UL, 0x000000FEUL,
  0x00067018UL, 0x00001300UL,
  /*    701C */ 0x870A0060UL,
  /*    7020 */ 0x00000000UL,
  /*    7024 */ 0x00000082UL,
  /*    7028 */ 0x00000000UL,
  /*    702C */ 0x000000D5UL,
  0x00027048UL, 0x0000383EUL,
  /*    704C */ 0x000025BCUL,
  0x00037070UL, 0x00120105UL,
  /*    7074 */ 0x0008302EUL,
  /*    7078 */ 0x006D8480UL,
  0xFFFFFFFFUL,
};

const uint32_t WiSunConf_Protocol_Configuration_3_modemConfigBase[] = {
  0x01041FDCUL, 0x00000000UL,
  /*    1FE0 */ 0x00000000UL,
  /*    1FE4 */ 0x00000000UL,
  /*    1FE8 */ 0x00000000UL,
  0x01041FF0UL, 0x003F003FUL,
  /*    1FF4 */ 0x00000000UL,
  /*    1FF8 */ (uint32_t) &phyInfo_2,
  /*    1FFC */ 0x00000000UL,
  0x00020004UL, 0x0011B10CUL,
  /*    0008 */ 0x00000800UL,
  0x00020018UL, 0x00000000UL,
  /*    001C */ 0x00000000UL,
  0x00070028UL, 0x00000825UL,
  /*    002C */ 0x00000100UL,
  /*    0030 */ 0x000000FFUL,
  /*    0034 */ 0x00010301UL,
  /*    0038 */ 0x00000000UL,
  /*    003C */ 0x00000000UL,
  /*    0040 */ 0x000007A0UL,
  0x00010048UL, 0x0000000BUL,
  0x00020054UL, 0x00000D0FUL,
  /*    0058 */ 0x00000101UL,
  0x000400A0UL, 0x00004001UL,
  /*    00A4 */ 0x00000CFFUL,
  /*    00A8 */ 0x00004101UL,
  /*    00AC */ 0x00000DFFUL,
  0x00012000UL, 0x0000170EUL,
  0x00012010UL, 0xFFFFFFFFUL,
  0x00012018UL, 0xEDB88320UL,
  0x00013008UL, 0x0100AC13UL,
  0x00023030UL, 0x00102D99UL,
  /*    3034 */ 0x00000003UL,
  0x00013040UL, 0x00000000UL,
  0x000140A0UL, 0x0F0027AAUL,
  0x000140B8UL, 0x0033C000UL,
  0x000140F4UL, 0x00001020UL,
  0x00024134UL, 0x00000880UL,
  /*    4138 */ 0x000087F6UL,
  0x00024140UL, 0x00880040UL,
  /*    4144 */ 0x4D52E6C1UL,
  0x00044160UL, 0x00000000UL,
  /*    4164 */ 0x00000000UL,
  /*    4168 */ 0x00000006UL,
  /*    416C */ 0x00000006UL,
  0x00086014UL, 0x00000010UL,
  /*    6018 */ 0x04000000UL,
  /*    601C */ 0x0006400FUL,
  /*    6020 */ 0x00005000UL,
  /*    6024 */ 0x00000000UL,
  /*    6028 */ 0x03000000UL,
  /*    602C */ 0x00000000UL,
  /*    6030 */ 0x00000000UL,
  0x00066050UL, 0x00FF1FE0UL,
  /*    6054 */ 0x00000C41UL,
  /*    6058 */ 0x00000050UL,
  /*    605C */ 0x00300012UL,
  /*    6060 */ 0x00007209UL,
  /*    6064 */ 0x00000000UL,
  0x000C6078UL, 0x08E0381FUL,
  /*    607C */ 0x00000000UL,
  /*    6080 */ 0x003A0392UL,
  /*    6084 */ 0x00000000UL,
  /*    6088 */ 0x00000000UL,
  /*    608C */ 0x0A000000UL,
  /*    6090 */ 0x5454544AUL,
  /*    6094 */ 0x00000000UL,
  /*    6098 */ 0x00000000UL,
  /*    609C */ 0x00000000UL,
  /*    60A0 */ 0x00000000UL,
  /*    60A4 */ 0x00000000UL,
  0x000760E4UL, 0x8BC20897UL,
  /*    60E8 */ 0x00000000UL,
  /*    60EC */ 0x07830464UL,
  /*    60F0 */ 0x3AC81388UL,
  /*    60F4 */ 0x0006209CUL,
  /*    60F8 */ 0x00206100UL,
  /*    60FC */ 0x208556B7UL,
  0x00036104UL, 0x00105B31UL,
  /*    6108 */ 0x00003020UL,
  /*    610C */ 0x0000BB88UL,
  0x00016120UL, 0x00000000UL,
  0x10017014UL, 0x0007F800UL,
  0x30017014UL, 0x000000FEUL,
  0x00067018UL, 0x00001300UL,
  /*    701C */ 0x848A0060UL,
  /*    7020 */ 0x00000000UL,
  /*    7024 */ 0x00000082UL,
  /*    7028 */ 0x00000000UL,
  /*    702C */ 0x000000D5UL,
  0x00027048UL, 0x0000383EUL,
  /*    704C */ 0x000025BCUL,
  0x00037070UL, 0x00120105UL,
  /*    7074 */ 0x00083026UL,
  /*    7078 */ 0x006D8480UL,
  0xFFFFFFFFUL,
};

const RAIL_ChannelConfigEntry_t WiSunConf_Protocol_Configuration_1_channels[] = {
  {
    .phyConfigDeltaAdd = NULL,
    .baseFrequency = 902200000,
    .channelSpacing = 200000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 0,
    .channelNumberEnd = 128,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr_0,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_0,
#endif
  },
};

const RAIL_ChannelConfigEntry_t WiSunConf_Protocol_Configuration_2_channels[] = {
  {
    .phyConfigDeltaAdd = NULL,
    .baseFrequency = 865100000,
    .channelSpacing = 100000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 0,
    .channelNumberEnd = 18,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr_1,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_1,
#endif
  },
};

const RAIL_ChannelConfigEntry_t WiSunConf_Protocol_Configuration_3_channels[] = {
  {
    .phyConfigDeltaAdd = NULL,
    .baseFrequency = 865100000,
    .channelSpacing = 200000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 0,
    .channelNumberEnd = 9,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr_2,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_2,
#endif
  },
};

const RAIL_ChannelConfig_t WiSunConf_Protocol_Configuration_1_channelConfig = {
  .phyConfigBase = WiSunConf_Protocol_Configuration_1_modemConfigBase,
  .phyConfigDeltaSubtract = NULL,
  .configs = WiSunConf_Protocol_Configuration_1_channels,
  .length = 1U,
  .signature = 0UL,
};

const RAIL_ChannelConfig_t WiSunConf_Protocol_Configuration_2_channelConfig = {
  .phyConfigBase = WiSunConf_Protocol_Configuration_2_modemConfigBase,
  .phyConfigDeltaSubtract = NULL,
  .configs = WiSunConf_Protocol_Configuration_2_channels,
  .length = 1U,
  .signature = 0UL,
};

const RAIL_ChannelConfig_t WiSunConf_Protocol_Configuration_3_channelConfig = {
  .phyConfigBase = WiSunConf_Protocol_Configuration_3_modemConfigBase,
  .phyConfigDeltaSubtract = NULL,
  .configs = WiSunConf_Protocol_Configuration_3_channels,
  .length = 1U,
  .signature = 0UL,
};

const RAIL_ChannelConfig_t *channelConfigs[] = {
  &WiSunConf_Protocol_Configuration_1_channelConfig,
  &WiSunConf_Protocol_Configuration_2_channelConfig,
  &WiSunConf_Protocol_Configuration_3_channelConfig,
  NULL
};

#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
const uint8_t stackInfo_0[5] = {0x07, 0x02, 0x01, 0x01, 0x01};
const uint8_t stackInfo_1[5] = {0x07, 0x01, 0x00, 0x01, 0x05};
const uint8_t stackInfo_2[5] = {0x07, 0x05, 0x00, 0x02, 0x05};
#endif // RADIO_CONFIG_ENABLE_STACK_INFO

uint32_t wisunconfAccelerationBuffer[189];
