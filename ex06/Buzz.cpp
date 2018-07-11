#include <iostream>
#include "Buzz.h"

bool Buzz::speak(std::string const &text) {
    std::cout << "BUZZ: ";
    return Toy::speak(text);
}

bool Buzz::speak_es(std::string const &text) {
    std::cout << getName() << " senorita \"" << text << "\" senorita" << std::endl;
    return true;
}
