#include <string>
#include <vector>
#include <cstdio>
#include "series.hpp"


template <typename DataType, typename IndexType>
void Series<DataType, IndexType>::set_default_index(const std::vector<IndexType>& data) {
    for (int i = 0; i < data.size(); ++i) {
        this->index_.push_back(i);
    }
}


template <typename DataType, typename IndexType>
Series<DataType, IndexType>::Series(const std::vector<DataType>& data, const std::vector<IndexType>& index, std::string name) {
    this->data_ = data;
    this->index_ = index;
    this->name_ = name;
}

template <typename DataType, typename IndexType>
Series<DataType, IndexType>::Series(const std::vector<DataType>& data, std::string name) {
    this->data_ = data;
    this->name_ = name;
    this->set_default_index(data);
}

template <typename DataType, typename IndexType>
Series<DataType, IndexType>::Series(const std::vector<DataType>& data) {
    this->data_ = data;
    this->name_ = "";
    this->set_default_index(data);
}

template <typename DataType, typename IndexType>
std::vector<DataType> Series<DataType, IndexType>::values() {
    return this->data_;
}

template <typename DataType, typename IndexType>
std::vector<IndexType> Series<DataType, IndexType>::index() {
    return this->index_;
}

template <typename DataType, typename IndexType>
std::string Series<DataType, IndexType>::name() {
    return this->name_;
}

template <typename DataType, typename IndexType>
Series<DataType, IndexType> Series<DataType, IndexType>::iloc(u_long begin, u_long end) {

    typename std::vector<DataType>::iterator data_iter_begin = this->data_.begin();
    typename std::vector<DataType>::iterator index_iter_begin = this->index_.begin();

    // Slice the data and index (end is excluded)
    std::vector<DataType> data_sliced = std::vector<DataType>(data_iter_begin + begin, data_iter_begin + end);
    std::vector<DataType> index_sliced = std::vector<DataType>(index_iter_begin + begin, index_iter_begin + end);

    return Series(data_sliced, index_sliced, this->name_);

}