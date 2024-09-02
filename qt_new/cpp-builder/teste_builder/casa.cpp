#include "casa.hpp"
#include <stdexcept>

// Construtor privado da classe House
House::House(int porta, int janela, int quartos, bool telhado, bool chao, bool paredes)
    : porta(porta), janela(janela), quartos(quartos), telhado(telhado), chao(chao), paredes(paredes),
      cozinha(false), piscina(false), banheiro(false), garagem(false), jardim(false) {
    if (porta <= 0 || janela <= 0 || quartos <= 0 || !telhado || !chao || !paredes) {
        throw std::invalid_argument("Todos os atributos obrigatórios devem ser válidos.");
    }
}

// Métodos para adicionar atributos opcionais
void House::addCozinha() { cozinha = true; }
void House::addPiscina() { piscina = true; }
void House::addBanheiro() { banheiro = true; }
void House::addGaragem() { garagem = true; }
void House::addJardim() { jardim = true; }

// Método para exibir os detalhes da casa
void House::printDetails() const {
    std::cout << "House(porta=" << porta << ", janela=" << janela << ", quartos=" << quartos
              << ", telhado=" << telhado << ", chao=" << chao << ", paredes=" << paredes
              << ", cozinha=" << cozinha << ", piscina=" << piscina << ", banheiro=" << banheiro
              << ", garagem=" << garagem << ", jardim=" << jardim << ")" << std::endl;
}

// Construtor do Builder que recebe os atributos obrigatórios
HouseBuilder::HouseBuilder(int porta, int janela, int quartos, bool telhado, bool chao, bool paredes) {
    house = new House(porta, janela, quartos, telhado, chao, paredes);
}

// Métodos para adicionar os atributos opcionais
HouseBuilder& HouseBuilder::addCozinha() {
    house->addCozinha();
    return *this;
}

HouseBuilder& HouseBuilder::addPiscina() {
    house->addPiscina();
    return *this;
}

HouseBuilder& HouseBuilder::addBanheiro() {
    house->addBanheiro();
    return *this;
}

HouseBuilder& HouseBuilder::addGaragem() {
    house->addGaragem();
    return *this;
}

HouseBuilder& HouseBuilder::addJardim() {
    house->addJardim();
    return *this;
}

// Método para construir e retornar a casa
House* HouseBuilder::build() {
    return house;
}
