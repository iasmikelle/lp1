

#pragma once
#include "Cidade.h"
#include <string>

class Passageiro {
private:
    std::string nome;
    Cidade* localizacaoAtual;

public:
    Passageiro(std::string nome, Cidade* localizacaoAtual)
        : nome(nome), localizacaoAtual(localizacaoAtual) {}

    std::string getNome() const { return nome; }
    Cidade* getLocalizacaoAtual() const { return localizacaoAtual; }
    void setLocalizacaoAtual(Cidade* cidade) { localizacaoAtual = cidade; }
};
