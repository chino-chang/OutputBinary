#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

class outputBinary
{
#define HEX_MANIPULATE(x) std::right << std::hex << std::setw(2) << std::setfill('0') <<  (x & 0x000000FF)

#define INPUT_ERROR "The input filepath can't read. Please re-confirm filepath."

#define OUTPUT_ERROR "The output filepath can't write. please re-confirm filepath."

public:
    /**
        This module outputs binary data of file to a console.
        @param inputPath Input.
        @throws ioexception
    */
    static void outputToConsole(std::string inputPath);

    /**
        This module outputs binary data of file to the external file.
        @param inputPath Input
        @param outputPath Output
        @throws ioexception
    */
    static void outputToExternal(std::string inputPath, std::string outputPath);

private:
    /**
        This variable@defines the maximum number of columns to be output
    */
    static const int MaxColumn = 16;
};
