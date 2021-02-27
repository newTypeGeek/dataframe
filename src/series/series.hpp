#ifndef DATAFRAME_SERIES_HPP_
#define DATAFRAME_SERIES_HPP_
#include <string>
#include <vector>
#include <iterator>

template <typename DataType, typename IndexType = int>
class Series {
    private:
      std::vector<DataType> data_;
      std::vector<IndexType> index_;
      std::string name_;
      unsigned long long int size_;

      // Generate index [0, 1, 2, ... n] according to data_.size()
      std::vector<IndexType> get_default_index_from_data_size();

      // Check if two series have the same index
      bool is_same_index(const Series& series);

    public:
      Series(const std::vector<DataType>& data = {}, const std::vector<IndexType>& index = {}, std::string name = "");

      // Getter
      std::vector<DataType> values();
      std::vector<IndexType> index();
      std::string name();
      unsigned long long int size();

      // Slicer (mimic .iloc in pandas)
      Series iloc(long long int begin, long long int end);
      DataType iloc(long long int position);

      // Value iterator
      typedef typename std::vector<DataType>::iterator value_iter;
      typedef typename std::vector<DataType>::const_iterator const_value_iter;
      value_iter begin() { 
        return this->data_.begin(); 
      }
      value_iter end() {
        return this->data_.end();
      }
      const_value_iter cbegin() { 
        return this->data_.cbegin(); 
      }
      const_value_iter cend() {
        return this->data_.cend();
      }
      Series operator+(const Series& series) {
        if (this->is_same_index(series)) {
          const std::vector<DataType> data_ = this->data_ + series.values();
          return Series(data_, this->index());
        }
        throw "Two series have different index";

      }

};

// For template, we need to include definition in header
#include "series.cpp"


#endif 