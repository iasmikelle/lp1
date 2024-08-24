
#pragma once
#include <string>

class Cidade {
private:
    std::string nome;

public:
    Cidade(std::string nome) : nome(nome) {}
    std::string getNome() const { return nome; }
};
