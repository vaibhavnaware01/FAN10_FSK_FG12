################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.2.2/util/third_party/segger/systemview/SEGGER/subdir.mk
-include gecko_sdk_4.2.2/util/third_party/printf/src/subdir.mk
-include gecko_sdk_4.2.2/util/third_party/printf/subdir.mk
-include gecko_sdk_4.2.2/util/third_party/mbedtls/library/subdir.mk
-include gecko_sdk_4.2.2/util/silicon_labs/silabs_core/memory_manager/subdir.mk
-include gecko_sdk_4.2.2/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.2.2/platform/service/system/src/subdir.mk
-include gecko_sdk_4.2.2/platform/service/sleeptimer/src/subdir.mk
-include gecko_sdk_4.2.2/platform/service/iostream/src/subdir.mk
-include gecko_sdk_4.2.2/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/subdir.mk
-include gecko_sdk_4.2.2/platform/security/sl_component/sl_mbedtls_support/src/subdir.mk
-include gecko_sdk_4.2.2/platform/radio/rail_lib/plugin/rail_util_pti/subdir.mk
-include gecko_sdk_4.2.2/platform/radio/rail_lib/plugin/pa-conversions/subdir.mk
-include gecko_sdk_4.2.2/platform/micrium_os/ports/source/gnu/subdir.mk
-include gecko_sdk_4.2.2/platform/micrium_os/ports/source/generic/subdir.mk
-include gecko_sdk_4.2.2/platform/micrium_os/kernel/source/subdir.mk
-include gecko_sdk_4.2.2/platform/micrium_os/cpu/source/subdir.mk
-include gecko_sdk_4.2.2/platform/micrium_os/common/source/rtos/subdir.mk
-include gecko_sdk_4.2.2/platform/micrium_os/common/source/ring_buf/subdir.mk
-include gecko_sdk_4.2.2/platform/micrium_os/common/source/logging/subdir.mk
-include gecko_sdk_4.2.2/platform/micrium_os/common/source/lib/subdir.mk
-include gecko_sdk_4.2.2/platform/micrium_os/common/source/kal/subdir.mk
-include gecko_sdk_4.2.2/platform/emlib/src/subdir.mk
-include gecko_sdk_4.2.2/platform/emdrv/nvm3/src/subdir.mk
-include gecko_sdk_4.2.2/platform/emdrv/dmadrv/src/subdir.mk
-include gecko_sdk_4.2.2/platform/driver/leddrv/src/subdir.mk
-include gecko_sdk_4.2.2/platform/driver/debug/src/subdir.mk
-include gecko_sdk_4.2.2/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.2.2/platform/common/src/subdir.mk
-include gecko_sdk_4.2.2/platform/Device/SiliconLabs/EFR32MG12P/Source/subdir.mk
-include gecko_sdk_4.2.2/platform/CMSIS/RTOS2/Source/subdir.mk
-include gecko_sdk_4.2.2/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/subdir.mk
-include gecko_sdk_4.2.2/hardware/driver/configuration_over_swo/src/subdir.mk
-include gecko_sdk_4.2.2/hardware/board/src/subdir.mk
-include gecko_sdk_4.2.2/app/wisun/component/trace_util/nanostack/nanostack-libservice/source/libip6string/subdir.mk
-include gecko_sdk_4.2.2/app/wisun/component/trace_util/nanostack/nanostack-libservice/source/libBits/subdir.mk
-include gecko_sdk_4.2.2/app/wisun/component/trace_util/subdir.mk
-include gecko_sdk_4.2.2/app/wisun/component/ns_list/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := FAN1.0_FSK_FINAL
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: FAN1.0_FSK_FINAL.axf

