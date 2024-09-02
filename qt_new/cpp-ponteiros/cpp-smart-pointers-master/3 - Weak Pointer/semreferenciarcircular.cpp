#include <QCoreApplication>

#include <QDebug>

#include <memory>

class Carro;

class Pessoa {
public:
    std::weak_ptr<Carro> _carro;

    ~Pessoa() {
        qInfo() << "Pessoa::~Pessoa destruido";
    }
};

class Carro {
public:
    std::weak_ptr<Pessoa> _pessoa;

    ~Carro() {
        qInfo() << "Carro::~Carro destruido";
    }
};

//int main( int argc, char* argv[] ) {
//    QCoreApplication a( argc, argv );

//    {
//        std::shared_ptr<Carro> carro = std::make_shared<Carro>();
//        std::shared_ptr<Pessoa> pessoa = std::make_shared<Pessoa>();

//        carro->_pessoa = pessoa;
//        pessoa->_carro = carro;

//    }

//    return a.exec();
//}
