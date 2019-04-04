// ================================ CONCEPTS ================================ //
// Project:         The Experimental Bit Algorithms Library
// Name:            concepts.hpp
// Description:     Concepts for the manager library
// Creator:         Vincent Reverdy
// Contributor(s):  Vincent Reverdy [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _CONCEPTS_HPP_INCLUDED
#define _CONCEPTS_HPP_INCLUDED
// ========================================================================== //



// ================================ PREAMBLE ================================ //
// C++ standard library
#include <type_traits>
// Project sources
#include "type_traits.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



/* **************************** FUNCTION POINTER **************************** */
// Function pointer concept definition
template <class T>
concept bool FunctionPointer = is_function_pointer_v<T>;
/* ************************************************************************** */



/* **************************** FUNCTION OBJECT ***************************** */
// Function object concept definition
template <class T>
concept bool FunctionObject = is_function_object_v<T>;
/* ************************************************************************** */



/* ******************************** CALLABLE ******************************** */
// Callable concept definition
template <class T>
concept bool Callable = is_callable_v<T>;
/* ************************************************************************** */



/* ******************************* CALLABLOID ******************************* */
// Callabloid concept definition
template <class T>
concept bool Callabloid = is_callabloid_v<T>;
/* ************************************************************************** */



/* ********************************* OBJECT ********************************* */
// Object concept definition
template <class T>
concept bool Object = is_object_v<T>;
/* ************************************************************************** */



/* ******************************* REFERENCE ******************************** */
// Reference concept definition
template <class T>
concept bool Reference = is_reference_v<T>;
/* ************************************************************************** */



/* ********************************* RANGE ********************************** */
// Range concept definition
template <class T>
concept bool Range = is_range_v<T>;
/* ************************************************************************** */



/* ******************************* CONTAINER ******************************** */
// Container concept definition
template <class T>
concept bool Container = is_container_v<T>;
/* ************************************************************************** */



/* ******************************* CHARACTER ******************************** */
// Character concept definition
template <class T>
concept bool Character = is_character_v<T>;
/* ************************************************************************** */



/* ******************************** CSTRING ********************************* */
// Cstring concept definition
template <class T>
concept bool CString = is_cstring_v<T>;
/* ************************************************************************** */



/* ********************************* STRING ********************************* */
// String concept definition
template <class T>
concept bool String = is_string_v<T>;
/* ************************************************************************** */



/* ******************************* STRINGOID ******************************** */
// Stringoid concept definition
template <class T>
concept bool Stringoid = is_stringoid_v<T>;
/* ************************************************************************** */



/* ******************************** CONSTANT ******************************** */
// Constant concept definition
template <class T>
concept bool Constant = is_constant_v<T>;
/* ************************************************************************** */



/* **************************** INTEGRALCONSTANT **************************** */
// Integral constant concept definition
template <class T>
concept bool IntegralConstant = is_integral_constant_v<T>;
/* ************************************************************************** */



// ========================================================================== //
#endif // _CONCEPTS_HPP_INCLUDED
// ========================================================================== //
