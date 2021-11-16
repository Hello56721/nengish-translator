#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Mode.hpp"
#include "Options.hpp"
#include "InvalidUsageException.hpp"
#include "CommandLine.hpp"

int myMain(int argc, char** argv)
{
    std::vector<std::string> commandLineArguments;
    for (int i = 0; i < argc; i++)
    {
        commandLineArguments.push_back(argv[i]);
    }
    
    Options options = processCommandLineArguments(commandLineArguments);
    
    return 0;
}

int main(int argc, char** argv)
{
    try
    {
        myMain(argc, argv);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "[FATAL ERROR]: " << e.what() << '\n';
        return 9;
    }
    catch(const InvalidUsageException& e)
    {
        std::cout << "USAGE: " << argv[0] << " [--to-text/--to-nengish] <input_file> <output_file>\n";
        return 0;
    }
}