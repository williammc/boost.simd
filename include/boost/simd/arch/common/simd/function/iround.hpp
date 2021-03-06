//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IROUND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IROUND_HPP_INCLUDED

#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/toint.hpp>
#include <boost/simd/function/simd/round.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
 BOOST_DISPATCH_OVERLOAD_IF ( iround_
                         , (typename A0, typename X)
                         , (detail::is_native<X>)
                         , bd::cpu_
                         , bs::pack_<bd::arithmetic_<A0>, X>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF ( iround_
                          , (typename A0, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<A0> operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return saturated_(toint)(round(a0));
    }
  };


} } }


#endif
