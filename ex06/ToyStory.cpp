#include <iostream>
#include <fstream>
#include "ToyStory.h"


void ToyStory::tellMeAStory(const std::string &file,
                            Toy &toy1, bool (Toy::*func1)(std::string const &str),
                            Toy &toy2, bool (Toy::*func2)(std::string const &str))
{
    std::cout << toy1.getAscii() << "\n" << toy2.getAscii() << std::endl;

    std::string line;
    std::ifstream f(file.c_str());

    if (!f.is_open()) {
        std::cout << "Bad Story" << std::endl;
        return;
    }

    bool first = true;
    while (getline(f, line)) {
        Toy *t = first ? &toy1 : &toy2;
        bool (Toy::*func)(std::string const &str) = first ? func1 : func2;
        (t->*func)(line);

        if (!line.compare(0, 8, "picture:")) {
            if (!t->setAscii(line.substr(8, line.length() - 1))) {
                std::cerr << t->getLastError().where() << ": " << t->getLastError().what() << std::endl;
                break;
            }
            std::cout << t->getAscii() << std::endl;
        }
        first = !first;
    }
}
