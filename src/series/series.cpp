#include <string>
#include <vector>
#include <cassert>
#include "series.hpp"


template <typename DataType, typename IndexType>
std::vector<IndexType> Series<DataType, IndexType>::get_default_index_from_data_size() {
    std::vector<IndexType> index;
    for (int i = 0; i < this->data_.size(); ++i) {
        index.push_back(i);
    }
    return index;
}


template <typename DataType, typename IndexType>
Series<DataType, IndexType>::Series(const std::vector<DataType>& data, const std::vector<IndexType>& index, std::string name) {
    this->data_ = data;

    int data_size = this->data_.size();
    int index_size = index.size();

    if (index_size == 0) { // TODO: use optional instead
        this->index_ = this->get_default_index_from_data_size();
    } else if (index_size != data_size) {
        assert(index_size == data_size);
    } else {
        this->index_ = index;
    }
    this->name_ = name;
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
Series<DataType, IndexType> Series<DataType, IndexType>::iloc(unsigned long long int begin, unsigned long long int end) {

    typename std::vector<DataType>::iterator data_iter_begin = this->data_.begin();
    typename std::vector<IndexType>::iterator index_iter_begin = this->index_.begin();

    // Slice the data and index (end is excluded)
    std::vector<DataType> data_sliced = std::vector<DataType>(data_iter_begin + begin, data_iter_begin + end);
    std::vector<IndexType> index_sliced = std::vector<IndexType>(index_iter_begin + begin, index_iter_begin + end);
    
     Series series_sliced(data_sliced, index_sliced, this->name_);

     return series_sliced;

}