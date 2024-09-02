#include <iostream>
#include "hello.h"


int main()
{
    std::string name = "vagner";

    hello().sayhello(name);

    hello().altera(name);
    return 0;
}
