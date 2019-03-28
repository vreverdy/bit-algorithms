// ============================== TYPE TRAITS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            type_traits.hpp
// Description:     Type traits for the manager library
// Creator:         Vincent Reverdy
// Contributor(s):  Vincent Reverdy [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _TYPE_TRAITS_HPP_INCLUDED
#define _TYPE_TRAITS_HPP_INCLUDED
// ========================================================================== //



// ================================ PREAMBLE ================================ //
// C++ standard library
#include <tuple>
#include <memory>
#include <string>
#include <utility>
#include <iostream>
#include <type_traits>
// Project sources
#include "is_valid.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



/* ********************************* TYPE T ********************************* */
// Alias template declaration type t
template <class T, class... Args>
using type_t = T;
/* ************************************************************************** */



/* ******************************** ARGUMENT ******************************** */
// Argument structure definition
struct argument
{
    template <class T>
    constexpr operator T&() const noexcept;
    template <class T>
    constexpr operator T&&() const noexcept;
};
/* ************************************************************************** */



/* ******************************** MIN ARITY ******************************* */
// Min arity structure definition
template <class F, class Args = std::tuple<>, std::size_t N = 128, class = void>
struct min_arity {};

// Min arity sructure specialization: recursive specialization
template <class F, template <class...> class T, class... Args, std::size_t N>
struct min_arity<F, T<Args...>, N, std::enable_if_t<sizeof...(Args) <= N>>
: std::conditional_t<
    std::is_invocable_v<F, Args...>,
    std::integral_constant<std::size_t, sizeof...(Args)>,
    min_arity<F, std::tuple<Args..., argument>, N>
> {};

// Variable template declaration min arity
template <class F>
inline constexpr std::size_t min_arity_v = min_arity<F>::value;
/* ************************************************************************** */



/* *********************** HAS FUNCTION CALL OPERATOR *********************** */
// Has function call operator structure definition
template <class T, class = void, class = void>
struct has_function_call_operator: std::false_type {};

// Has function call operator structure specialization: the type has it
template <class T>
struct has_function_call_operator<
    T,
    std::enable_if_t<std::is_class_v<T> || std::is_union_v<T>>,
    std::void_t<decltype(min_arity_v<T>)>
>: std::true_type {};

// Variable template declaration has function call operator
template <class T>
inline constexpr bool has_function_call_operator_v = has_function_call_operator<
    T
>::value;

// Alias template declaration if function call operator
template <class T>
using if_function_call_operator_t = std::enable_if_t<
    has_function_call_operator_v<T>
>;
/* ************************************************************************** */



/* *************************** IS FUNCTION POINTER ************************** */
// Is function pointer structure definition
template <class T>
struct is_function_pointer
: std::bool_constant<
    std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>
> {};

// Variable template declaration is function pointer
template <class T>
inline constexpr bool is_function_pointer_v = is_function_pointer<T>::value;

// Alias template declaration if function pointer
template <class T>
using if_function_pointer_t = std::enable_if_t<is_function_pointer_v<T>>;
/* ************************************************************************** */



/* *************************** IS FUNCTION OBJECT *************************** */
// Is function object structure definition
template <class T>
struct is_function_object
: std::bool_constant<
    has_function_call_operator_v<T> || is_function_pointer_v<T>
> {};

// Variable template declaration is function object
template <class T>
inline constexpr bool is_function_object_v = is_function_object<T>::value;

// Alias template declaration if function object
template <class T>
using if_function_object_t = std::enable_if_t<is_function_object_v<T>>;
/* ************************************************************************** */



/* ******************************* IS CALLABLE ****************************** */
// Is callable structure definition
template <class T>
struct is_callable
: std::bool_constant<
    is_function_object_v<T> ||
    std::is_function_v<T> ||
    std::is_member_pointer_v<T>
> {};

// Variable template declaration is callable
template <class T>
inline constexpr bool is_callable_v = is_callable<T>::value;

// Alias template declaration if callable
template <class T>
using if_callable_t = std::enable_if_t<is_callable_v<T>>;
/* ************************************************************************** */



/* ****************************** IS CALLABLOID ***************************** */
// Is callabloid structure definition
template <class T>
struct is_callabloid
: std::bool_constant<
    is_callable_v<std::remove_reference_t<T>>
> {};

// Variable template declaration is callabloid
template <class T>
inline constexpr bool is_callabloid_v = is_callabloid<T>::value;

// Alias template declaration if callabloid
template <class T>
using if_callabloid_t = std::enable_if_t<is_callabloid_v<T>>;
/* ************************************************************************** */



/* ******************************** IS OBJECT ******************************* */
// Is reference structure definition
template <class T>
struct is_object: std::is_object<T> {};

// Variable template declaration is object
template <class T>
inline constexpr bool is_object_v = is_object<T>::value;

// Alias template declaration if object
template <class T>
using if_object_t = std::enable_if_t<is_object_v<T>>;
/* ************************************************************************** */



/* ****************************** IS REFERENCE ****************************** */
// Is reference structure definition
template <class T>
struct is_reference: std::is_reference<T> {};

// Variable template declaration is reference
template <class T>
inline constexpr bool is_reference_v = is_reference<T>::value;

// Alias template declaration if reference
template <class T>
using if_reference_t = std::enable_if_t<is_reference_v<T>>;
/* ************************************************************************** */



/* ******************************** IS RANGE ******************************** */
// Is range structure definition
template <class T, class = void>
struct is_range: std::false_type {};

// Is range structure specialization: the type is a range
template <class T>
struct is_range<
    T,
    std::void_t<
        decltype(std::begin(std::declval<T>())),
        decltype(std::end(std::declval<T>()))
    >
