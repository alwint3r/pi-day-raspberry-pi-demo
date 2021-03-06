# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/winter/git/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(acc_gyro_i2c C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(acc_gyro_i2c acc_gyro_i2c.c )

pico_set_program_name(acc_gyro_i2c "acc_gyro_i2c")
pico_set_program_version(acc_gyro_i2c "0.1")

pico_enable_stdio_uart(acc_gyro_i2c 0)
pico_enable_stdio_usb(acc_gyro_i2c 1)

# Add the standard library to the build
target_link_libraries(acc_gyro_i2c pico_stdlib)

# Add any user requested libraries
target_link_libraries(acc_gyro_i2c
        hardware_i2c
        )

pico_add_extra_outputs(acc_gyro_i2c)

