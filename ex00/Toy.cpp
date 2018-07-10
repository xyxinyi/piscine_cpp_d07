#include "Toy.h"

Toy::~Toy()
{
}

bool Toy::setAscii(std::string const &name) {
    return _picture.getPictureFromFile(name);
}

std::string const &Toy::getAscii() const {
    return _picture._data;
}

std::string const &Toy::getName() const {
    return _name;
}

void Toy::setName(std::string const &name) {
    _name = std::string(name);
}

Toy::ToyType const &Toy::getType() const {
    return _type;
}
