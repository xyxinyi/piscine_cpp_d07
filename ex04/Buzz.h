#ifndef _BUZZ_H_
#define _BUZZ_H_

#include <string>
#include <cctype>
#include "Toy.h"

class Buzz : public Toy
{
	public:
		Buzz(std::string const &name);
		Buzz(std::string const &name, std::string const &filename);
		~Buzz();
		void speak(std::string);
};

#endif
