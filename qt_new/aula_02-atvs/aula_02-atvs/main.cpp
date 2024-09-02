#include <QCoreApplication>
#include <iostream>
#include <QList>
#include <QDebug>
#include <string>
#include <algorithm>

///////////////////////////////////////////// ATV4 //////////////////////////////////////////////////
//bool funcao(){
//    return false;
//}

void REtetativa(std::function<bool()> func,
                std::function<void()> callback){

    int MaxTentativas = 5;
    bool verifica = false;

    for(int i =0; i<MaxTentativas; i++){
        if (func()){
            verifica = true;
            break;
        }


        }
    if(!verifica){
        callback();
    }

    }

void Mcallback(){
    qDebug() << "callback ativado!";
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    REtetativa([]()-> bool{
        return true;
    }, []()->void{
        qDebug() << "callback ativado!";
    });



    REtetativa([]()-> bool{
        return false;
    }, []() -> void{
        qDebug() << "callback ativado!";
    });

}

void atv1(){
    int valor = 5;
    auto quadrado = [](int &valor){
        return valor * valor;
    };

    std::cout << "valor é " << quadrado(valor);
}

void atv2(){
    QList<int> lista = {1, 55, 23, 69, 7};

    std::sort(lista.begin(), lista.end(), [](int a, int b) -> bool{
        return a > b;
    });

    qDebug() << "Decrescente:"  << lista;

}


void atv3(){
    QList<std::string> Slista = {"bom", "dia", "cinco", "bicicleta"};
    int count = std::count_if(Slista.begin(), Slista.end(), [](const std::string& Slista){
        return Slista.length() > 5;
    });

    qDebug() << "string com mais de 5 letras: "  << count;
}

void atv4(){

}
