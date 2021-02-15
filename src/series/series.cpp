#include <string>
#include <vector>
#include <cstdio>
#include "series.hpp"


template <typename Dtype>
Series::Series(const std::vector<Dtype>& data) {
    data_ = data;

    // If no index argument is provided, use default index setting as shown below
    for (int i = 0; i < data_.size(); ++i) {
        index_.push_back(i);
    }

    // default name is empty string
    name_ = "";
}

template <typename Dtype>
Series::Series(const std::vector<Dtype>& data, std::string name) {
    data_ = data;

    // If no index argument is provided, use default index setting as shown below
    for (int i = 0; i < data_.size(); ++i) {
        index_.push_back(i);
    }

    name_ = name;
}


template <typename Dtype>
Series::Series(const std::vector<Dtype>& data, const std::vector<Dtype>& index, std::string name) {
    data_ = data;
    index_ = index;
    name_ = name;
}