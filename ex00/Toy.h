#ifndef _TOY_H_
#define _TOY_H_

#include <string>
#include "Picture.h"

class Toy {
public:

    enum ToyType {
        BASIC_TOY,
        ALIEN
    };

	~Toy();
    Toy() : _type(BASIC_TOY), _name(std::string("toy")) {};
    Toy(ToyType const &type, std::string const &name, std::string const &fileName)
            : _type(type), _name(std::string(name)), _picture(fileName) {};

    bool setAscii(std::string const &name);
    std::string const &getAscii() const;
    std::string const &getName() const;
    void setName(std::string const &name);
    ToyType const &getType() const;
private:
    ToyType const _type;
    std::string _name;
    Picture _picture;
};


#endif 
