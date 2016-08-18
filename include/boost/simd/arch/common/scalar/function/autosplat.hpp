//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_AUTOSPLAT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_AUTOSPLAT_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/arch/common/tags.hpp>
#include <boost/simd/detail/decorator.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  // ({P,S},{S,P})
  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( (typename F, typename P0, typename S0, typename E0)
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   )
  {
    using functor = bd::functor<F>;
    using value_t = typename P0::value_type;

    auto operator()( S0 s0, P0 p0) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(P0(value_t(s0)), p0))
  };

  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( (typename F, typename P0, typename S0, typename E0)
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   )
  {
    using functor = bd::functor<F>;
    using value_t = typename P0::value_type;

    auto operator()( P0 p0
                   , S0 s0
                   ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(p0, P0(value_t(s0)) ) )
  };

  // ({D,P,S},{D,S,P})
  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( (typename F, typename D, typename P0, typename S0, typename E0)
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::decorator_<D>
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   )
  {
    using functor = decltype(detail::decorator<D>()(bd::functor<F>()));
    using value_t = typename P0::value_type;

    auto operator()( D const&, S0 s0, P0 p0 ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(P0(value_t(s0)), p0))
  };

  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( (typename F, typename D, typename P0, typename S0, typename E0)
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::decorator_<D>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   )
  {
    using functor = decltype(detail::decorator<D>()(bd::functor<F>()));
    using value_t = typename P0::value_type;

    auto operator()( D const&, P0 p0, S0 s0 ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(p0, P0(value_t(s0)) ) )
  };

  // ({U,P,S},{U,S,P})
  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( (typename F, typename D, typename P0, typename S0, typename E0)
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bd::unspecified_<D>
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   )
  {
    using functor = bd::functor<F>;
    using value_t = typename P0::value_type;

    auto operator()( D d, S0 s0, P0 p0 ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(d,P0(value_t(s0)), p0))
  };

  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( (typename F, typename D, typename P0, typename S0, typename E0)
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bd::unspecified_<D>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   )
  {
    using functor = bd::functor<F>;
    using value_t = typename P0::value_type;

    auto operator()( D d, P0 p0, S0 s0 ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(d,p0, P0(value_t(s0)) ) )
  };

  // ({D,U,P,S},{D,U,S,P})
  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK( ( typename F, typename D, typename Opt
                                    , typename P0, typename S0, typename E0
                                    )
                                  , bd::elementwise_<F>
                                  , bd::cpu_
                                  , bs::decorator_<D>
                                  , bd::unspecified_<Opt>
                                  , bd::scalar_<bd::unspecified_<S0>>
                                  , bs::pack_<bd::unspecified_<P0>, E0>
                                  )
  {
    using functor = decltype(detail::decorator<D>()(bd::functor<F>()));
    using value_t = typename P0::value_type;

    auto operator()( D const&, Opt o, S0 s0, P0 p0 ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(o, P0(value_t(s0)), p0))
  };

  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK( ( typename F, typename D, typename Opt
                                    , typename P0, typename S0, typename E0
                                    )
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::decorator_<D>
                                   , bd::unspecified_<Opt>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   )
  {
    using functor = decltype(detail::decorator<D>()(bd::functor<F>()));
    using value_t = typename P0::value_type;

    auto operator()( D const&, Opt o, P0 p0, S0 s0 ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(o, p0, P0(value_t(s0)) ) )
  };

  // ({P,S},{P,S},{P,S})
  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( ( typename F
                                     , typename P0
                                     , typename S0
                                     , typename E0
                                     )
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   )
  {
    using functor = bd::functor<F>;
    using value_t = typename P0::value_type;

    auto operator()( P0 p0
                   , P0 p1
                   , S0 s0
                   ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(p0, p1, P0(value_t(s0))))
  };

  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( ( typename F
                                     , typename P0
                                     , typename S0
                                     , typename E0
                                     )
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   )
  {
    using functor = bd::functor<F>;
    using value_t = typename P0::value_type;

    auto operator()( P0 p0
                   , S0 s0
                   , P0 p1
                   ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(p0, P0(value_t(s0)), p1))
  };

  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( ( typename F
                                     , typename P0
                                     , typename S0
                                     , typename E0
                                     )
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   )
  {
    using functor = bd::functor<F>;
    using value_t = typename P0::value_type;

    auto operator()( S0 s0
                   , P0 p0
                   , P0 p1
                   ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(P0(value_t(s0)), p0, p1))
  };

  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( ( typename F
                                     , typename P0
                                     , typename S0
                                     , typename S1
                                     , typename E0
                                     )
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   , bd::scalar_<bd::unspecified_<S1>>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   )
  {
    using functor = bd::functor<F>;
    using value_t = typename P0::value_type;

    auto operator()( S0 s0
                   , S1 s1
                   , P0 p0
                   ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(P0(value_t(s0)), P0(value_t(s1)), p0))
  };

  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( ( typename F
                                     , typename P0
                                     , typename S0
                                     , typename S1
                                     , typename E0
                                     )
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   , bd::scalar_<bd::unspecified_<S1>>
                                   )
  {
    using functor = bd::functor<F>;
    using value_t = typename P0::value_type;

    auto operator()( S0 s0
                   , P0 p0
                   , S1 s1
                   ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(P0(value_t(s0)), p0, P0(value_t(s1))))
  };

  // -----------------------------------------------------------------------------------------------

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( ( typename F
                                     , typename P0
                                     , typename S0
                                     , typename S1
                                     , typename E0
                                     )
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::pack_<bd::unspecified_<P0>, E0>
                                   , bd::scalar_<bd::unspecified_<S0>>
                                   , bd::scalar_<bd::unspecified_<S1>>
                                   )
  {
    using functor = bd::functor<F>;
    using value_t = typename P0::value_type;

    auto operator()( P0 p0
                   , S0 s0
                   , S1 s1
                   ) const
    BOOST_NOEXCEPT_DECLTYPE_BODY(functor()(p0, P0(value_t(s0)), P0(value_t(s1))))
  };
} } }

#endif
