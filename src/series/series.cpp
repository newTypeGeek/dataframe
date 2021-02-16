#include <string>
#include <vector>
#include <cstdio>
#include "series.hpp"


template <typename Dtype>
void Series<Dtype>::set_default_index(const std::vector<Dtype>& data) {
    for (int i = 0; i < data.size(); ++i) {
        this->index_.push_back(i);
    }
}


template <typename Dtype>
Series<Dtype>::Series(const std::vector<Dtype>& data, const std::vector<Dtype>& index, std::string name) {
    this->data_ = data;
    this->index_ = index;
    this->name_ = name;
}

template <typename Dtype>
Series<Dtype>::Series(const std::vector<Dtype>& data, std::string name) {
    this->data_ = data;
    this->name_ = name;
    this->set_default_index(data);
}

template <typename Dtype>
Series<Dtype>::Series(const std::vector<Dtype>& data) {
    this->data_ = data;
    this->name_ = "";
    this->set_default_index(data);
}



