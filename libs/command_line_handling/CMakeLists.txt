# Copyright (c) 2019 The STE||AR-Group
#
# SPDX-License-Identifier: BSL-1.0
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(command_line_handling_headers
    hpx/command_line_handling/command_line_handling.hpp
    hpx/command_line_handling/parse_command_line.hpp
)

set(command_line_handling_compat_headers hpx/util/command_line_handling.hpp
                                         hpx/util/parse_command_line.hpp
)

set(command_line_handling_sources command_line_handling.cpp
                                  parse_command_line.cpp
)

include(HPX_AddModule)
add_hpx_module(
  command_line_handling
  COMPATIBILITY_HEADERS ON
  DEPRECATION_WARNINGS FORCE_LINKING_GEN
  GLOBAL_HEADER_GEN ON
  SOURCES ${command_line_handling_sources}
  HEADERS ${command_line_handling_headers}
  COMPAT_HEADERS ${command_line_handling_compat_headers}
  DEPENDENCIES
    hpx_allocator_support
    hpx_asio
    hpx_assertion
    hpx_affinity
    hpx_basic_execution
    hpx_batch_environments
    hpx_concurrency
    hpx_config
    hpx_datastructures
    hpx_debugging
    hpx_errors
    hpx_execution
    hpx_filesystem
    hpx_functional
    hpx_format
    hpx_memory
    hpx_mpi_base
    hpx_prefix
    hpx_program_options
    hpx_runtime_configuration
    hpx_threading
    hpx_topology
    hpx_util
    hpx_version
  CMAKE_SUBDIRS
)
