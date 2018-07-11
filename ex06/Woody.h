#ifndef _WOODY_H
#define _WOODY_H


#include "Toy.h"

class Woody : public Toy {
public:
    explicit Woody(std::string const &name, std::string const &fileName = "woody.txt")
            : Toy(WOODY, name, fileName) {}
    bool speak(std::string const &text);
};


#endif 
