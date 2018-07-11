#include <iostream>
#include "Woody.h"

bool Woody::speak(std::string const &text) {
    std::cout << "WOODY: ";
    return Toy::speak(text);
}
