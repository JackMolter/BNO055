cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(BNO055)
pico_sdk_init()

add_executable(bno 
    bno.c
)

target_link_libraries(bno
    pico_stdlib
    hardware_i2c
)
pico_enable_stdio_usb(bno 1)
pico_add_extra_outputs(bno)
