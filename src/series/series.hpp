#ifndef SERIES_HPP
#define SERIES_HPP
#include <string>
#include <vector>

class Series {
    private:
      // TODO: create template class for data and index to accept dynamic type
      std::vector<double> data_;
      std::vector<std::string> index_;
      std::string name_;
    
    public:
      Series(std::vector<double> data, std::vector<std::string> index, std::string name);

      // temporary method for testing
      double sum();
};
#endif