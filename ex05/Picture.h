#ifndef PICTURE_H_
# define PICTURE_H_

#include <iostream>
# include <string>
class Picture{
  std::string _data;
 public:
  bool getPictureFromFile(const std::string &s);
  Picture(const std::string &fn);
  std::string getData() const{
    return _data;
  };
  void setData(std::string s){
    _data = s;
  }
  Picture();
  Picture(const Picture &a);
  ~Picture();
  Picture operator=(const Picture &a);
};

#endif /* Watson */
