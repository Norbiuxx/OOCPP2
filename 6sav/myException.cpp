#include "myException.h"
#include <sstream>

myException::myException(std::string file, int line)
{
    std::stringstream b;
    b << "Trying to call a method without a created realisation in\nLine: " << line << "\nFile: " << file << std::endl;
    error = b.str();
}

const std::string myException::what() {
    return error;
}

