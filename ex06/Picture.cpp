#include "Picture.h"
#include <iostream>
#include <fstream>

Picture::Picture()
{
	_data = "";
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::string line;
    std::ifstream f(file.c_str());

    if (!f.is_open()) {
        _data = "ERROR";
        return false;
    }

    _data = std::string();
    while (getline(f, line))
        _data.append(line).append("\n");

    return true;
}
