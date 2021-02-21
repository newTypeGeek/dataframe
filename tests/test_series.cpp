#include <iostream>
#include <vector>
#include <string>
#include "../src/series/series.hpp"

int main() {
    // How to compile and test
    // $ cd /path/to/dataframe/tests/
    // $ clang++ std=c++17 test_series.cpp
    // # ./a.out

    std::vector<double> data = {3.14, 1.27, 5.45, -13.4, 987.5, 4.234};

    Series time_series(data);

    std::cout << "Value\n";
    for (auto val : time_series.values()) {
        std::cout << val << " ";
    }
    std::cout << "\nIndex\n";
    for (auto ind : time_series.index()) {
        std::cout << ind << " ";
    }
    std::cout << "\nName\n";
    std::cout << time_series.name() << std::endl;

    std::cout << "Size\n";
    std::cout << time_series.size() << std::endl;  

    // sub-series 
    std::cout <<"===== Sub Series =====\n";
    Series sub_series = time_series.iloc(-4, -1);
    std::cout << "Value\n";
    for (auto val : sub_series.values()) {
        std::cout << val << " ";
    }
    std::cout << "\nIndex\n";
    for (auto ind : sub_series.index()) {
        std::cout << ind << " ";
    }
    std::cout << "\nName\n";
    std::cout << sub_series.name() << std::endl;

    std::cout << "Size\n";
    std::cout << sub_series.size() << std::endl;  

    return 0;
}