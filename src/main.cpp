/**
    This software outputs binary data of input data.
    It supports console-output and externalfile-output.
    It　requires command-line parameter.
    
    "
    first parameter is path of input file.
    second parameter is path of output file.
    "
    
    if you don't want to output externalfile, you don't need to enter second parameter.
    
    @author chino-chang
*/
#include "outputBinary.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "" << std::endl;
        return -1;
    }

    try
    {
        if (argc == 2)
        {
            outputBinary::outputToConsole(argv[1]);
        }
        else
        {
            outputBinary::outputToExternal(argv[1], argv[2]);
        }
    }
    catch (std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }

    return 0;
}
