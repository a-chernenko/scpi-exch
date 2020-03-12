cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME scpiexch)
set(PROJECT_LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(COMPILE_FLAGS -Wall -Wextra -Werror)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")
endif()

project(${PROJECT_NAME} ${PROJECT_LANGUAGES})

include_directories( 
	"socket_api/include/"
    "include/"
	"include/scpi/"
	"include/hardware/"
	"include/ieee4882/"
)

set(SOURCES
	src/hardware/hardware.cpp
	src/hardware/hardware_exception.cpp
	src/ieee4882/ieee4882.cpp
	src/ieee4882/ieee4882_mnemonics.cpp
	src/scpi/scpi_mnemonics.cpp
	src/scpi/scpi.cpp
	src/scpi/scpi_base.cpp
	src/scpi/scpi_current_subsystem.cpp
	src/scpi/scpi_exception.cpp
	src/scpi/scpi_frequency_subsystem.cpp
	src/scpi/scpi_input_subsystem.cpp
	src/scpi/scpi_measure_subsystem.cpp
	src/scpi/scpi_output_subsystem.cpp
	src/scpi/scpi_power_subsystem.cpp
	src/scpi/scpi_sense_bandwidth_subsystem.cpp
	src/scpi/scpi_sense_frequency_subsystem.cpp
	src/scpi/scpi_sense_subsystem.cpp
	src/scpi/scpi_sense_sweep_subsystem.cpp
	src/scpi/scpi_source_current_subsystem.cpp
	src/scpi/scpi_source_frequency_subsystem.cpp
	src/scpi/scpi_source_marker_subsystem.cpp
	src/scpi/scpi_source_power_subsystem.cpp
	src/scpi/scpi_source_subsystem.cpp
	src/scpi/scpi_source_voltage_subsystem.cpp
	src/scpi/scpi_sweep_subsystem.cpp
	src/scpi/scpi_system_subsystem.cpp
	src/scpi/scpi_trigger_subsystem.cpp
	src/scpi/scpi_unit_subsystem.cpp
	src/scpi/scpi_units_type.cpp
	src/scpi/scpi_voltage_subsystem.cpp
    src/scpi/scpi_status_subsystem.cpp
	src/scpi/scpi_display_subsystem.cpp
)
set(HEADERS
	include/const_string.h
	include/const_string.hpp
	include/hardware/hardware.h
	include/hardware/hardware_exception.h
	include/ieee4882/ieee4882.h
	include/ieee4882/ieee4882_constants.h
	include/ieee4882/ieee4882_mnemonics.h
	include/ieee4882/ieee4882_registers_type.h
	include/scpi/scpi.h
	include/scpi/scpi_base.h
	include/scpi/scpi_base.hpp
	include/scpi/scpi_channel_type.h
	include/scpi/scpi_constants.h
	include/scpi/scpi_current_subsystem.h
	include/scpi/scpi_display_subsystem.h
	include/scpi/scpi_exception.h
	include/scpi/scpi_frequency_subsystem.h
	include/scpi/scpi_input_subsystem.h
	include/scpi/scpi_source_level_commands.h
	include/scpi/scpi_source_level_commands.hpp
	include/scpi/scpi_measure_subsystem.h
	include/scpi/scpi_mnemonics.h
	include/scpi/scpi_output_subsystem.h
	include/scpi/scpi_power_subsystem.h
	include/scpi/scpi_source_protection_commands.h
	include/scpi/scpi_source_protection_commands.hpp
	include/scpi/scpi_registers_type.h
	include/scpi/scpi_sense_bandwidth_subsystem.h
	include/scpi/scpi_sense_frequency_subsystem.h
	include/scpi/scpi_sense_subsystem.h
	include/scpi/scpi_sense_sweep_subsystem.h
	include/scpi/scpi_source_current_subsystem.h
	include/scpi/scpi_source_frequency_subsystem.h
	include/scpi/scpi_source_marker_subsystem.h
	include/scpi/scpi_source_power_subsystem.h
	include/scpi/scpi_source_subsystem.h
	include/scpi/scpi_source_voltage_subsystem.h
	include/scpi/scpi_status_subsystem.h
	include/scpi/scpi_status_subsystem.hpp
	include/scpi/scpi_sweep_subsystem.h
	include/scpi/scpi_system_subsystem.h
	include/scpi/scpi_unit_subsystem.h
	include/scpi/scpi_voltage_subsystem.h
	include/scpi/scpi_trigger_subsystem.h
	include/scpi/scpi_units_type.h
	include/scpi/scpi_frequency_mnemonics.h
	include/scpi/scpi_display_mnemonics.h
	include/scpi/scpi_measure_mnemonics.h
	include/scpi/scpi_sweep_mnemonics.h
	include/scpi/scpi_output_mnemonics.h
	include/scpi/scpi_unit_mnemonics.h
	include/scpi/scpi_input_mnemonics.h
	include/scpi/scpi_status_mnemonics.h
	include/scpi/scpi_system_mnemonics.h
	include/scpi/scpi_trigger_mnemonics.h
	include/scpi/scpi_source_level_mnemonics.h
	include/scpi/scpi_source_protection_mnemonics.h
	include/scpi/scpi_sense_bandwidth_mnemonics.h
	include/scpi_api.h
	include/scpi_export.h
    include/register_type.h
    include/register_type.hpp
)

add_subdirectory(socket_api)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
