#include <benchmark/benchmark.h>
#include <random>
#include <math.h>


auto BM_BitShiftLeft = [](benchmark::State& state, auto input) {
    using container_type = typename std::tuple_element<0, decltype(input)>::type;
    using word_type = typename std::tuple_element<1, decltype(input)>::type;
    unsigned int total_bits = std::get<2>(input);
    auto digits = bit::binary_digits<word_type>::value;
    auto container_size = ceil(float(total_bits) / digits);
    container_type bitcont = make_random_container<container_type>(container_size); 
    const int range_from  = 0;
    const int range_to    = total_bits - 1;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    auto first = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto last = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    for (auto _ : state) {
        benchmark::DoNotOptimize(bit::shift_left(first, last, distr(generator)));
        benchmark::ClobberMemory();
    }
};

auto BM_BitShiftLeft_UU = [](benchmark::State& state, auto input) {
    using container_type = typename std::tuple_element<0, decltype(input)>::type;
    using word_type = typename std::tuple_element<1, decltype(input)>::type;
    unsigned int total_bits = std::get<2>(input);
    auto digits = bit::binary_digits<word_type>::value;
    auto container_size = ceil(float(total_bits) / digits);
    container_type bitcont = make_random_container<container_type>(container_size); 
    const int range_from  = 2;
    const int range_to    = total_bits - 4;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    auto first = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto last = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    for (auto _ : state) {
        benchmark::DoNotOptimize(bit::shift_left(first + 2, last - 3, distr(generator)));
        benchmark::ClobberMemory();
    }
};

auto BM_BoolShiftLeft = [](benchmark::State& state, auto input) {
    using container_type = std::vector<bool>;
    using num_type = typename container_type::value_type;
    unsigned int container_size = std::get<2>(input);
    container_type cont = make_random_container<container_type>(container_size); 
    auto first = cont.begin();
    auto last = cont.end();
    const int range_from  = 0;
    const int range_to    = container_size - 1;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    for (auto _ : state) {
        benchmark::DoNotOptimize(bit::word_shift_left(first, last, distr(generator)));
        benchmark::ClobberMemory();
    }
};
