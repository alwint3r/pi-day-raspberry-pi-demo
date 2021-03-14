# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/winter/git/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(temperature_display C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(temperature_display temperature_display.c )

pico_set_program_name(temperature_display "temperature_display")
pico_set_program_version(temperature_display "0.1")

pico_enable_stdio_uart(temperature_display 0)
pico_enable_stdio_usb(temperature_display 1)

# Add the standard library to the build
target_link_libraries(temperature_display pico_stdlib)

# Add any user requested libraries
target_link_libraries(temperature_display
        hardware_i2c
        hardware_adc
        )

pico_add_extra_outputs(temperature_display)

