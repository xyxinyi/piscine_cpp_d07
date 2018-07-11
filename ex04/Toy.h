#ifndef _TOY_H_
#define _TOY_H_

#include <string>
#include <memory>
#include "Picture.h"

class Toy
{
	public:
		enum ToyType
		{
			BASIC_TOY,
			ALIEN,
			BUZZ,
			WOODY
		};
		ToyType type;

		Toy();
		Toy(const Toy&);
		Toy &operator=(const Toy&);
		Toy(ToyType ToyType, std::string const &name, std::string const &file);
		virtual ~Toy();
		int getType() const;
		std::string getName() const;
		void setName(std::string name);
		bool setAscii(std::string fileName);
		std::string getAscii() const;
		virtual void speak(std::string);
		Toy &operator<<(std::string const &put);

	private:
		std::string _name;
		Picture _picture;

};

std::ostream &operator<<(std::ostream &s, const Toy &toy);

#endif
