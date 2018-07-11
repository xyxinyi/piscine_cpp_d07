#include <iostream>
#include "Toy.h"

std::string const Toy::Error::wheres[3] = {
        "",
        "setAscii",
        "speak_es"
};

std::string const Toy::Error::whats[3] = {
        "",
        "bad new illustration",
        "wrong mode"
};

Toy::Error const Toy::Error::error_unknown = Toy::Error(Toy::Error::UNKNOWN);
Toy::Error const Toy::Error::error_picture = Toy::Error(Toy::Error::PICTURE);
Toy::Error const Toy::Error::error_speak = Toy::Error(Toy::Error::SPEAK);

Toy::Error::~Error()
{}

/** end singletons **/

Toy& Toy::operator=(Toy const &alt) {
    _name = alt.getName();
    _picture = Picture();
    _picture._data = alt.getAscii();
    _type = alt.getType();
    _error = alt.getLastError();
    return *this;
}


std::ostream &operator<<(std::ostream &stream, Toy const &obj) {
    stream << obj.getName() << std::endl;
    stream << obj.getAscii() << std::endl;
    return stream;
}

Toy::Error const &Toy::getLastError() const {
    return _error;
}

std::string const &Toy::Error::what() const {
    return whats[type];
}

std::string const &Toy::Error::where() const {
    return wheres[type];
}

Toy &Toy::operator<<(std::string const &obj) {
    _picture._data = std::string(obj);
    return *this;
}

bool Toy::speak(std::string const &text) {
    std::cout << _name << " \"" << text << "\"" << std::endl;
    return true;
}

bool Toy::speak_es(std::string const &text) {
    (void) text;
    _error = Toy::Error::error_speak;
    return false;
}

bool Toy::setAscii(std::string const &name) {
    if (!_picture.getPictureFromFile(name)) {
        _error = Error::error_picture;
        return false;
    }
    return true;
}

Toy::~Toy()
{
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
