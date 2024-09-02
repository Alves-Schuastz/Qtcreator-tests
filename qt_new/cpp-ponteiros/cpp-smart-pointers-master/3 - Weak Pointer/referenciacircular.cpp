#include <QCoreApplication>

#include <QDebug>

class Pessoa;

class Carro {
public:
    std::shared_ptr<Pessoa> _pessoa;

    ~Carro() {
        qInfo() << "Carro::~Carro destruido";
    }
};

class Pessoa {
public:
    std::shared_ptr<Carro> _carro;

    ~Pessoa() {
        qInfo() << "Pessoa::~Pessoa destruido";
    }
};

//int main( int argc, char* argv[] ) {
//    QCoreApplication a( argc, argv );

//    {
//        std::shared_ptr<Carro> carro = std::make_shared<Carro>();
//        std::shared_ptr<Pessoa> pessoa = std::make_shared<Pessoa>();

//        // Estabelecendo a relação circular
//        carro->_pessoa = pessoa;
//        pessoa->_carro = carro;

//        // Ao final do escopo, tanto 'a' quanto 'b' não serão destruídos,
//        // Pois eles ainda se referenciam mutuamente.
//    }

//    return a.exec();
//}
