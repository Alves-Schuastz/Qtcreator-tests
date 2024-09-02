#ifndef HELLO_H
#define HELLO_H

#include "mylibrary_global.h"
#include <string>

class MYLIBRARY_EXPORT hello
{
public:
    hello();
    void sayhello(std::string name);
    void altera(std::string name);
};

#endif // HELLO_H
