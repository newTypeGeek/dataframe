#include <string>
#include <vector>
#include <cstdio>
#include "series.hpp"


template <typename Dtype>
void Series<Dtype>::set_default_index(std::vector<Dtype>& data) {
    for (int i = 0; i < data.size(); ++i) {
        this->index_.push_back(i);
    }
}


template <typename Dtype>
Series<Dtype>::Series(const std::vector<Dtype>& data, const std::vector<Dtype>& index, std::string name) {
    data_ = data;
    index_ = index;
    name_ = name;
}

template <typename Dtype>
Series<Dtype>::Series(const std::vector<Dtype>& data, std::string name) {
    std::vector<Dtype> index;
    for (int i = 0; i < data.size(); ++i) {
        index.push_back(i);
    }
    Series(data, index, name);
}

template <typename Dtype>
Series<Dtype>::Series(const std::vector<Dtype>& data) {
    std::string name = "";
    Series(data, name);
}



