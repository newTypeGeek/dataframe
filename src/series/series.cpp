#include <string>
#include <vector>
#include <cstdio>
#include "series.hpp"


template <typename DataType>
void Series<DataType>::set_default_index(const std::vector<DataType>& data) {
    for (int i = 0; i < data.size(); ++i) {
        this->index_.push_back(i);
    }
}


template <typename DataType>
Series<DataType>::Series(const std::vector<DataType>& data, const std::vector<DataType>& index, std::string name) {
    this->data_ = data;
    this->index_ = index;
    this->name_ = name;
}

template <typename DataType>
Series<DataType>::Series(const std::vector<DataType>& data, std::string name) {
    this->data_ = data;
    this->name_ = name;
    this->set_default_index(data);
}

template <typename DataType>
Series<DataType>::Series(const std::vector<DataType>& data) {
    this->data_ = data;
    this->name_ = "";
    this->set_default_index(data);
}

template <typename DataType>
std::vector<DataType> Series<DataType>::values() {
    return this->data_;
}

template <typename DataType>
std::vector<DataType> Series<DataType>::index() {
    return this->index_;
}

template <typename DataType>
std::string Series<DataType>::name() {
    return this->name_;
}

template <typename DataType>
Series<DataType> Series<DataType>::iloc(u_long begin, u_long end) {

    typename std::vector<DataType>::iterator data_iter_begin = this->data_.begin();
    typename std::vector<DataType>::iterator index_iter_begin = this->index_.begin();

    // Slice the data and index (end is excluded)
    std::vector<DataType> data_sliced = std::vector<DataType>(data_iter_begin + begin, data_iter_begin + end);
    std::vector<DataType> index_sliced = std::vector<DataType>(index_iter_begin + begin, index_iter_begin + end);

    return Series(data_sliced, index_sliced, this->name_);

}