# Copyright (c) 2019 The STE||AR-Group
#
# SPDX-License-Identifier: BSL-1.0
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Default location is $HPX_ROOT/libs/cache/include
set(cache_headers
    hpx/cache/local_cache.hpp
    hpx/cache/lru_cache.hpp
    hpx/cache/entries/entry.hpp
    hpx/cache/entries/fifo_entry.hpp
    hpx/cache/entries/lfu_entry.hpp
    hpx/cache/entries/lru_entry.hpp
    hpx/cache/entries/size_entry.hpp
    hpx/cache/policies/always.hpp
    hpx/cache/statistics/local_full_statistics.hpp
    hpx/cache/statistics/local_statistics.hpp
    hpx/cache/statistics/no_statistics.hpp
)

# Default location is $HPX_ROOT/libs/cache/include_compatibility
set(cache_compat_headers
    hpx/util/cache/local_cache.hpp
    hpx/util/cache/lru_cache.hpp
    hpx/util/cache/entries/entry.hpp
    hpx/util/cache/entries/fifo_entry.hpp
    hpx/util/cache/entries/lfu_entry.hpp
    hpx/util/cache/entries/lru_entry.hpp
    hpx/util/cache/entries/size_entry.hpp
    hpx/util/cache/policies/always.hpp
    hpx/util/cache/statistics/local_full_statistics.hpp
    hpx/util/cache/statistics/local_statistics.hpp
    hpx/util/cache/statistics/no_statistics.hpp
)

# Default location is $HPX_ROOT/libs/cache/src
set(cache_sources)

include(HPX_AddModule)
add_hpx_module(
  cache
  COMPATIBILITY_HEADERS ON # Added in 1.4.0
  DEPRECATION_WARNINGS FORCE_LINKING_GEN
  SOURCES ${cache_sources}
  HEADERS ${cache_headers}
  COMPAT_HEADERS ${cache_compat_headers}
  DEPENDENCIES hpx_config
  CMAKE_SUBDIRS examples tests
)
