
#pragma once
#include "Cidade.h"
#include <string>

class Transporte {
private:
    std::string nome;
    std::string tipo;
    int capacidade;
    double velocidade;
    double distanciaDescanso;
    double tempoDescanso;
    Cidade* localizacaoAtual;

public:
    Transporte(std::string nome, std::string tipo, int capacidade, double velocidade,
               double distanciaDescanso, double tempoDescanso, Cidade* localizacaoAtual)
        : nome(nome), tipo(tipo), capacidade(capacidade), velocidade(velocidade),
          distanciaDescanso(distanciaDescanso), tempoDescanso(tempoDescanso),
          localizacaoAtual(localizacaoAtual) {}

    std::string getNome() const { return nome; }
    std::string getTipo() const { return tipo; }
    int getCapacidade() const { return capacidade; }
    double getVelocidade() const { return velocidade; }
    double getDistanciaDescanso() const { return distanciaDescanso; }
    double getTempoDescanso() const { return tempoDescanso; }
    Cidade* getLocalizacaoAtual() const { return localizacaoAtual; }
    void setLocalizacaoAtual(Cidade* cidade) { localizacaoAtual = cidade; }
};
