//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_FINITE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_FINITE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_finite capabilities

    Returns @ref True if x is not inf, -inf or nan, else returns @ref False.

    @par Semantic:

    @code
    as_logical_t<T> r = is_finite(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = x-x ==  0;
    @endcode

    @par Alias:
    is_not_invalid

  **/
  as_logical_t<Value> is_finite(Value const& x);
} }
#endif

#include <boost/simd/function/scalar/is_finite.hpp>
#include <boost/simd/function/simd/is_finite.hpp>

#endif
