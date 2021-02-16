#ifndef DATAFRAME_SERIES_HPP_
#define DATAFRAME_SERIES_HPP_
#include <string>
#include <vector>
#include <iostream>

template <class Dtype>
class Series {
    private:
      std::vector<Dtype> data_;
      std::vector<Dtype> index_;
      std::string name_;

      // set index_ to [0, 1, 2, ..., data.size()]
      void set_default_index(const std::vector<Dtype>& data);
    
    public:
      Series(const std::vector<Dtype>& data, const std::vector<Dtype>& index, std::string name);
      Series(const std::vector<Dtype>& data, std::string name);
      Series(const std::vector<Dtype>& data);

      // Getter
      std::vector<Dtype> values();
      std::vector<Dtype> index();
      std::string name();

      // Slicer (mimic .iloc in pandas)
      Series iloc(u_long begin, u_long end);
      

};
#endif