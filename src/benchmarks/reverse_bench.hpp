#include <benchmark/benchmark.h>

enum Alignment {unaligned = 0, aligned = 1};

int unaligned_t = 1;
auto BM_BitReverse = [](benchmark::State& state, auto input) {
    using container_type = typename std::tuple_element<0, decltype(input)>::type;
    using word_type = typename std::tuple_element<1, decltype(input)>::type;
    unsigned int total_bits = std::get<2>(input);
    auto digits = bit::binary_digits<word_type>::value;
    auto container_size = total_bits / digits;
    container_type bitcont = make_random_container<container_type>(container_size); 
    auto first = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto last = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    for (auto _ : state)
        bit::reverse(first, last);
};

auto BM_BitReverse_UU = [](benchmark::State& state, auto input) {
    using container_type = typename std::tuple_element<0, decltype(input)>::type;
    using word_type = typename std::tuple_element<1, decltype(input)>::type;
    unsigned int total_bits = std::get<2>(input);
    auto digits = bit::binary_digits<word_type>::value;
    auto container_size = total_bits / digits;
    container_type bitcont = make_random_container<container_type>(container_size); 
    auto first = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto last = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    for (auto _ : state)
        bit::reverse(first + 2, last - 3);
};

auto BM_BoolReverse = [](benchmark::State& state, auto input) {
    using container_type = std::vector<bool>;
    using num_type = typename container_type::value_type;
    unsigned int container_size = std::get<2>(input);
    container_type cont = make_random_container<container_type>(container_size); 
    auto first = cont.begin();
    auto last = cont.end();
    for (auto _ : state)
        std::reverse(first, last);
};