#pragma once
#include <iostream>
#include "Cidade.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Trajeto.h"
#include <vector>

class Viagem {
private:
    Cidade* origem;
    Cidade* destino;
    Transporte* transporte;
    std::vector<Passageiro*> passageiros;
    double horasPassadas;
    bool emAndamento;
    Trajeto* trajeto;

public:
    Viagem(Cidade* origem, Cidade* destino, Transporte* transporte, const std::vector<Passageiro*>& passageiros)
        : origem(origem), destino(destino), transporte(transporte),
          passageiros(passageiros), horasPassadas(0), emAndamento(false) {}

    void iniciarViagem() { 
        if (verificarPossibilidade()) {
            emAndamento = true;
        } else {
            std::cerr << "Transporte não está na cidade de origem.\n";
        }
    }

    void avancarHoras(double horas) {
        if (!emAndamento) {
            //std::cerr << "A viagem não está em andamento.\n";
            return;
        }

        horasPassadas += horas;
        double distanciaPercorrida = horasPassadas * transporte->getVelocidade();
        
        if (transporte->getDistanciaDescanso() > 0 && distanciaPercorrida >= transporte->getDistanciaDescanso()) {
            horasPassadas += transporte->getTempoDescanso();
        }

        double distanciaTotal = trajeto->getDistancia();
        if (distanciaPercorrida >= distanciaTotal) {
            distanciaPercorrida = distanciaTotal;
            emAndamento = false;
            transporte->setLocalizacaoAtual(destino);
            for (auto& p : passageiros) {
                p->setLocalizacaoAtual(destino);
            }
            std::cout << "Viagem concluída! Transporte e passageiros chegaram a " << destino->getNome() << ".\n";
        } else {
            std::cout << "Distância percorrida: " << distanciaPercorrida << " km. Distância restante: " << distanciaTotal - distanciaPercorrida << " km.\n";
        }
    }

    bool chegouAoDestino() const { return !emAndamento; }
    bool verificarPossibilidade() const { return transporte->getLocalizacaoAtual() == origem; }
    Cidade* getOrigem() const { return origem; }
    Cidade* getDestino() const { return destino; }
    Transporte* getTransporte() const { return transporte; }
    std::vector<Passageiro*> getPassageiros() const { return passageiros; }
};
