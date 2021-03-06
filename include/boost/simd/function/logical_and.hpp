//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_AND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_AND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing logical_and capabilities

    return the logical and of the two parameters.

    The operands must share the same @ref cardinal_of value.

    Infix notation can be used with operator '&&'.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = logical_and(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = x && y ;
    @endcode

    @see  logical_or, logical_xor, logical_notand,
    logical_andnot, logical_notor, logical_ornot, logical_not

  **/
  as_logical_t<Value> logical_and(Value const& x, Value const& y);
} }
#endif

#include <boost/simd/function/scalar/logical_and.hpp>
#include <boost/simd/function/simd/logical_and.hpp>

#endif
