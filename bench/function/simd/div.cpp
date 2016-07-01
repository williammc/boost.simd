// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/div.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;

DEFINE_SIMD_BENCH(si_div, boost::simd::div);
DEFINE_SCALAR_BENCH(sc_div, boost::simd::div);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<si_div, NS_BENCH_IEEE_TYPES>(-10, 10, -10, 10);
  nsb::for_each<si_div, NS_BENCH_IEEE_TYPES>(0, 10,  0,  10);
  nsb::for_each<sc_div, NS_BENCH_IEEE_TYPES>(-10, 10, -10, 10);
  nsb::for_each<sc_div, NS_BENCH_IEEE_TYPES>(0, 10,  0,  10);
}
