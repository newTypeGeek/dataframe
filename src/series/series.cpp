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
    this->size_ = this->data_.size();
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
unsigned long long int Series<DataType, IndexType>::size() {
    return this->size_;
} 


template <typename DataType, typename IndexType>
Series<DataType, IndexType> Series<DataType, IndexType>::iloc(long long int begin, long long int end) {
     
     // Handle negative begin and end input
     // In pandas, .iloc[-3:-1] = slice from the last third index to the last index (excluded)
     if (begin < 0) {
         begin = this->size_ + begin;
     }

     if (end < 0) {
         end = this->size_ + end;
     }

    typename std::vector<DataType>::iterator data_iter_begin = this->data_.begin();
    typename std::vector<IndexType>::iterator index_iter_begin = this->index_.begin();

    // Slice the data and index (end is excluded)
    std::vector<DataType> data_sliced = std::vector<DataType>(data_iter_begin + begin, data_iter_begin + end);
    std::vector<IndexType> index_sliced = std::vector<IndexType>(index_iter_begin + begin, index_iter_begin + end);
    
     Series series_sliced(data_sliced, index_sliced, this->name_);

     return series_sliced;

}


template <typename DataType, typename IndexType>
DataType Series<DataType, IndexType>::iloc(long long int position) {
    // Handle negative indexing
     if (position < 0) {
         position = this->size_ + position;
     }

    return this->data_.at(position);
}