// =============================== SEPARATOR ================================ //
// Project:         The Experimental Bit Algorithms Library
// Name:            separator.hpp
// Description:     A line separator involved in files layout
// Creator:         Vincent Reverdy
// Contributor(s):  Vincent Reverdy [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _SEPARATOR_HPP_INCLUDED
#define _SEPARATOR_HPP_INCLUDED
// ========================================================================== //



// ================================ PREAMBLE ================================ //
// C++ standard library
#include <string>
#include <cassert>
#include <utility>
#include <iostream>
#include <algorithm>
// Project sources
#include "concepts.hpp"
#include "identity.hpp"
#include "type_traits.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



/* ******************************* SEPARATOR ******************************** */
// Separator class definition
template <
    Callable Titler = identity,
    Container String = std::string,
    Constant Width = std::integral_constant<std::size_t, 80>
>
class separator
{
    // Friendship
    template <class, class, class>
    friend class separator;
    
    // Types and constants
    public:
    using string = String;
    using titler_type = Titler;
    using size_type = typename string::size_type;
    using char_type = typename string::value_type;
    using default_width = Width;

    // Lifecycle
    public:
    constexpr separator(const separator&) = default;
    constexpr separator(separator&&) = default;
    template <Stringoid Prefix, Stringoid Suffix>
    constexpr separator(Prefix&&, char_type, Suffix&&);
    template <Stringoid Prefix, Stringoid Suffix>
    constexpr separator(Prefix&&, char_type, Suffix&&, size_type);
    template <Stringoid Prefix, Stringoid Suffix>
    constexpr separator(Prefix&&, char_type, Suffix&&, titler_type);
    template <Stringoid Prefix, Stringoid Suffix>
    constexpr separator(Prefix&&, char_type, Suffix&&, titler_type, size_type);
    template <class... Args>
    explicit constexpr separator(const separator<Args...>&);
    template <class... Args>
    constexpr separator(const separator<Args...>&, size_type);
    template <class... Args>
    constexpr separator(const separator<Args...>&, titler_type);
    template <class... Args>
    constexpr separator(const separator<Args...>&, titler_type, size_type);

    // Assignment
    public:
    constexpr separator& operator=(const separator&) = default;
    constexpr separator& operator=(separator&&) = default;

    // Conversion
    public:
    explicit constexpr operator string() const;

    // Production
    public:
    constexpr string operator()() const;
    template <class T>
    constexpr string operator()(T&&) const;

    // Properties
    public:
    constexpr string prefix() const;
    constexpr char_type symbol() const;
    constexpr string suffix() const;
    constexpr titler_type titler() const;
    constexpr size_type width() const;
    template <class T>
    constexpr string title(T&&) const;
    
    // Implementation details: data members
    private:
    string _prefix;
    char_type _symbol;
    string _suffix;
    titler_type _titler;
    size_type _width;
};

// Non-members
template <class... Args>
std::ostream& operator<<(std::ostream&, const separator<Args...>&);


// Class template argument deduction guides
template <
    Container Affix,
    Character Symbol,
    class... Args
>
separator(Affix, Symbol, Affix, Args...)
-> separator<typename separator<>::titler_type, Affix>;
template <
    Stringoid Prefix,
    Character Symbol,
    Stringoid Suffix,
    class... Args
>
separator(Prefix, Symbol, Suffix, Args...)
-> separator<typename separator<>::titler_type, std::string>;
template <
    Container Affix,
    Character Symbol,
    Callable Titler,
    class... Args
>
separator(Affix, Symbol, Affix, Titler, Args...)
-> separator<Titler, Affix>;
template <
    Stringoid Prefix,
    Character Symbol,
    Stringoid Suffix,
    Callable Titler,
    class... Args
>
separator(Prefix, Symbol, Suffix, Titler, Args...)
-> separator<Titler, std::string>;
template <
    Callable Titler,
    Container String,
    Constant Width,
    class... Args
>
separator(const separator<Titler, String, Width>&, Args...)
-> separator<Titler, String, Width>;
template <
    Callable Titler,
    Container String,
    Constant Width,
    Callable F,
    class... Args
