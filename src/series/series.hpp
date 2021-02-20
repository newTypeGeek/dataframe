#ifndef DATAFRAME_SERIES_HPP_
#define DATAFRAME_SERIES_HPP_
#include <string>
#include <vector>

template <typename DataType, typename IndexType = int>
class Series {
    private:
      std::vector<DataType> data_;
      std::vector<IndexType> index_;
      std::string name_;
    
    public:
      Series(const std::vector<DataType>& data = {}, const std::vector<IndexType>& index = {}, std::string name = "");

      // Getter
      std::vector<DataType> values();
      std::vector<IndexType> index();
      std::string name();

      // Slicer (mimic .iloc in pandas)
      Series iloc(u_long begin, u_long end);
    
    protected:
      // Generate index [0, 1, 2, ... n] according to data_.size()
      std::vector<IndexType> get_default_index_from_data_size();
      

};

// For template, we need to include definition in header
#include "series.cpp"


#endif 