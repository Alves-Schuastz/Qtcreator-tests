#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <QList>
//#include <algorithm>

class MyClass{
public:
    explicit MyClass(int n):
        _n(n){}

    int getN() const{
        return _n;
    }

private:
    int _n;
};


void processar (int value, const std::function <QString(int)>&func){
    qDebug() << func (value);
}


int main()
{
    processar(5,[](int numero) -> QString{
        return QString ("customizado: ").append(QString::number (numero) );
    });
}


void f_mult(){
    int couter = 0;
    auto increment = [couter]() mutable -> void{
        couter ++;
        std:: cout << " couter dendro do lambda:" << couter << std:: endl;
    };

    increment();
    increment();

    std::cout << "couter fora do lambda:" << couter << std::endl;
}

void find_if(){
    QList<int> numeros = {4, 34, 23,74, 1};

    auto it =std::find_if(numeros.cbegin(), numeros.cend(), [](const int numero) -> bool{
        return numero > 100;
    });

    qDebug() << "l. numero nao encontrado" << *it;

    QList <MyClass*> classes = {
        new MyClass (4),
        new MyClass (34),
        new MyClass (23)
    };

    auto it2 = std::find_if(classes.cbegin(), classes.cend(), [](const MyClass* minhaClasse) -> bool{
        return minhaClasse -> getN() > 20;
    });

    if(it2 != classes.cend()){
        qDebug() << "2. Numero encontrado:" << (*it2) ->getN();
    }
    else{
        qDebug() << "3. Não encontrado";
    }

}

void sort(){

    QList<int> numeros = {4 ,23 ,1, 74, 34};

    qDebug() << "original: " << numeros;

    std::sort(numeros.begin(), numeros.end());{
        qDebug() << "crescente:" << numeros;
    }


    std::sort(numeros.begin(), numeros.end(), [](int a, int b) -> bool{
        return a > b;
    });

    qDebug() << "Decrescente:"  << numeros;
}
