// ================================ NAMELIST ================================ //
// Project:         The Experimental Bit Algorithms Library
// Name:            namelist.hpp
// Description:     A list of parameters and values loadable from files
// Creator:         Vincent Reverdy
// Contributor(s):  Vincent Reverdy [2015-2017]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _NAMELIST_HPP_INCLUDED
#define _NAMELIST_HPP_INCLUDED
// ========================================================================== //



// ================================ PREAMBLE ================================ //
// C++ standard library
#include <istream>
#include <ostream>
#include <utility>
#include <filesystem>
#include <type_traits>
// Project sources
// Third-party libraries
// Miscellaneous
// ========================================================================== //



/* ******************************** NAMELIST ******************************** */
// Namelist class definition
template <
    class String = std::string,
    class Map = std::unordered_map<String, String>
>
class namelist
{
    // Types
    public:
    using string = String;
    using map = Map
    using char_type = typename string::traits::char_type;
    using key_type = typename map_type::key_type;
    using mapped_type = typename map_type::mapped_type;
    using value_type = typename map_type::value_type;
    using size_type = typename map_type::size_type;
    using difference_type = typename map_type::difference_type;
    using key_compare = typename map_type::key_compare;
    using allocator_type = typename map_type::allocator_type;
    using reference = typename map_type::reference;
    using const_reference = typename map_type::const_reference;
    using pointer = typename map_type::pointer;
    using const_pointer = typename map_type::const_pointer;
    using iterator = typename map_type::iterator;
    using const_iterator = typename map_type::const_iterator;
    using reverse_iterator = typename map_type::reverse_iterator;
    using const_reverse_iterator = typename map_type::const_reverse_iterator;
    using path = std::filesystem::path;
    using regex = std::regex<char_type>;
    using istream = std::basic_istream<char_type>;
    using ostream = std::basic_ostream<char_type>;

    // Load and save
    public:
    bool load(const path& p, const regex& separator, const regex& linebreak);

    // Element access
    public:
    constexpr mapped_type& at(const key_type& key);
    constexpr const mapped_type& at(const key_type& key) const;
    constexpr mapped_type& operator[](const key_type& key);
    constexpr const mapped_type& operator[](const key_type& key) const;

    // Iterators
    public:
    constexpr iterator begin() noexcept;
    constexpr const_iterator begin() const noexcept;
    constexpr const_iterator cbegin() const noexcept;
    constexpr iterator end() noexcept;
    constexpr const_iterator end() const noexcept;
    constexpr const_iterator cend() const noexcept;
    constexpr reverse_iterator rbegin() noexcept;
    constexpr const_reverse_iterator rbegin() const noexcept;
    constexpr const_reverse_iterator crbegin() const noexcept;
    constexpr reverse_iterator rend() noexcept;
    constexpr const_reverse_iterator rend() const noexcept;
    constexpr const_reverse_iterator crend() const noexcept;

    // Capacity
    public:
    constexpr bool empty() const noexcept;
    constexpr size_type size() const noexcept;
    constexpr size_type max_size() const noexcept;

    // Modifiers
    public:
    constexpr void clear() noexcept;

    // Implementation details: data members
    private:
    map _map;
};
/* ************************************************************************** */



// ------------------------- NAMELIST: LOAD AND SAVE ------------------------ //
// Loads parameters from a file with the specified separator and linebreak
template <class String, class Map>
bool namelist<String, Map>::load(
    const path& p,
    const regex& separator,
    const regex& linebreak
)
{
    // Initialization
    bool success = false;

    /* TO BE DONE:
     * imagine a parameter file of the type:
     * 
     * first_parameter = this_is_a_string
     * second_parameter = 2.0
     * third_parameter = 1
     * fourth = this is another string
     *
     * This function should open the file, look for the first linebreak
     * specified by the regex, extract what is before the linebreak,
     * break the string into a key/value pair using the separator regex
     * and then adds the key/value pair to the _map data member.
    */

    // Finalization
    return success;
}
// -------------------------------------------------------------------------- //



// --------------------------- NAMELIST: ITERATORS -------------------------- //
// Returns an iterator to the beginning of the namelist
template <class String, class Map>
constexpr iterator namelist<String, Map>::begin(
) noexcept
{
    return std::begin(_map);
}

// Returns a constant iterator to the beginning of the namelist
template <class String, class Map>
constexpr const_iterator namelist<String, Map>::begin(
) const noexcept
{
    return std::begin(_map);
}

// Returns a constant iterator to the beginning of the namelist
template <class String, class Map>
constexpr const_iterator namelist<String, Map>::cbegin(
) const noexcept
{
    return std::cbegin(_map);
}

// Returns an iterator to the end of the namelist
template <class String, class Map>
constexpr iterator namelist<String, Map>::end(
) noexcept
{
    return std::end(_map);
}

// Returns a constant iterator to the end of the namelist
template <class String, class Map>
constexpr const_iterator namelist<String, Map>::end(
) const noexcept
{
    return std::end(_map);
}

// Returns a constant iterator to the end of the namelist
template <class String, class Map>
constexpr const_iterator namelist<String, Map>::cend(
) const noexcept
{
    return std::cend(_map);
}

// Returns an iterator to the beginning of the reversed namelist
template <class String, class Map>
constexpr reverse_iterator namelist<String, Map>::rbegin(
) noexcept
{
    return std::rbegin(_map);
}

// Returns a constant iterator to the beginning of the reversed namelist
template <class String, class Map>
constexpr const_reverse_iterator namelist<String, Map>::rbegin(
) const noexcept
{
    return std::rbegin(_map);
}

// Returns a constant iterator to the beginning of the reversed namelist
template <class String, class Map>
constexpr const_reverse_iterator namelist<String, Map>::crbegin(
) const noexcept
{
    return std::crbegin(_map);
}

// Returns an iterator to the end of the reversed namelist
template <class String, class Map>
constexpr reverse_iterator namelist<String, Map>::rend(
) noexcept
{
    return std::rend(_map);
}

// Returns a constant iterator to the end of the reversed namelist
template <class String, class Map>
constexpr const_reverse_iterator namelist<String, Map>::rend(
) const noexcept
{
    return std::rend(_map);
}

// Returns a constant iterator to the end of the reversed namelist
template <class String, class Map>
constexpr const_reverse_iterator namelist<String, Map>::crend(
) const noexcept
{
    return std::crend(_map);
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _NAMELIST_HPP_INCLUDED
// ========================================================================== //
