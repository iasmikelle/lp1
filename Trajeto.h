
#pragma once
#include "Cidade.h"
#include <string>

class Trajeto {
private:
    Cidade* origem;
    Cidade* destino;
    std::string tipo;
    double distancia;

public:
    Trajeto(Cidade* origem, Cidade* destino, std::string tipo, double distancia)
        : origem(origem), destino(destino), tipo(tipo), distancia(distancia) {}

    Cidade* getOrigem() const { return origem; }
    Cidade* getDestino() const { return destino; }
    std::string getTipo() const { return tipo; }
    double getDistancia() const { return distancia; }
};
