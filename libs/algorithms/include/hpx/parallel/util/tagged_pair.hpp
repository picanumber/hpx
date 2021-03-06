//  Copyright Eric Niebler 2013-2015
//  Copyright 2015 Hartmut Kaiser
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// This was modeled after the code available in the Range v3 library

#if !defined(HPX_UTIL_TAGGED_PAIR_DEC_23_2015_1014AM)
#define HPX_UTIL_TAGGED_PAIR_DEC_23_2015_1014AM

#include <hpx/config.hpp>
#include <hpx/assertion.hpp>
#include <hpx/datastructures/tagged_pair.hpp>
#include <hpx/datastructures/tuple.hpp>
#include <hpx/lcos/future.hpp>
#include <hpx/type_support/decay.hpp>

#include <cstddef>
#include <type_traits>
#include <utility>

namespace hpx { namespace util {
    ///////////////////////////////////////////////////////////////////////////
    template <typename Tag1, typename Tag2, typename T1, typename T2>
    hpx::future<tagged_pair<Tag1(typename decay<T1>::type),
        Tag2(typename decay<T2>::type)>>
    make_tagged_pair(hpx::future<std::pair<T1, T2>>&& f)
    {
        typedef hpx::util::tagged_pair<Tag1(typename decay<T1>::type),
            Tag2(typename decay<T2>::type)>
            result_type;

#if defined(HPX_COMPUTE_DEVICE_CODE)
        HPX_ASSERT(false);
        return hpx::future<result_type>();
#else
        return lcos::make_future<result_type>(
            std::move(f), [](std::pair<T1, T2>&& p) -> result_type {
                return make_tagged_pair<Tag1, Tag2>(std::move(p));
            });
#endif
    }

    template <typename Tag1, typename Tag2, typename... Ts>
    hpx::future<tagged_pair<Tag1(typename tuple_element<0, tuple<Ts...>>::type),
        Tag2(typename tuple_element<1, tuple<Ts...>>::type)>>
    make_tagged_pair(hpx::future<tuple<Ts...>>&& f)
    {
        static_assert(
            sizeof...(Ts) >= 2, "tuple must have at least 2 elements");

        typedef hpx::util::tagged_pair<
            Tag1(typename tuple_element<0, tuple<Ts...>>::type),
            Tag2(typename tuple_element<1, tuple<Ts...>>::type)>
            result_type;

#if defined(HPX_COMPUTE_DEVICE_CODE)
        HPX_ASSERT(false);
        return hpx::future<result_type>();
#else
        return lcos::make_future<result_type>(
            std::move(f), [](tuple<Ts...>&& p) -> result_type {
                return make_tagged_pair<Tag1, Tag2>(std::move(p));
            });
#endif
    }
}}    // namespace hpx::util

#endif
