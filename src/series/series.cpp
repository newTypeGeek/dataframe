#include <string>
#include <vector>
#include "series.hpp"

Series::Series(std::vector<double> data, std::vector<std::string> index, std::string name) {
    data_ = data;
    index_ = index;
    name_ = name;
}

double Series::sum() {
    double total = 0.;
    for (double value : data_) {
        total += value;
    }
    return total;
}