#include "CommandLine.hpp"

Options processCommandLineArguments(std::vector<std::string> arguments)
{
    Options result = {};
    
    if (arguments.size() < 3)
    {
        throw InvalidUsageException {};
    }
    
    if (arguments[1] == "--to-text")
    {
        result.mode = Mode::NENGISH_TO_TEXT;
        result.inputFileName = arguments[2];
        result.outputFileName = arguments[3];
    } else if (arguments[1] == "--to-nengish")
    {
        result.mode = Mode::TEXT_TO_NENGISH;
        result.inputFileName = arguments[2];
        result.outputFileName = arguments[3];
    } else {
        result.mode = Mode::TEXT_TO_NENGISH;
        result.inputFileName = arguments[1];
        result.outputFileName = arguments[2];
    }
    
    return result;
}