cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME distance_with_led)
project(${PROJECT_NAME})

set(${CMAKE_PROJECT_NAME}_SKETCH distance_with_led.ino)

set(${CMAKE_PROJECT_NAME}_BOARD uno)
set(${CMAKE_PROJECT_NAME}_PORT com5)


generate_arduino_firmware(${CMAKE_PROJECT_NAME})
