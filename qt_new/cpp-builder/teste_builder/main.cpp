#include <QCoreApplication>
#include "casa.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();

    // Exemplo de uso do Builder para construir uma casa
    HouseBuilder builder(1, 4, 3, true, true, true);
    House* house = builder.addCozinha().addBanheiro().addPiscina().build();

    house->printDetails();

    // Liberação de memória
    delete house;
}
