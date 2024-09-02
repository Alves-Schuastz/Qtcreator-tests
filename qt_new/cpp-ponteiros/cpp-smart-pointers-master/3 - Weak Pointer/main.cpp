#include <QCoreApplication>

#include <QDebug>

#include <memory>

class Carro {
public:
    void buzinar() {
        qInfo() << "bi-bi-bi";
    }
};

int main( int argc, char* argv[] ) {
    QCoreApplication a( argc, argv );

    {
        std::weak_ptr<Carro> weak;

        {
            std::shared_ptr<Carro> shared = std::make_shared<Carro>();
            weak = shared;

            if ( auto sharedFromWeak = weak.lock() ) {
                sharedFromWeak->buzinar();
                qInfo() << "Contagem de usos compartilhados [USE_COUNT]" << sharedFromWeak.use_count();
            }

        }

        // Shared sai do escopo e o objeto Carro é destruído

        if ( auto sharedFromWeak = weak.lock() ) {
            // Este bloco não será executado porque o objeto foi destruído
        }else {
            qInfo() << "O objeto foi destruído";
        }

    }

    {
        std::weak_ptr<Carro> weak;

        {
            std::shared_ptr<Carro> shared = std::make_shared<Carro>();
            weak = shared;

            if ( auto sharedFromWeak = weak.lock() ) {
                sharedFromWeak->buzinar();
                qInfo() << "Contagem de usos compartilhados [USE_COUNT]" << sharedFromWeak.use_count();
            }

        }

        // Shared sai do escopo e o objeto Carro é destruído

        if ( !weak.expired() ) {
            // Este bloco não será executado porque o objeto foi destruído
        }else {
            qInfo() << "O objeto foi destruído";
        }

    }

    return a.exec();
}
