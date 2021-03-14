# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/winter/git/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(temperature_sensor C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(temperature_sensor
    temperature_sensor.cpp
    AnalogIn.cpp
    InternalTemperatureSensor.cpp
)

pico_set_program_name(temperature_sensor "temperature_sensor")
pico_set_program_version(temperature_sensor "0.1")

pico_enable_stdio_uart(temperature_sensor 1)
pico_enable_stdio_usb(temperature_sensor 0)

# Add the standard library to the build
target_link_libraries(temperature_sensor pico_stdlib)

target_link_libraries(temperature_sensor hardware_adc)

pico_add_extra_outputs(temperature_sensor)

