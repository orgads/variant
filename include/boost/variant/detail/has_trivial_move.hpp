
// (C) Copyright Eric Friedman 2002-2003.
// Permission to copy, use, modify, sell and distribute this software is 
// granted provided this copyright notice appears in all copies. This software 
// is provided "as is" without express or implied warranty, and with no claim 
// as to its suitability for any purpose.
//
// See http://www.boost.org for most recent version including documentation.

#ifndef BOOST_VARIANT_DETAIL_HAS_TRIVIAL_MOVE_HPP_INCLUDED
#define BOOST_VARIANT_DETAIL_HAS_TRIVIAL_MOVE_HPP_INCLUDED

#include "boost/type_traits/has_trivial_copy.hpp"
#include "boost/type_traits/has_trivial_assign.hpp"

#include "boost/mpl/and.hpp"
#include "boost/mpl/or.hpp"

// should be the last #include
#include "boost/type_traits/detail/bool_trait_def.hpp"

namespace boost {
namespace detail { namespace variant {

// TRAIT: has_trivial_move

template <typename T>
struct has_trivial_move_impl
{
    BOOST_STATIC_CONSTANT(
        bool, value = (
            mpl::and_<
              has_trivial_copy<T>
            , has_trivial_assign<T>
            >::type::value
            )
        );
};

BOOST_TT_AUX_BOOL_TRAIT_DEF1(
      has_trivial_move
    , T
    , (::boost::detail::variant::has_trivial_move_impl<T>::value)
    )


// TRAIT: has_trivial_move_constructor

template <typename T>
struct has_trivial_move_constructor_impl
{
    BOOST_STATIC_CONSTANT(
        bool, value = (
            mpl::or_<
              has_trivial_move<T>
            , has_trivial_copy<T>
            >::type::value
            )
        );
};

BOOST_TT_AUX_BOOL_TRAIT_DEF1(
      has_trivial_move_constructor
    , T
    , (::boost::detail::variant::has_trivial_move_constructor_impl<T>::value)
    )


// TRAIT: has_trivial_move_assign

template <typename T>
struct has_trivial_move_assign_impl
{
    BOOST_STATIC_CONSTANT(
        bool, value = (
            mpl::or_<
              has_trivial_move<T>
            , has_trivial_assign<T>
            >::type::value
            )
        );
};

BOOST_TT_AUX_BOOL_TRAIT_DEF1(
      has_trivial_move_assign
    , T
    , (::boost::detail::variant::has_trivial_move_assign_impl<T>::value)
    )

}} // namespace detail::variant

BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(1,::boost::detail::variant::has_trivial_move)
BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(1,::boost::detail::variant::has_trivial_move_constructor)
BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(1,::boost::detail::variant::has_trivial_move_assign)

} // namespace boost

#include "boost/type_traits/detail/bool_trait_undef.hpp"

#endif // BOOST_VARIANT_DETAIL_HAS_TRIVIAL_MOVE_HPP_INCLUDED
