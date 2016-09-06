#include <fstream>
#include <iostream>
#include <string>

#include <fcntl.h>

#include <boost/program_options.hpp>

#include "rot47.h"

struct Options
{
    unsigned int shift;
    bool decode;
    std::vector<std::string> input_files;
    std::string help;
    std::string version;
    bool cstyle;
};

Options parser(int ac, char** av)
{
    Options options;
        using namespace boost::program_options;
        options_description desc("Allowed options");

        desc.add_options()
            ("version,v", "prints version")
            ("help,h", "produce help message")
            ("shift,s", value<unsigned int>(&options.shift)->default_value(0))
            ("decode,d", bool_switch(&options.decode)->default_value(false), "")
            ("cstyle,c", bool_switch(&options.cstyle)->default_value(false), "")
            ("input-file", value<std::vector<std::string> >(&options.input_files), "input file")
        ;

        positional_options_description pos;
        pos.add("input-file", -1);

        variables_map vm;
        store(command_line_parser(ac, av).
                options(desc).positional(pos).run(), vm);
        notify(vm);

        if (vm.count("help"))
        {
            std::stringstream ss;
            ss << desc;
            options.help = ss.str();
        }

        if (vm.count("version"))
        {
            options.version = "0.1.0";
        }

        return options;
}


int main(int ac, char** av)
{
    auto options = parser(ac, av);
    if (options.help.length())
    {
        std::cout << options.help << std::endl;
        return 1;
    }

    if (options.version.length())
    {
        std::cout << options.version << std::endl;
        return 1;
    }

    if (options.input_files.size() > 0)
    {
        std::for_each(
                options.input_files.begin(),
                options.input_files.end(),
                [&options](const std::string& file_name){
                    if (options.cstyle) {
                        int in_fd = open(file_name.c_str(), O_RDONLY);
                        if (in_fd != -1) {
                            rot47::c_parse(in_fd, STDOUT_FILENO, options.decode, options.shift);
                            close(in_fd);
                        }

                    }
                    else {
                        std::ifstream file(file_name);
                        if (file)
                        rot47::parse(file, std::cout, options.decode, options.shift);
                    }
                }
        );
    }
    else
    {
        rot47::parse(std::cin, std::cout, options.decode, options.shift);
    }
    return 0;
}
