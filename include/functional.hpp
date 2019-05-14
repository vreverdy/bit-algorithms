// =============================== FUNCTIONAL =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            functional.hpp
// Description:     Specialization of function objects for bits
// Creator:         Vincent Reverdy
// Contributor(s):  Vincent Reverdy [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _FUNCTIONAL_HPP_INCLUDED
#define _FUNCTIONAL_HPP_INCLUDED
// ========================================================================== //



// ================================ PREAMBLE ================================ //
// C++ standard library
#include <functional>
// Project sources
#include "bit_algorithm_details.hpp"
#include "type_traits.hpp"
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //



/* *************************** BIT FUNCTION OBJECT ************************** */
// Bit function object structure declaration
template <class...>
class bit_function_object;

// Bit function object structure specialization
template <class Result, template <class> class Function, class Arg>
class bit_function_object<Result, Function<Arg>>
{
    // Implementation details: type traits
    private:
    template <class... Bits>
    using _if_bits_t = std::enable_if_t<(is_bit_v<std::decay_t<Bits>> && ...)>;

    // Lifecycle
    public:
    constexpr bit_function_object() noexcept = default;
    
    // Function call operator
    public:
    template <class... Bits, class = _if_bits_t<Bits...>>
    constexpr Result operator(Bits&&...) const noexcept;
};
/* ************************************************************************** */



/* ********************************** PLUS ********************************** */
// Plus structure specialization 
} namespace std {
template <>
struct plus<::bit::bit>
: ::bit::bit_function_object<::bit::bit_value, ::std::plus<unsigned int>>
{
};
} namespace bit {
/* ************************************************************************** */



/* ********************************* MINUS ********************************** */
// Plus structure specialization 
} namespace std {
template <>
struct minus<::bit::bit>
: ::bit::bit_function_object<::bit::bit_value, ::std::minus<unsigned int>>
{
};
} namespace bit {
/* ************************************************************************** */



// -------------- BIT FUNCTION OBJECT: FUNCTION CALL OPERATOR --------------- //
template <class Result, template <class> class Function, class Arg>
template <class... Bits, class>
constexpr Result bit_function_object<Result, Function<Arg>>::operator()(
    Bits&&... bits
) const noexcept
{
    return static_cast<Result>(
        std::invoke(
            Function<Arg>{},
            static_cast<Arg>(std::forward<Bits>(bits))...
        )
    );
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
} // namespace bit
#endif // _FUNCTIONAL_HPP_INCLUDED
// ========================================================================== //
