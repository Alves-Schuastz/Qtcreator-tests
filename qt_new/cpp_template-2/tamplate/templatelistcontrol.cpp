#include "templatelistcontrol.h"

#include <QDebug>

TemplateListControl::TemplateListControl( QObject* parent ) :
    _inteiros( {} ),
    _textos( {} ),
    _decimais( {} ) {

    qInfo() << "TemplateListControl::TemplateListControl";

}

QList<int> TemplateListControl::inteiros() const {
    return _inteiros;
}

void TemplateListControl::setInteiros( const QList<int>& inteiros ) {

    if ( _inteiros == inteiros ) {
        return;
    }

    _inteiros = inteiros;
    emit inteirosChanged();

}

void TemplateListControl::carregarValoresIniciais() {

    qInfo() << "TemplateListControl::carregarValoresIniciais";

    setInteiros( { 1, 42, 8, 2, 30, 5 } );
    setDecimais( { 6.0, 45.4, 1.4, 0.5 } );
    setTextos( { "Zé", "Maria", "Antoino", "Ana", "Joao" } );

    qInfo() << "TemplateListControl::carregarValoresIniciais";
    TemplateListControl::ordenarValores();
}


void TemplateListControl::ordenarValores() {

    qInfo() << "TemplateListControl::atualizarValores";

    // TODO #1 ordenar valores usando template e std::sort

    setInteiros( ordenacao<int>(_inteiros));
    setTextos(ordenacao<QString>(_textos));
    setDecimais(ordenacao<double>(_decimais));

    // TODO #2 Exibir em log cada valor da lista, se inteiro exibir uma mensagem diferente

    qInfo() << "TemplateListControl::atualizarValores";
}


template<typename T>
QList<T> TemplateListControl::ordenacao(QList<T> &item) {
    qInfo() << "TemplateListControl::ordenarInteiros";

    QList<T> int_lista = item;
    // Usando std::sort para ordenar a lista de inteiros
    std::sort(int_lista.begin(), int_lista.end());

    // Emitir o sinal de que os inteiros mudaram


    qInfo() << "Inteiros ordenados:";
    for (const auto& valor : int_lista) {
        qInfo() << valor;
    }
    return int_lista;
}

QList<double> TemplateListControl::decimais() const {
    return _decimais;
}

void TemplateListControl::setDecimais( const QList<double>& decimais ) {
    if ( _decimais == decimais ) {
        return;
    }

    _decimais = decimais;
    emit decimaisChanged();
}

QList<QString> TemplateListControl::textos() const {
    return _textos;
}

void TemplateListControl::setTextos( const QList<QString>& textos ) {

    if ( _textos == textos ) {
        return;
    }

    _textos = textos;
    emit textosChanged();

}