>
separator(const separator<Titler, String, Width>&, F, Args...)
-> separator<F, String, Width>;
/* ************************************************************************** */



// -------------------------- SEPARATOR: LIFECYCLE -------------------------- //
// Explicitly constructs a separator with a default titler and default width
template <Callable Titler, Container String, Constant Width>
template <Stringoid Prefix, Stringoid Suffix>
constexpr separator<Titler, String, Width>::separator(
    Prefix&& prefix,
    char_type symbol,
    Suffix&& suffix
)
: _prefix(std::forward<Prefix>(prefix))
, _symbol(symbol)
, _suffix(std::forward<Suffix>(suffix))
, _titler()
, _width(default_width::value)
{
}

// Explicitly constructs a separator with a default titler
template <Callable Titler, Container String, Constant Width>
template <Stringoid Prefix, Stringoid Suffix>
constexpr separator<Titler, String, Width>::separator(
    Prefix&& prefix,
    char_type symbol,
    Suffix&& suffix,
    size_type width
)
: _prefix(std::forward<Prefix>(prefix))
, _symbol(symbol)
, _suffix(std::forward<Suffix>(suffix))
, _titler()
, _width(width)
{
}

// Explicitly constructs a separator with a default width
template <Callable Titler, Container String, Constant Width>
template <Stringoid Prefix, Stringoid Suffix>
constexpr separator<Titler, String, Width>::separator(
    Prefix&& prefix,
    char_type symbol,
    Suffix&& suffix,
    titler_type titler
)
: _prefix(std::forward<Prefix>(prefix))
, _symbol(symbol)
, _suffix(std::forward<Suffix>(suffix))
, _titler(titler)
, _width(default_width::value)
{
}

// Explicitly constructs a separator from its properties
template <Callable Titler, Container String, Constant Width>
template <Stringoid Prefix, Stringoid Suffix>
constexpr separator<Titler, String, Width>::separator(
    Prefix&& prefix,
    char_type symbol,
    Suffix&& suffix,
    titler_type titler,
    size_type width
)
: _prefix(std::forward<Prefix>(prefix))
, _symbol(symbol)
, _suffix(std::forward<Suffix>(suffix))
, _titler(titler)
, _width(width)
{
}

// Explicitly constructs a separator from another one
template <Callable Titler, Container String, Constant Width>
template <class... Args>
constexpr separator<Titler, String, Width>::separator(
    const separator<Args...>& other
)
: _prefix(other._prefix)
, _symbol(other._symbol)
, _suffix(other._suffix)
, _titler(other._titler)
, _width(other._width)
{
}

// Explicitly constructs a separator from another one and a width
template <Callable Titler, Container String, Constant Width>
template <class... Args>
constexpr separator<Titler, String, Width>::separator(
    const separator<Args...>& other,
    size_type width
)
: _prefix(other._prefix)
, _symbol(other._symbol)
, _suffix(other._suffix)
, _titler(other._titler)
, _width(width)
{
}

// Explicitly constructs a separator from another one and a titler
template <Callable Titler, Container String, Constant Width>
template <class... Args>
constexpr separator<Titler, String, Width>::separator(
    const separator<Args...>& other,
    titler_type titler
)
: _prefix(other._prefix)
, _symbol(other._symbol)
, _suffix(other._suffix)
, _titler(titler)
, _width(other._width)
{
}

// Explicitly constructs a separator from another one, a titler, and a width
template <Callable Titler, Container String, Constant Width>
template <class... Args>
constexpr separator<Titler, String, Width>::separator(
    const separator<Args...>& other,
    titler_type titler,
    size_type width
)
: _prefix(other._prefix)
, _symbol(other._symbol)
, _suffix(other._suffix)
, _titler(titler)
, _width(width)
{
}
// -------------------------------------------------------------------------- //



// ------------------------- SEPARATOR: CONVERSION -------------------------- //
// Explicitly converts the separator to a string
template <Callable Titler, Container String, Constant Width>
constexpr separator<Titler, String, Width>::operator string(
) const
{
    return (*this)();
}
// -------------------------------------------------------------------------- //



