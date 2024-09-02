#include "hello.h"
#include <iostream>
#include <string>

hello::hello()
{
}

void hello::sayhello (std::string name){
    std::cout <<"aaa " << name << std::endl;
}

void hello::altera(std::string name){
    name = "novo nome";
    std::cout << name;
}
