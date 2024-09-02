#include <QCoreApplication>

#include <QList>
#include <QDebug>
#include <memory>

class MyClass {
public:
    MyClass( int val ) :
        _value( val ) {}

    void show() const {
        qInfo() << "MyClass::show [VALUE]" << _value;
    }

private:
    int _value;
};

int main( int argc, char* argv[] ) {
    QCoreApplication a( argc, argv );

    {
        QList<std::unique_ptr<MyClass> > uniqueList;

//      QList é copy-on-write, uma estratégia usada em programação de computadores e sistemas operacionais para otimizar a cópia de dados.
//      Em vez de duplicar imediatamente todos os dados quando uma cópia é solicitada, o sistema cria uma nova referência aos dados existentes.

        uniqueList.append( std::make_unique<MyClass>( 1 ) ); // std::unique_ptr não é copiável
        uniqueList.append( std::make_unique<MyClass>( 2 ) );
        uniqueList.append( std::make_unique<MyClass>( 3 ) );

        for ( const auto& item : uniqueList ) {
            item->show();
        }
    }

    {
        QList<std::shared_ptr<MyClass> > sharedList;

        sharedList.append( std::make_shared<MyClass>( 1 ) );
        sharedList.append( std::make_shared<MyClass>( 2 ) );
        sharedList.append( std::make_shared<MyClass>( 3 ) );

        for ( const auto& item : sharedList ) {
            item->show();
        }
    }

    return a.exec();
}
