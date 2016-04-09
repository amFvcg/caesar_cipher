#pragma once
#include <algorithm>
#include <istream>
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

void parse(std::istream& input, std::ostream& output, bool decode=false, int shift=0)
{
    std::string line;
    while (std::getline(input, line))
    {
            output << rot47::cipher(line, decode?SHIFT-shift:SHIFT+shift);
            if (!input.eof())
            {
                output << '\n';
            }
    }
}

} // namespace rot47
