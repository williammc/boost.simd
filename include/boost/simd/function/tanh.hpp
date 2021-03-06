//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TANH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TANH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-hyperbolic
    Function object implementing tanh capabilities

    Returns the hyperbolic tangent: \f$\frac{\sinh(x)}{\cosh(x)}\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = tanh(x);
    @endcode

    is similar to:

    @code
    T r = sinh(x)/cosh(x);
    @endcode

  **/
  Value tanh(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/tanh.hpp>
#include <boost/simd/function/simd/tanh.hpp>

#endif
