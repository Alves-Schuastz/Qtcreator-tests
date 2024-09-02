#ifndef CASA_HPP
#define CASA_HPP

#include <iostream>

class House {
private:
    // Atributos obrigatórios
    int porta, janela, quartos;
    bool telhado, chao, paredes;

    // Atributos opcionais
    bool cozinha, piscina, banheiro, garagem, jardim;

    // Construtor privado, acessível apenas pelo Builder
    House(int porta, int janela, int quartos, bool telhado, bool chao, bool paredes);

public:
    // Métodos para adicionar atributos opcionais
    void addCozinha();
    void addPiscina();
    void addBanheiro();
    void addGaragem();
    void addJardim();

    // Método para exibir os detalhes da casa
    void printDetails() const;

    // Declaração do Builder como classe amiga
    friend class HouseBuilder;
};

class HouseBuilder {
private:
    House* house;

public:
    // Construtor do Builder que recebe os atributos obrigatórios
    HouseBuilder(int porta, int janela, int quartos, bool telhado, bool chao, bool paredes);

    // Métodos para adicionar os atributos opcionais
    HouseBuilder& addCozinha();
    HouseBuilder& addPiscina();
    HouseBuilder& addBanheiro();
    HouseBuilder& addGaragem();
    HouseBuilder& addJardim();

    // Método para construir e retornar a casa
    House* build();
};

#endif

