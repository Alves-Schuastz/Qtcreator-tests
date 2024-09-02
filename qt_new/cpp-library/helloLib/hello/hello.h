#ifndef HELLO_H
#define HELLO_H

#include "hello_global.h"

class HELLO_EXPORT Hello
{
public:
    Hello();
    void sayHello (const QString& name);
};

#endif // HELLO_H
