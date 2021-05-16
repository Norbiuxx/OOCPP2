#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <stdexcept>

#include <string>

class myException : public std::exception
{
    public:
        myException(std::string file, int line);
        const std::string what();

    private:
        std::string error;
};


#endif // MYEXCEPTION_H
