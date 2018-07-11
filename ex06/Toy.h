#ifndef _TOY_H
#define _TOY_H

#include <string>
#include "Picture.h"

class Toy {
public:

    enum ToyType {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };

    class Error {
    public:

        enum ErrorType {
            UNKNOWN = 0,
            PICTURE,
            SPEAK
        };

        ~Error();
        Error(Error const &cpy) : type(cpy.type) {};

        Error(ErrorType const _type) : type(_type) {};

        Error &operator=(Error const &alt) {
            type = alt.type;
            return *this;
        }

        ErrorType type;

        std::string const &what() const;
        std::string const &where() const;

        static Error const error_unknown;
        static Error const error_picture;
        static Error const error_speak;

    private:
        static std::string const whats[3];
        static std::string const wheres[3];
    };

    ~Toy();
    Toy(Toy const &cpy)
            : _type(cpy.getType()), _name(cpy.getName()), _picture(Picture()), _error(Error::error_unknown) {
        _picture._data = cpy.getAscii();
    };

    Toy() : _type(BASIC_TOY), _name(std::string("toy")), _picture(Picture()), _error(Error::error_unknown) {};
    Toy(ToyType const &type, std::string const &name, std::string const &fileName)
            : _type(type), _name(std::string(name)), _picture(fileName), _error(Error::error_unknown) {};
    Toy &operator=(Toy const &alt);
    Toy &operator<<(std::string const &obj);

    bool setAscii(std::string const &name);
    std::string const &getAscii() const;
    std::string const &getName() const;
    void setName(std::string const &name);
    ToyType const &getType() const;
    virtual bool speak(std::string const &text);
    virtual bool speak_es(std::string const &text);
    Error const &getLastError() const;

private:
    ToyType _type;
    std::string _name;
    Picture _picture;
    Error _error;
};

std::ostream &operator<<(std::ostream &stream, Toy const &obj);


#endif
