//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG10_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG10_HPP_INCLUDED

#include <boost/simd/arch/common/detail/scalar/logarithm.hpp>
#include <boost/simd/arch/common/detail/simd/logarithm.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/simd/is_not_nan.hpp>
#include <boost/simd/function/simd/is_positive.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD_IF ( log10_
                          , (typename A0, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_< bd::floating_<A0>, X>
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return detail::logarithm<A0,tag::simd_type>::log10(a0);
    }
  };
} } }

#endif
