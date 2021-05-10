#include "myException.h"
#include <sstream>

using namespace std;

myException::myException(string file, int line)
{
    stringstream b;
    b << "Trying to call a method without a created realisation in\nLine: " << line << "\nFile: " << file << endl;
    error = b.str();
}

const string myException::what() {
    return error;
}
