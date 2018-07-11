//
// Created by romain.pillot on 1/15/18.
//

#ifndef EX02_BUZZ_H
#define EX02_BUZZ_H


#include "Toy.h"

class Buzz : public Toy {
public:
    Buzz(std::string const &name, std::string const &fileName = "buzz.txt")
            : Toy(BUZZ, name, fileName) {}
    bool speak(std::string const &text);
    bool speak_es(std::string const &text);
};


#endif
