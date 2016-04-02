#include <fstream>
#include <iostream>
#include <string>

#include "rot47.h"


int main(int argc, char** argv)
{
    auto parser = [](std::istream& stream){
        std::string line;
        while (std::getline(stream, line))
        {
            std::cout << rot47::cipher(line) << std::endl;
        }
    };
    if (argc > 1)
    {
        for(int i=1; i<argc; ++i)
        {
            std::ifstream file(argv[i]);
            if (!file) continue;
            parser(file);
        }
    }
    else
    {
        parser(std::cin);
    }
    return 0;
}
