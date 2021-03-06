//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/is_included.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" is_included integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_included;

  using r_t = decltype(is_included(T(),T()));

  // specific values tests
  STF_EQUAL(is_included(bs::Mone<T>(),bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_included(bs::One<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(is_included(bs::One<T>(),bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_included(bs::One<T>(),bs::Three<T>()), r_t(true));
  STF_EQUAL(is_included(bs::One<T>(),bs::Two<T>()), r_t(false));
  STF_EQUAL(is_included(bs::One<T>(),bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_included(bs::Zero<T>(), bs::Zero<T>()), r_t(true));
} // end of test for integer_
