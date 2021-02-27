#include <iostream>
#include <vector>
#include <string>
#include "../src/series/series.hpp"

int main() {
    // How to compile and test
    // $ cd /path/to/dataframe/tests/
    // $ clang++ std=c++17 test_series_iter.cpp
    // # ./a.out
    std::vector<double> data = {3.14, 1.27, 5.45, -13.4, 987.5, 4.234};
    Series time_series(data);

    for (auto val : time_series) {
        std::cout << val << " ";
    }
}