// ------------------------- SEPARATOR: PRODUCTION -------------------------- //
// Returns a separator string with no title
template <Callable Titler, Container String, Constant Width>
constexpr typename separator<Titler, String, Width>::string
separator<Titler, String, Width>::operator()(
) const
{    
    // Initialization
    const size_type affixes_size = std::size(_prefix) + std::size(_suffix);
    string result(_width, char_type{});
    auto it = std::begin(result);
    assert(affixes_size <= _width);

    // Make separator without title
    it = std::copy(std::begin(_prefix), std::end(_prefix), it);
    if (affixes_size < _width) {
        std::fill_n(it, _width - affixes_size, _symbol);
        std::advance(it, _width - affixes_size);
    }
    it = std::copy(std::begin(_suffix), std::end(_suffix), it);

    // Finalization
    return result;
}

// Returns a separator string with a centered title
template <Callable Titler, Container String, Constant Width>
template <class T>
constexpr typename separator<Titler, String, Width>::string
separator<Titler, String, Width>::operator()(
    T&& text
) const
{
    // Types and constants
    constexpr size_type zero = 0;
    constexpr size_type two = 2;
    
    // Initialization
    const string title_text = title(std::forward<T>(text));
    const size_type prefix_size = std::size(_prefix);
    const size_type midfix_size = std::size(title_text);
    const size_type suffix_size = std::size(_suffix);
    const size_type affixes_size = prefix_size + midfix_size + suffix_size;
    const size_type difference = _width - affixes_size;
    const size_type half = difference / two;
    const size_type is_odd = (_width - affixes_size) % two != zero;
    string result(_width, char_type{});
    auto it = std::begin(result);
    assert(affixes_size <= _width);

    // Make separator with title
    if (!std::empty(title_text)) {
        it = std::copy(std::begin(_prefix), std::end(_prefix), it);
        if (affixes_size < _width) {
            std::fill_n(it, half + is_odd, _symbol);
            std::advance(it, half + is_odd);
        }
        it = std::copy(std::begin(title_text), std::end(title_text), it);
        if (affixes_size < _width) {
            std::fill_n(it, half, _symbol);
            std::advance(it, half);
        }
        it = std::copy(std::begin(_suffix), std::end(_suffix), it);
    }

    // Finalization
    return !std::empty(title_text) ? result : (*this)();
}
// -------------------------------------------------------------------------- //



// ------------------------- SEPARATOR: PROPERTIES -------------------------- //
// Returns the separator prefix
template <Callable Titler, Container String, Constant Width>
constexpr typename separator<Titler, String, Width>::string
separator<Titler, String, Width>::prefix(
) const
{
    return _prefix;
}

// Returns the separator symbol
template <Callable Titler, Container String, Constant Width>
constexpr typename separator<Titler, String, Width>::char_type
separator<Titler, String, Width>::symbol(
) const
{
    return _symbol;
}

// Returns the separator suffix
template <Callable Titler, Container String, Constant Width>
constexpr typename separator<Titler, String, Width>::string
separator<Titler, String, Width>::suffix(
) const
{
    return _suffix;
}

// Returns the separator titler, which produces a title from a string
template <Callable Titler, Container String, Constant Width>
constexpr typename separator<Titler, String, Width>::titler_type
separator<Titler, String, Width>::titler(
) const
{
    return _titler;
}

// Returns the separator width
template <Callable Titler, Container String, Constant Width>
constexpr typename separator<Titler, String, Width>::size_type
separator<Titler, String, Width>::width(
) const
{
    return _width;
}

// Returns a title using the titler if the text is not empty
template <Callable Titler, Container String, Constant Width>
template <class T>
constexpr typename separator<Titler, String, Width>::string
separator<Titler, String, Width>::title(
    T&& text
) const
{
    using result_type = std::invoke_result_t<titler_type, T&&>;
    result_type result = _titler(std::forward<T>(text));
    return string(!std::empty(text) ? result : result_type{});
}
// -------------------------------------------------------------------------- //



// ------------------------- SEPARATOR: NON-MEMBERS ------------------------- //
// Outputs a separator to an output stream
template <class... Args>
std::ostream& operator<<(
    std::ostream& os,
    const separator<Args...>& sep
)
{
    return os << sep();
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _SEPARATOR_HPP_INCLUDED
// ========================================================================== //
