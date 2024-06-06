################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk/hardware/driver/configuration_over_swo/src/sl_cos.c 

OBJS += \
./gecko_sdk_4.2.2/hardware/driver/configuration_over_swo/src/sl_cos.o 

C_DEPS += \
./gecko_sdk_4.2.2/hardware/driver/configuration_over_swo/src/sl_cos.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.2.2/hardware/driver/configuration_over_swo/src/sl_cos.o: C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk/hardware/driver/configuration_over_swo/src/sl_cos.c gecko_sdk_4.2.2/hardware/driver/configuration_over_swo/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM68=1' '-DSL_BOARD_NAME="BRD4170A"' '-DSL_BOARD_REV="A01"' '-DconfigNUM_SDK_THREAD_LOCAL_STORAGE_POINTERS=2' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<sl_mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' -I"C:\Users\smart\SimplicityStudio\v5_workspace\FAN1.0_FSK_FINAL\config" -I"C:\Users\smart\SimplicityStudio\v5_workspace\FAN1.0_FSK_FINAL\config\rail" -I"C:\Users\smart\SimplicityStudio\v5_workspace\FAN1.0_FSK_FINAL\config\wisun" -I"C:\Users\smart\SimplicityStudio\v5_workspace\FAN1.0_FSK_FINAL" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/RTOS2/Include" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/driver/leddrv/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_mbedtls_support/config" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_mbedtls_support/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//util/third_party/mbedtls/include" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//util/third_party/mbedtls/library" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/micrium_os/common/source" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/micrium_os/common/include" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/micrium_os/cpu/include" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/micrium_os/ports/source" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/micrium_os" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/micrium_os/kernel/source" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/micrium_os/kernel/include" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_psa_driver/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_psa_driver/inc/public" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg1x" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg1x" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//app/wisun/component/ns_list" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//app/wisun/component/trace_util" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//app/wisun/component/trace_util/nanostack/nanostack-libservice/mbed-client-libservice" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//protocol/wisun/stack/inc" -I"C:\Users\smart\SimplicityStudio\v5_workspace\FAN1.0_FSK_FINAL\autogen" -Og -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.2.2/hardware/driver/configuration_over_swo/src/sl_cos.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


