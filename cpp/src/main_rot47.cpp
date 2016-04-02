#include <fstream>
#include <iostream>
#include <string>

#include "rot47.h"


int main(int argc, char** argv)
{
    if (argc > 1)
    {
        for(int i=1; i<argc; ++i)
        {
            std::ifstream file(argv[i]);
            if (!file) continue;
            rot47::parse(file, std::cout);
        }
    }
    else
    {
        rot47::parse(std::cin, std::cout);
    }
    return 0;
}
