#ifndef _PICTURE_H_
#define _PICTURE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

class Picture
{
	public:
		Picture();
		Picture(const Picture&);
		Picture &operator=(const Picture&);
		Picture(const std::string &file);
		~Picture();
		bool getPictureFromFile(const std::string &file);
		std::string getData() const;
		std::string data;

};

#endif