# Tool invocations
FAN1.0_FSK_FINAL.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "C:\Users\smart\SimplicityStudio\v5_workspace\FAN1.0_FSK_FINAL\autogen\linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="FAN1.0_FSK_FINAL.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o FAN1.0_FSK_FINAL.axf -Wl,--start-group "./app.o" "./app_address_utils.o" "./app_init.o" "./app_timestamp_and_traces.o" "./main.o" "./autogen/rail_config.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_iostream_handles.o" "./autogen/sl_iostream_init_usart_instances.o" "./autogen/sl_simple_led_instances.o" "./gecko_sdk_4.2.2/app/wisun/component/ns_list/ns_list.o" "./gecko_sdk_4.2.2/app/wisun/component/trace_util/nanostack/nanostack-libservice/source/libBits/common_functions.o" "./gecko_sdk_4.2.2/app/wisun/component/trace_util/nanostack/nanostack-libservice/source/libBits/common_inlined_functions.o" "./gecko_sdk_4.2.2/app/wisun/component/trace_util/nanostack/nanostack-libservice/source/libip6string/ip6tos.o" "./gecko_sdk_4.2.2/app/wisun/component/trace_util/nanostack/nanostack-libservice/source/libip6string/stoip6.o" "./gecko_sdk_4.2.2/app/wisun/component/trace_util/sl_wisun_trace_util.o" "./gecko_sdk_4.2.2/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.2.2/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.2.2/hardware/driver/configuration_over_swo/src/sl_cos.o" "./gecko_sdk_4.2.2/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o" "./gecko_sdk_4.2.2/platform/CMSIS/RTOS2/Source/os_systick.o" "./gecko_sdk_4.2.2/platform/Device/SiliconLabs/EFR32MG12P/Source/startup_efr32mg12p.o" "./gecko_sdk_4.2.2/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.o" "./gecko_sdk_4.2.2/platform/common/src/sl_assert.o" "./gecko_sdk_4.2.2/platform/common/src/sl_slist.o" "./gecko_sdk_4.2.2/platform/common/src/sl_string.o" "./gecko_sdk_4.2.2/platform/common/src/sli_cmsis_os2_ext_task_register.o" "./gecko_sdk_4.2.2/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.2.2/platform/driver/debug/src/sl_debug_swo.o" "./gecko_sdk_4.2.2/platform/driver/leddrv/src/sl_led.o" "./gecko_sdk_4.2.2/platform/driver/leddrv/src/sl_simple_led.o" "./gecko_sdk_4.2.2/platform/emdrv/dmadrv/src/dmadrv.o" "./gecko_sdk_4.2.2/platform/emdrv/nvm3/src/nvm3_default_common_linker.o" "./gecko_sdk_4.2.2/platform/emdrv/nvm3/src/nvm3_hal_flash.o" "./gecko_sdk_4.2.2/platform/emdrv/nvm3/src/nvm3_lock.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_core.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_crypto.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_emu.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_ldma.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_msc.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_prs.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_rtcc.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_system.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_timer.o" "./gecko_sdk_4.2.2/platform/emlib/src/em_usart.o" "./gecko_sdk_4.2.2/platform/micrium_os/common/source/kal/kal_kernel.o" "./gecko_sdk_4.2.2/platform/micrium_os/common/source/lib/lib_ascii.o" "./gecko_sdk_4.2.2/platform/micrium_os/common/source/lib/lib_mem.o" "./gecko_sdk_4.2.2/platform/micrium_os/common/source/lib/lib_str.o" "./gecko_sdk_4.2.2/platform/micrium_os/common/source/logging/logging.o" "./gecko_sdk_4.2.2/platform/micrium_os/common/source/ring_buf/ring_buf.o" "./gecko_sdk_4.2.2/platform/micrium_os/common/source/rtos/rtos_err_str.o" "./gecko_sdk_4.2.2/platform/micrium_os/common/source/rtos/rtos_utils.o" "./gecko_sdk_4.2.2/platform/micrium_os/cpu/source/cpu_core.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/cmsis_os2.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_cfg_app.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_core.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_dbg.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_flag.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_mon.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_msg.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_mutex.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_prio.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_q.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_sem.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_stat.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_task.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_time.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_tmr.o" "./gecko_sdk_4.2.2/platform/micrium_os/kernel/source/os_var.o" "./gecko_sdk_4.2.2/platform/micrium_os/ports/source/generic/arm_cpu_dwt_ts.o" "./gecko_sdk_4.2.2/platform/micrium_os/ports/source/gnu/armv7m_cpu_a.o" "./gecko_sdk_4.2.2/platform/micrium_os/ports/source/gnu/armv7m_os_cpu_a.o" "./gecko_sdk_4.2.2/platform/micrium_os/ports/source/gnu/armv7m_os_cpu_c.o" "./gecko_sdk_4.2.2/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.o" "./gecko_sdk_4.2.2/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.o" "./gecko_sdk_4.2.2/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_mbedtls_support/src/crypto_aes.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_mbedtls_support/src/crypto_ecp.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_mbedtls_support/src/mbedtls_ccm.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_mbedtls_support/src/mbedtls_sha.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_mbedtls_support/src/sl_entropy_hardware.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_mbedtls_support/src/sl_mbedtls.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_mbedtls_support/src/sli_psa_crypto.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/crypto_management.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/sl_psa_its_nvm3.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_aead.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_cipher.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_hash.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_mac.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/sli_crypto_trng_driver.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/sli_psa_driver_common.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/sli_psa_driver_init.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/sli_psa_trng.o" "./gecko_sdk_4.2.2/platform/security/sl_component/sl_psa_driver/src/sli_se_version_dependencies.o" "./gecko_sdk_4.2.2/platform/service/device_init/src/sl_device_init_dcdc_s1.o" "./gecko_sdk_4.2.2/platform/service/device_init/src/sl_device_init_emu_s1.o" "./gecko_sdk_4.2.2/platform/service/device_init/src/sl_device_init_hfxo_s1.o" "./gecko_sdk_4.2.2/platform/service/device_init/src/sl_device_init_lfxo_s1.o" "./gecko_sdk_4.2.2/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.2.2/platform/service/iostream/src/sl_iostream.o" "./gecko_sdk_4.2.2/platform/service/iostream/src/sl_iostream_retarget_stdio.o" "./gecko_sdk_4.2.2/platform/service/iostream/src/sl_iostream_uart.o" "./gecko_sdk_4.2.2/platform/service/iostream/src/sl_iostream_usart.o" "./gecko_sdk_4.2.2/platform/service/sleeptimer/src/sl_sleeptimer.o" "./gecko_sdk_4.2.2/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtcc.o" "./gecko_sdk_4.2.2/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.o" "./gecko_sdk_4.2.2/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.2.2/platform/service/system/src/sl_system_kernel.o" "./gecko_sdk_4.2.2/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.2.2/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" "./gecko_sdk_4.2.2/util/silicon_labs/silabs_core/memory_manager/sl_malloc.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/aes.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/asn1parse.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/asn1write.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/base64.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/bignum.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ccm.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/cipher.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/cipher_wrap.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/constant_time.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ctr_drbg.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ecdh.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ecdsa.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ecp.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ecp_curves.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/entropy.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/entropy_poll.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/hmac_drbg.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/md.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/nist_kw.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/oid.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/pem.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/pk.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/pk_wrap.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/pkparse.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/pkwrite.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/platform.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/platform_util.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_aead.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_cipher.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_client.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_driver_wrappers.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_ecp.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_hash.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_mac.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_rsa.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_se.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_slot_management.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/psa_crypto_storage.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/sha1.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/sha256.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ssl_cache.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ssl_ciphersuites.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ssl_client.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ssl_cookie.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ssl_debug_helpers_generated.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ssl_msg.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ssl_ticket.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ssl_tls.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ssl_tls12_client.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/ssl_tls12_server.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/threading.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/x509.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/x509_create.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/x509_crl.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/x509_crt.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/x509_csr.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/x509write_crt.o" "./gecko_sdk_4.2.2/util/third_party/mbedtls/library/x509write_csr.o" "./gecko_sdk_4.2.2/util/third_party/printf/printf.o" "./gecko_sdk_4.2.2/util/third_party/printf/src/iostream_printf.o" "./gecko_sdk_4.2.2/util/third_party/segger/systemview/SEGGER/SEGGER_RTT.o" "C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/lib/libnvm3_CM4_gcc.a" "C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/autogen/librail_release/librail_efr32xg12_gcc_release.a" "C:/Users/smart/SimplicityStudio/SDKs/gecko_sdk//protocol/wisun/stack/libwisun_router_core_efr32xg1x_micriumos_gcc_debug.a" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: FAN1.0_FSK_FINAL.hex'
	arm-none-eabi-objcopy -O ihex "FAN1.0_FSK_FINAL.axf" "FAN1.0_FSK_FINAL.hex"
	@echo ' '

	@echo 'Building bin file: FAN1.0_FSK_FINAL.bin'
	arm-none-eabi-objcopy -O binary "FAN1.0_FSK_FINAL.axf" "FAN1.0_FSK_FINAL.bin"
	@echo ' '

	@echo 'Building s37 file: FAN1.0_FSK_FINAL.s37'
	arm-none-eabi-objcopy -O srec "FAN1.0_FSK_FINAL.axf" "FAN1.0_FSK_FINAL.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "FAN1.0_FSK_FINAL.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) FAN1.0_FSK_FINAL.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
