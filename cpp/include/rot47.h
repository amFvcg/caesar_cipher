#pragma once
#include <algorithm>
#include <string>


namespace rot47 {
const int SHIFT = 47;

std::string cipher(const std::string& line, const int shift=SHIFT)
{
    std::string retval;
    auto evaluate = [shift](unsigned char c){
        return ((c > 32) && (c < 127)) ? 33 + ((c + shift - 33) % 94) : c;
    };
    std::transform(line.begin(), line.end(), std::back_inserter(retval), evaluate);
    return retval;
}

} // namespace rot47
