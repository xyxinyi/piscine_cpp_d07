#ifndef _PICTURE_H_
#define _PICTURE_H_

#include <string>

class Picture {
public:
    Picture();
	Picture(const std::string &file);
	~Picture();
    std::string _data;
    bool getPictureFromFile(const std::string &file);
};


#endif
