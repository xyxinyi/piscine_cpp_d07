#ifndef _TOY_H_
#define _TOY_H_

#include <string>
#include <cctype>
#include "Picture.h"

class Toy
{
	public:
		enum ToyType
		{
			BASIC_TOY,
			ALIEN,
		};
		ToyType type;

		Toy();
		Toy(const Toy&);
		Toy &operator=(const Toy&);
		Toy(ToyType ToyType, std::string name, std::string file);
		~Toy();
		int getType() const;
		std::string getName() const;
		void setName(std::string name);
		bool setAscii(std::string fileName);
		std::string getAscii() const;

	private:
		std::string _name;
		Picture _picture;

};

#endif