>: std::true_type {};

// Variable template declaration is range
template <class T>
inline constexpr bool is_range_v = is_range<T>::value;

// Alias template declaration if range
template <class T>
using if_range_t = std::enable_if_t<is_range_v<T>>;
/* ************************************************************************** */



/* ****************************** IS CONTAINER ****************************** */
// Is container structure definition
template <class T, class = void>
struct is_container: std::false_type {};

// Is container structure specialization: the type is a container
template <class T>
struct is_container<
    T,
    std::void_t<
        if_object_t<T>,
        if_range_t<T>,
        typename T::value_type,
        typename T::size_type,
        typename T::difference_type,
        typename T::reference,
        typename T::const_reference,
        typename T::pointer,
        typename T::const_pointer,
        typename T::iterator,
        typename T::const_iterator,
        typename T::reverse_iterator,
        typename T::const_reverse_iterator,
        decltype(std::declval<T>().front())
    >
>: std::true_type {};

// Variable template declaration is container
template <class T>
inline constexpr bool is_container_v = is_container<T>::value;

// Alias template declaration if container
template <class T>
using if_container_t = std::enable_if_t<is_container_v<T>>;
/* ************************************************************************** */



/* ****************************** IS CHARACTER ****************************** */
// Is character structure definition
template <class T, class = void, class = void>
struct is_character: std::false_type {};

// Is character structure specialization: the type is a character
template <class T>
struct is_character<
    T,
    if_object_t<T>,
    std::void_t<
        typename std::char_traits<T>::char_type,
        typename std::char_traits<T>::int_type,
        typename std::char_traits<T>::off_type,
        typename std::char_traits<T>::pos_type,
        typename std::char_traits<T>::state_type
    >
>: std::true_type {};

// Variable template declaration is character
template <class T>
inline constexpr bool is_character_v = is_character<T>::value;

// Alias template declaration if character
template <class T>
using if_character_t = std::enable_if_t<is_character_v<T>>;
/* ************************************************************************** */



/* ******************************* IS CSTRING ******************************* */
// Is cstring structure definition
template <class T, class = void, class = void>
struct is_cstring: std::false_type {};

// Is cstring structure specialization: the type is a cstring
template <class T>
struct is_cstring<
    T,
    std::enable_if_t<
        std::is_array_v<std::remove_reference_t<T>> ||
        std::is_pointer_v<std::remove_reference_t<T>>
    >,
    std::void_t<
        if_character_t<std::remove_reference_t<decltype(*std::declval<T>())>>
    >
>: std::true_type {};

// Variable template declaration is cstring
template <class T>
inline constexpr bool is_cstring_v = is_cstring<T>::value;

// Alias template declaration if cstring
template <class T>
using if_cstring_t = std::enable_if_t<is_cstring_v<T>>;
/* ************************************************************************** */



/* ******************************** IS STRING ******************************* */
// Is string structure definition
template <class T, class = void, class = void>
struct is_string: std::false_type {};

// Is string structure specialization: the type is a string
template <class T>
struct is_string<
    T,
    if_object_t<T>,
    std::void_t<
        if_container_t<T>,
        if_character_t<typename T::traits_type::char_type>
    >
>: std::true_type {};

// Variable template declaration is string
template <class T>
inline constexpr bool is_string_v = is_string<T>::value;

// Alias template declaration if string
template <class T>
using if_string_t = std::enable_if_t<is_string_v<T>>;
/* ************************************************************************** */



/* ****************************** IS STRINGOID ****************************** */
// Is stringoid structure definition
template <class T, class = void>
struct is_stringoid: std::false_type {};

// Is stringoid structure specialization: the type is a stringoid
template <class T>
struct is_stringoid<
    T,
    std::enable_if_t<
        is_cstring_v<std::remove_reference_t<T>> ||
        is_string_v<std::remove_reference_t<T>>
    >
>: std::true_type {};

// Variable template declaration is stringoid
template <class T>
inline constexpr bool is_stringoid_v = is_stringoid<T>::value;

// Alias template declaration if stringoid
template <class T>
using if_stringoid_t = std::enable_if_t<is_stringoid_v<T>>;
/* ************************************************************************** */



/* ******************************* IS CONSTANT ****************************** */
// Is constant structure definition
template <class T, class = void>
struct is_constant: std::false_type {};

// Is constant structure definition: the type is a constant
template <class T>
struct is_constant<
    T,
    std::void_t<
        decltype(T::value)
    >
>: std::true_type {};

// Variable template declaration is constant
template <class T>
inline constexpr bool is_constant_v = is_constant<T>::value;

// Alias template declaration if integral constant
template <class T>
using if_constant_t = std::enable_if_t<is_constant_v<T>>;
/* ************************************************************************** */



/* ************************** IS INTEGRAL CONSTANT ************************** */
// Is integral constant structure definition
template <class T, class = void>
struct is_integral_constant: std::false_type {};

// Is integral constant structure definition: the type is an integral constant
template <class T>
struct is_integral_constant<
    T,
    std::enable_if_t<
        std::is_integral_v<decltype(T::value)>
    >
>: std::true_type {};

// Variable template declaration is integral constant
template <class T>
inline constexpr bool is_integral_constant_v = is_integral_constant<T>::value;

// Alias template declaration if integral constant
template <class T>
using if_integral_constant_t = std::enable_if_t<is_integral_constant_v<T>>;
/* ************************************************************************** */



// ========================================================================== //
#endif // _TYPE_TRAITS_HPP_INCLUDED
// ========================================================================== //
