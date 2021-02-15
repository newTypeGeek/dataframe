#ifndef SERIES_HPP
#define SERIES_HPP
#include <string>
#include <vector>
#include <iostream>

template <class Dtype>
class Series {
    private:
      // TODO: create template class for data and index to accept dynamic type
      std::vector<Dtype> data_;
      std::vector<Dtype> index_;
      std::string name_;
    
    public:
      Series(const std::vector<Dtype>& data);
      Series(const std::vector<Dtype>& data, std::string name);
      Series(const std::vector<Dtype>& data, const std::vector<Dtype>& index, std::string name);

      // head displays Series with first num_rows rows
      void head();
      void head(int: num_rows);

      // tail displays Series with last num_rows rows
      void tail();
      void tail(int: num_rows);

      // Getter
      std::vector<Dtype> values();
      std::vector<Dtype> index();
      std::string name();

      // sum over all values in Series if Dtype is numerical
      double sum();
};
#endif