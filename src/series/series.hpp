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

      void set_default_index(const std::vector<Dtype>& data);
    
    public:
      Series(const std::vector<Dtype>& data, const std::vector<Dtype>& index, std::string name);
      Series(const std::vector<Dtype>& data, std::string name);
      Series(const std::vector<Dtype>& data);

      // head displays Series with first num_rows rows
      void head();
      void head(int num_rows);

      // tail displays Series with last num_rows rows
      void tail();
      void tail(int num_rows);

      // Getter
      std::vector<Dtype> values();
      std::vector<Dtype> index();
      std::string name();

      // sum over all values in Series if Dtype is numerical
      double sum();
};
#endif