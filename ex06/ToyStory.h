#ifndef _TOYSTORY_H
#define _TOYSTORY_H

#include <string>
#include "Toy.h"

class ToyStory {
private:

public:
    static void tellMeAStory(std::string const &fileName,
                      Toy &toy1, bool (Toy::*func1)(std::string const &str),
                      Toy &toy2, bool (Toy::*func2)(std::string const &str));
};


#endif 
