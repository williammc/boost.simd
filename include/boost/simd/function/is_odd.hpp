//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_ODD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_ODD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_odd capabilities

    Returns @ref True or @ref False according x is odd or not.

    @par Semantic:

    @code
    as_logical_t<T> r = is_odd(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = (abs(x)/2)*2 == abs(x)-1;
    @endcode

    @par Note:

    A floating number x is odd if x-1 is even

    @see is_even,  is_flint

  **/
  as_logical_t<Value> is_odd(Value const& x);
} }
#endif

#include <boost/simd/function/scalar/is_odd.hpp>
#include <boost/simd/function/simd/is_odd.hpp>

#endif
