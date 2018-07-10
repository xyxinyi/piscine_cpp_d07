#include "ToyStory.h"

void ToyStory::tellMeAStory(std::string const& filename, Toy& toy1, bool(Toy::*func1)(std::string const&), Toy& toy2, bool(Toy::*func2)(std::string const&))
{
    std::ifstream stream;
    stream.open(filename.c_str());
    if (!stream.is_open())
        return;

    std::cout << toy1.getAscii() << std::endl << toy2.getAscii() << std::endl;

    bool btoy1 = true;
    while (stream.good())
    {
        std::string line;
        std::getline(stream, line);
        if (line.empty())
            continue;
        size_t found = line.find("picture:");
        bool ok = true;
        if (found != std::string::npos)
        {
            ok = execute(btoy1 ? toy1 : toy2, &Toy::setAscii, line.substr(found + 8));
            if (ok)
                std::cout << (btoy1 ? toy1.getAscii() : toy2.getAscii()) << std::endl;
        }
        else
            ok = execute(btoy1 ? toy1 : toy2, btoy1 ? func1 : func2, line);
        if (!ok)
            return;
        btoy1 = !btoy1;
    }
}

bool ToyStory::execute(Toy& toy, bool (Toy::*func)(std::string const& str), std::string const& str)
{
    if (!(toy.*func)(str))
    {
        Toy::Error e = toy.getLastError();
        std::cout << e.where() << ": " << e.what() << std::endl;
        return false;
    }
    return true;
}
