#include <fstream>
#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include "rot47.h"

struct Options
{
    unsigned int shift;
    bool decode;
    std::vector<std::string> input_files;
    std::string help;
};

Options parser(int ac, char** av)
{
    Options options;
        using namespace boost::program_options;
        options_description desc("Allowed options");

        desc.add_options()
            ("help,h", "produce help message")
            ("shift,s", value<unsigned int>(&options.shift)->default_value(0))
            ("decode,d", "")
            ("input-file", value<std::vector<std::string> >(), "input file")
        ;

        positional_options_description pos;
        pos.add("input-file", -1);

        variables_map vm;
        store(command_line_parser(ac, av).
                options(desc).positional(pos).run(), vm);
        notify(vm);

        options.decode = vm.count("decode") > 0;

        if (vm.count("help"))
        {
            std::stringstream ss;
            ss << desc;
            options.help = ss.str();
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

    if (options.input_files.size() > 0)
    {
        std::for_each(
                options.input_files.begin(),
                options.input_files.end(),
                [&options](const std::string& file_name){
                    std::ifstream file(file_name);
                    if (file)
                    rot47::parse(file, std::cout, options.decode, options.shift);
                }
        );
    }
    else
    {
        rot47::parse(std::cin, std::cout, options.decode, options.shift);
    }
    return 0;
}
