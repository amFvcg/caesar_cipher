#pragma once
#include <algorithm>
#include <cassert>
#include <istream>
#include <string>

#include <fcntl.h>
#include <unistd.h>


namespace rot47 {
const int SHIFT = 47;

char* c_cipher(char* buf, const size_t size, const int shift=SHIFT)
{
    char *retval = new char[size+1];
    auto evaluate = [shift](unsigned char c){
        return ((c > 32) && (c < 127)) ? 33 + ((c + shift - 33) % 94) : c;
    };
    std::transform(buf, buf + size, retval, evaluate);
    return retval;
}

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

void c_parse(int input_fd, int output_fd, bool decode=false, int shift=0)
{
    static const auto BUFFER_SIZE = 16*1024;
    assert(input_fd != -1);

    /* Advise the kernel of our access pattern.  */
    posix_fadvise(input_fd, 0, 0, POSIX_FADV_SEQUENTIAL);
    posix_fadvise(output_fd, 0, 0, POSIX_FADV_SEQUENTIAL);

    char buf[BUFFER_SIZE + 1];

    while(size_t bytes_read = read(input_fd, buf, BUFFER_SIZE))
    {
        if(bytes_read == (size_t)-1)
            break;
//            handle_error("read failed");
        if (!bytes_read)
            break;

        if (!write(output_fd, c_cipher(buf, bytes_read, decode?SHIFT-shift:SHIFT+shift), bytes_read))
            break;
    }
}

} // namespace rot47
