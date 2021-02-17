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

template <typename Dtype>
std::vector<Dtype> Series<Dtype>::values() {
    return this->data_;
}

template <typename Dtype>
std::vector<Dtype> Series<Dtype>::index() {
    return this->index_;
}

template <typename Dtype>
std::string Series<Dtype>::name() {
    return this->name_;
}

template <typename Dtype>
Series<Dtype> Series<Dtype>::iloc(u_long begin, u_long end) {

    typename std::vector<Dtype>::iterator data_iter_begin = this->data_.begin();
    typename std::vector<Dtype>::iterator index_iter_begin = this->index_.begin();

    // Slice the data and index (end is excluded)
    std::vector<Dtype> data_sliced = std::vector<Dtype>(data_iter_begin + begin, data_iter_begin + end);
    std::vector<Dtype> index_sliced = std::vector<Dtype>(index_iter_begin + begin, index_iter_begin + end);

    return Series(data_sliced, index_sliced, this->name_);

}