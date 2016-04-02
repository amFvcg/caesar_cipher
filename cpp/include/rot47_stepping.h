#pragma once
#include <string>
#include <istream>

#include "rot47.h"


namespace rot47 {
namespace stepping {

enum class Direction { 
	Forward,
	Backward,
        None
};

std::string cipher(const std::string& line, int step=0, Direction direction=Direction::Forward)
{
	step = direction == Direction::Forward 
            ? step 
            : direction == Direction::Backward 
                ? -step 
                : 0;
	return rot47::cipher(line, rot47::SHIFT + step);
}


void parse(std::istream& input, std::ostream& output, Direction direction)
{
    std::string line;
    int lineNo = 0;
    while (std::getline(input, line))
    {
            output << cipher(line, ++lineNo, direction) << '\n';
    }
};

} // namespace stepping
} // namespace rot47
