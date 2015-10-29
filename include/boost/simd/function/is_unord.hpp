//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_UNORD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_UNORD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True if x or y is nan.

    @par Semantic:

    @code
    as_logical_t<T> r = is_unord(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = (x != x) || (y != y);
    @endcode



    @return a logical value

**/
  template<typename T> auto is_unord(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True if x or y is nan.


      Function object tied to simd::is_unord

      @see simd::is_unord
    **/
    const boost::dispatch::functor<tag::is_unord_> is_unord = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_unord.hpp>
#include <boost/simd/arch/common/scalar/function/is_unord.hpp>
//#include <boost/simd/arch/common/function/simd/is_unord.hpp>

#endif