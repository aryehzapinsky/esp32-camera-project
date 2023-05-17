FILE(GLOB_RECURSE lib_sources ${CMAKE_SOURCE_DIR}/lib/*.*)

idf_component_register(SRCS ${lib_sources})

target_include_directories(${COMPONENT_TARGET} PRIVATE /Users/aryehzapinsky/Devel/esp32_wokwi/esp_git_tools/esp-idf/components/freertos/FreeRTOS-Kernel-SMP/include/freertos)
