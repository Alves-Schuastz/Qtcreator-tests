#include "hello.h"
#include <QDebug>

Hello::Hello()
{
}


void Hello::sayHello (const QString& name){
    qDebug() << QString ("hello %1").arg(name);
}
