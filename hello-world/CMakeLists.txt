cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(hello_world C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(hello_world main.c)

target_link_libraries(hello_world pico_stdlib)

pico_add_extra_outputs(hello_world)

pico_enable_stdio_uart(hello_world 0)

pico_enable_stdio_usb(hello_world 1)



