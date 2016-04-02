#pragma once
#include <algorithm>
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
