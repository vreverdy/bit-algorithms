// ============================= BIT_ALGORITHM ============================== //
// Project:         The C++ Bit Library
// Name:            bit_algorithm.hpp
// Description:     Optimized versions of algorithms for bit manipulation
// Creator:         Vincent Reverdy
// Contributor(s):  Vincent Reverdy [2015-2017]
//                  Maghav Kumar [2016-2017]
//                  Bryce Kille [2019]
//                  Collin Gress [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _BIT_ALGORITHM_HPP_INCLUDED
#define _BIT_ALGORITHM_HPP_INCLUDED
#define _Bit_Algorithm_VERSION_MAJOR @Bit_Algorithm_VERSION_MAJOR@
#define _Bit_Algorithm_VERSION_MINOR @Bit_Algorithm_VERSION_MINOR@
#if __AVX512BW__
#   pragma message("Building with AVX512BW support")
#   define SIMDPP_ARCH_X86_AVX512BW true
#elif __AVX512DQ__
#   pragma message("Building with AVX512DQ support")
#   define SIMDPP_ARCH_X86_AVX512DQ true
#elif __AVX512VL__
#   pragma message("Building with AVX512VL support")
#   define SIMDPP_ARCH_X86_AVX512VL true
#elif __AVX512F__
#   pragma message("Building with AVX512F support")
#   define SIMDPP_ARCH_X86_AVX512DQ true
#elif __AVX2__
#   pragma message("Building with AVX2 support")
#   define SIMDPP_ARCH_X86_AVX2 true
#elif __AVX__
#   pragma message("Building with AVX support")
#   define SIMDPP_ARCH_X86_AVX true
#elif __SSE4_1__
#   pragma message("Building with SSE4.1 support")
#   define SIMDPP_ARCH_X86_SSE4_1 true
#elif __SSE3__
#   pragma message("Building with SSE3 support")
#   define SIMDPP_ARCH_X86_SSE3 true
#elif __SSE2__
#   pragma message("Building with SSE2 support")
#   define SIMDPP_ARCH_X86_SSE2 true
#else
#  pragma message("Building with no vectorization")
#endif
// ========================================================================== //



// ================================ PREAMBLE ================================ //
#include "input_container.hpp"
#include "input_iterator.hpp"
#include "debug_utils.hpp" //TODO does this belong somewhere else?
#include "bit_algorithm_details.hpp"
// <algorithm> overloads
#include "accumulate.hpp"
#include "adjacent_difference.hpp"
#include "adjacent_find.hpp"
#include "all_of.hpp"
#include "any_of.hpp"
#include "binary_search.hpp"
#include "bsearch.hpp"
#include "clamp.hpp"
#include "compare_3way.hpp"
#include "copy.hpp"
#include "copy_backward.hpp"
#include "copy_n.hpp"
#include "count.hpp"
#include "destroy.hpp"
#include "destroy_at.hpp"
#include "destroy_n.hpp"
#include "equal.hpp"
#include "equal_range.hpp"
#include "exclusive_scan.hpp"
#include "fill.hpp"
#include "fill_n.hpp"
#include "find.hpp"
#include "find_end.hpp"
#include "find_first_of.hpp"
#include "for_each.hpp"
#include "for_each_n.hpp"
#include "generate.hpp"
#include "generate_n.hpp"
#include "includes.hpp"
#include "inclusive_scan.hpp"
#include "inner_product.hpp"
#include "inplace_merge.hpp"
#include "iota.hpp"
#include "is_heap.hpp"
#include "is_heap_until.hpp"
#include "is_partitioned.hpp"
#include "is_permutation.hpp"
#include "is_sorted.hpp"
#include "is_sorted_until.hpp"
#include "iter_swap.hpp"
#include "lexicographical_compare.hpp"
#include "lexicographical_compare_3way.hpp"
#include "lower_bound.hpp"
#include "make_heap.hpp"
#include "max.hpp"
#include "max_element.hpp"
#include "merge.hpp"
#include "min.hpp"
#include "min_element.hpp"
#include "minmax.hpp"
#include "minmax_element.hpp"
#include "mismatch.hpp"
#include "move.hpp"
#include "move_backward.hpp"
#include "next_permutation.hpp"
#include "none_of.hpp"
#include "nth_element.hpp"
#include "partial_sort.hpp"
#include "partial_sort_copy.hpp"
#include "partial_sum.hpp"
#include "partition.hpp"
#include "partition_copy.hpp"
#include "partition_point.hpp"
#include "pop_head.hpp"
#include "prev_permutation.hpp"
#include "push_heap.hpp"
#include "qsort.hpp"
#include "reduce.hpp"
#include "remove.hpp"
#include "remove_copy.hpp"
#include "replace.hpp"
#include "replace_copy.hpp"
#include "reverse.hpp"
#include "reverse_copy.hpp"
#include "rotate.hpp"
#include "rotate_copy.hpp"
#include "sample.hpp"
#include "search.hpp"
#include "search_n.hpp"
#include "set_difference.hpp"
#include "set_intersection.hpp"
#include "set_symmetric_difference.hpp"
#include "set_union.hpp"
#include "shift.hpp"
#include "shuffle.hpp"
#include "sort.hpp"
#include "sort_heap.hpp"
#include "stable_partition.hpp"
#include "stable_sort.hpp"
#include "swap.hpp"
#include "swap_ranges.hpp"
#include "transform.hpp"
#include "transform_exclusive_scan.hpp"
#include "transform_inclusive_scan.hpp"
#include "transform_reduce.hpp"
#include "uninitialized_construct.hpp"
#include "uninitialized_construct_n.hpp"
#include "uninitialized_copy.hpp"
#include "uninitialized_copy_n.hpp"
#include "uninitialized_default_construct.hpp"
#include "uninitialized_default_construct_n.hpp"
#include "uninitialized_fill.hpp"
#include "uninitialized_fill_n.hpp"
#include "uninitialized_move.hpp"
#include "uninitialized_move_n.hpp"
#include "unique.hpp"
#include "unique_copy.hpp"
#include "upper_bound.hpp"
// ========================================================================== //



// ========================================================================== //
#endif // _BIT_ALGORITHM_HPP_INCLUDED
// ========================================================================== //
