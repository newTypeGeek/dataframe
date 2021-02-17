#ifndef DATAFRAME_SERIES_HPP_
#define DATAFRAME_SERIES_HPP_
#include <string>
#include <vector>
#include <iostream>

template <typename DataType>
class Series {
    private:
      std::vector<DataType> data_;
      std::vector<DataType> index_;
      std::string name_;

      // set index_ to [0, 1, 2, ..., data.size()]
      void set_default_index(const std::vector<DataType>& data);
    
    public:
      Series(const std::vector<DataType>& data, const std::vector<DataType>& index, std::string name);
      Series(const std::vector<DataType>& data, std::string name);
      Series(const std::vector<DataType>& data);

      // Getter
      std::vector<DataType> values();
      std::vector<DataType> index();
      std::string name();

      // Slicer (mimic .iloc in pandas)
      Series iloc(u_long begin, u_long end);
      

};
#endif