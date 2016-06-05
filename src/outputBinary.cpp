/**
    This class implements outputbinary.hpp.
    These module outpus a binary data.
    @author chino-chang
*/
#include "outputBinary.hpp"

void outputBinary::outputToConsole(std::string inputPath)
{
    std::ifstream stream{ inputPath, std::ios::in | std::ios::binary };
    if (!stream.is_open())
    {
        throw std::runtime_error{ INPUT_ERROR };
    }

    int column = 1;
    while (!stream.eof())
    {
        const char SPACE = ' ';
        char x;
        stream.read(&x, sizeof(char));
        std::cout << HEX_MANIPULATE(x);
        if (column == MaxColumn)
        {
            std::cout << std::endl;
            column = 1;
        }
        else
        {
            std::cout << ' ';
            column++;
        }
    }

    stream.close();
}

void outputBinary::outputToExternal(std::string inputPath, std::string outputPath)
{
    std::ifstream ifstream{ inputPath, std::ios::in | std::ios::binary };
    if (!ifstream.is_open())
    {
        throw std::runtime_error{ INPUT_ERROR };
    }

    std::ofstream ofstream{ outputPath };
    if (!ofstream.is_open())
    {
        ifstream.close();
        throw std::runtime_error{ OUTPUT_ERROR };
    }

    int column = 1;
    while (!ifstream.eof())
    {
        char x;
        ifstream.read(&x, sizeof(char));
        ofstream << HEX_MANIPULATE(x);
        
        if (column == MaxColumn)
        {
            ofstream << std::endl;
            column = 1;
        }
        else
        {
            ofstream << ' ';
            column++;
        }
    }

    ifstream.close();
    ofstream.close();
}
