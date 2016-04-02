#include <fstream>
#include <iostream>
#include <string>

#include "rot47_stepping.h"


int main(int argc, char** argv)
{
    if (argc > 1)
    {
        for(int i=1; i<argc; ++i)
        {
            std::ifstream file(argv[i]);
            if (!file) continue;
            rot47::stepping::parse(
                    file, 
                    std::cout, 
                    rot47::stepping::Direction::None);
        }
    }
    else
    {
        rot47::stepping::parse(
                std::cin, 
                std::cout, 
                rot47::stepping::Direction::None);
    }
    return 0;
}
