#include <benchmark/benchmark.h>

static void BM_BitRotate(benchmark::State& state) {
    using container_type = std::vector<unsigned long long int>;
    using num_type = typename container_type::value_type;
    auto container_size = 100;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont = make_random_container<container_type>
                                     (container_size); 
    auto first = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto last = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    for (auto _ : state)
        bit::rotate(first + 3, first + 1111, last);
}
BENCHMARK(BM_BitRotate);


static void BM_BoolRotate(benchmark::State& state) {
    //using container_type = std::vector<bool>;
    //using num_type = typename container_type::value_type;
    //auto container_size = 400*8;
    //container_type boolcont = make_random_container<container_type>
                                     //(container_size); 
    std::vector<bool> boolcont(6400);
    auto first = boolcont.begin();
    auto last = boolcont.end();
    for (auto _ : state)
        std::rotate(first + 3, first + 1111, last);
}
BENCHMARK(BM_BoolRotate);
