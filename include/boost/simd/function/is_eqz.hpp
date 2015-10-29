//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_EQZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_EQZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according x is zero or not.

    @par Semantic:

    @code
    as_logical_t<T> r = is_eqz(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = x == 0;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_eqz(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True or False according x is zero or not.


      Function object tied to simd::is_eq

z      @see simd::is_eq
z    **/
    const boost::dispatch::functor<tag::is_eqz_> is_eqz = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_eqz.hpp>
#include <boost/simd/arch/common/scalar/function/is_eqz.hpp>
//#include <boost/simd/arch/common/function/simd/is_eqz.hpp>

#endif