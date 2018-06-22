deps_config := \
	/Users/flo/esp/esp-idf/components/app_trace/Kconfig \
	/Users/flo/esp/esp-idf/components/aws_iot/Kconfig \
	/Users/flo/esp/esp-idf/components/bt/Kconfig \
	/Users/flo/esp/esp-idf/components/driver/Kconfig \
	/Users/flo/esp/esp-idf/components/esp32/Kconfig \
	/Users/flo/esp/esp-idf/components/esp_adc_cal/Kconfig \
	/Users/flo/esp/esp-idf/components/esp_http_client/Kconfig \
	/Users/flo/esp/esp-idf/components/ethernet/Kconfig \
	/Users/flo/esp/esp-idf/components/fatfs/Kconfig \
	/Users/flo/esp/esp-idf/components/freertos/Kconfig \
	/Users/flo/esp/esp-idf/components/heap/Kconfig \
	/Users/flo/esp/esp-idf/components/libsodium/Kconfig \
	/Users/flo/esp/esp-idf/components/log/Kconfig \
	/Users/flo/esp/esp-idf/components/lwip/Kconfig \
	/Users/flo/esp/esp-idf/components/mbedtls/Kconfig \
	/Users/flo/esp/esp-idf/components/openssl/Kconfig \
	/Users/flo/esp/esp-idf/components/pthread/Kconfig \
	/Users/flo/esp/esp-idf/components/spi_flash/Kconfig \
	/Users/flo/esp/esp-idf/components/spiffs/Kconfig \
	/Users/flo/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/Users/flo/esp/esp-idf/components/wear_levelling/Kconfig \
	/Users/flo/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/Users/flo/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/Users/flo/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/Users/flo/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
