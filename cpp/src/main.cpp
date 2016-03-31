#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

std::string rot47(const std::string& line)
{
    std::string retval;
    auto evaluate = [](unsigned char c){
        return ((c > 32) && (c < 127)) ? 33 + ((c + 47 - 33) % 94) : c;
    };
    std::transform(line.begin(), line.end(), std::back_inserter(retval), evaluate);
    return retval;
}

int main(int argc, char** argv)
{
    auto parser = [](std::istream& stream){
        std::string line;
        while (std::getline(stream, line))
        {
            std::cout << rot47(line) << std::endl;
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
