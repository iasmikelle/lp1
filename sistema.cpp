#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Viagem.h"

std::vector<Cidade*> cidades;
std::vector<Trajeto*> trajetos;
std::vector<Transporte*> transportes;
std::vector<Passageiro*> passageiros;
std::vector<Viagem*> viagens;

Cidade* encontrarCidadePorNome(const std::string& nome) {
    for (auto& cidade : cidades) {
        if (cidade->getNome() == nome) {
            return cidade;
        }
    }
    return nullptr;
}

Transporte* encontrarTransportePorNome(const std::string& nome) {
    for (auto& transporte : transportes) {
        if (transporte->getNome() == nome) {
            return transporte;
        }
    }
    return nullptr;
}

void cadastrarCidade() {
    std::string nome;
    std::cout << "Digite o nome da cidade: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    cidades.push_back(new Cidade(nome));
    std::cout << "Cidade '" << nome << "' cadastrada com sucesso!\n";
}

void cadastrarTrajeto() {
    std::string origemNome, destinoNome, tipo;
    double distancia;

    std::cout << "Digite o nome da cidade de origem: ";
    std::cin.ignore();
    std::getline(std::cin, origemNome);
    Cidade* origem = encontrarCidadePorNome(origemNome);
    if (!origem) {
        std::cout << "Cidade de origem não encontrada!\n";
        return;
    }

    std::cout << "Digite o nome da cidade de destino: ";
    std::getline(std::cin, destinoNome);
    Cidade* destino = encontrarCidadePorNome(destinoNome);
    if (!destino) {
        std::cout << "Cidade de destino não encontrada!\n";
        return;
    }

    std::cout << "Escolha o tipo de trajeto (1 - Terrestre, 2 - Aquático): ";
    int tipoOpcao;
    std::cin >> tipoOpcao;
    tipo = (tipoOpcao == 1) ? "Terrestre" : "Aquático";

    std::cout << "Digite a distância em km: ";
    std::cin >> distancia;

    trajetos.push_back(new Trajeto(origem, destino, tipo, distancia));
    std::cout << "Trajeto de '" << origemNome << "' para '" << destinoNome << "' cadastrado com sucesso!\n";
}

void cadastrarTransporte() {
    std::string nome, tipo;
    int capacidade;
    double velocidade, distanciaDescanso, tempoDescanso;

    std::cout << "Digite o nome do transporte: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "Escolha o tipo de transporte (1 - Terrestre, 2 - Aquático): ";
    int tipoOpcao;
    std::cin >> tipoOpcao;
    tipo = (tipoOpcao == 1) ? "Terrestre" : "Aquático";

    std::cout << "Digite a capacidade de passageiros: ";
    std::cin >> capacidade;

    std::cout << "Digite a velocidade média em km/h: ";
    std::cin >> velocidade;

    std::cout << "Digite a distância máxima entre descansos (km): ";
    std::cin >> distanciaDescanso;

    std::cout << "Digite o tempo de descanso (horas): ";
    std::cin >> tempoDescanso;

    transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distanciaDescanso, tempoDescanso, nullptr));
    std::cout << "Transporte '" << nome << "' cadastrado com sucesso!\n";
}

void cadastrarPassageiro() {
    std::string nome, cidadeNome;
    std::cout << "Digite o nome do passageiro: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "Digite a cidade onde o passageiro está: ";
    std::getline(std::cin, cidadeNome);
    Cidade* cidade = encontrarCidadePorNome(cidadeNome);
    if (!cidade) {
        std::cout << "Cidade não encontrada!\n";
        return;
    }

    passageiros.push_back(new Passageiro(nome, cidade));
    std::cout << "Passageiro '" << nome << "' cadastrado com sucesso!\n";
}

void iniciarViagem() {
    std::string origemNome, destinoNome, transporteNome;
    std::cout << "Digite a cidade de origem: ";
    std::cin.ignore();
    std::getline(std::cin, origemNome);
    Cidade* origem = encontrarCidadePorNome(origemNome);
    if (!origem) {
        std::cout << "Cidade de origem não encontrada!\n";
        return;
    }

    std::cout << "Digite a cidade de destino: ";
    std::getline(std::cin, destinoNome);
    Cidade* destino = encontrarCidadePorNome(destinoNome);
    if (!destino) {
        std::cout << "Cidade de destino não encontrada!\n";
        return;
    }

    std::cout << "Digite o nome do transporte: ";
    std::getline(std::cin, transporteNome);
    Transporte* transporte = encontrarTransportePorNome(transporteNome);
    //if (!transporte || transporte->getLocalizacaoAtual() != origem) {
      //  std::cout << "Transporte não encontrado ou não está na cidade de origem!\n";
        //return;
   // }

    std::vector<Passageiro*> passageirosSelecionados;
    std::cout << "Selecione os passageiros (digite os números separados por vírgulas):\n";
    for (size_t i = 0; i < passageiros.size(); ++i) {
        if (passageiros[i]->getLocalizacaoAtual() == origem) {
            std::cout << i + 1 << ". " << passageiros[i]->getNome() << "\n";
        }
    }

    std::string indices;
    std::getline(std::cin, indices);
    std::stringstream ss(indices);
    std::string indice;
    while (std::getline(ss, indice, ',')) {
        int idx = std::stoi(indice) - 1;
        if (idx >= 0 && idx < passageiros.size() && passageiros[idx]->getLocalizacaoAtual() == origem) {
            passageirosSelecionados.push_back(passageiros[idx]);
        }
    }

    // Verificação e criação da viagem
    if (origem && destino && transporte && !passageirosSelecionados.empty()) {
        viagens.push_back(new Viagem(origem, destino, transporte, passageirosSelecionados));
        viagens.back()->iniciarViagem();
        std::cout << "Viagem de '" << origemNome << "' para '" << destinoNome << "' iniciada com sucesso!\n";
    } else {
        std::cout << "Erro ao criar a viagem. Verifique os dados fornecidos.\n";
    }
    
}

void avancarTempo() {
    double horas;
    std::cout << "Digite o número de horas a avançar: ";
    std::cin >> horas;

    for (auto& viagem : viagens) {
        if (!viagem->chegouAoDestino()) {
            viagem->avancarHoras(horas);
        }
    }

    std::cout << "Estado do sistema atualizado!\n";
}

void consultarStatus() {
    std::cout << "Escolha uma opção:\n";
    std::cout << "1. Onde estão os passageiros?\n";
    std::cout << "2. Onde estão os transportes?\n";
    std::cout << "3. Relatar viagens em andamento\n";
    std::cout << "4. Relatar cidades mais visitadas\n";
    int opcao;
    std::cin >> opcao;

    switch (opcao) {
        case 1:
            for (auto& passageiro : passageiros) {
                std::cout << "Passageiro " << passageiro->getNome() << " está em '"
                          << passageiro->getLocalizacaoAtual()->getNome() << "'.\n";
            }
            break;
        case 2:
            for (auto& transporte : transportes) {
                std::cout << "Transporte " << transporte->getNome() << " está em '"
                          << transporte->getLocalizacaoAtual()->getNome() << "'.\n";
            }
            break;
        case 3:
            for (auto& viagem : viagens) {
                if (!viagem->chegouAoDestino()) {
                    std::cout << "Viagem de '" << viagem->getOrigem()->getNome() << "' para '"
                              << viagem->getDestino()->getNome() << "' em andamento.\n";
                }
            }
            break;
        case 4:
            // Implementar lógica para reportar cidades mais visitadas (opcional).
            std::cout << "Relatório de cidades mais visitadas (não implementado).\n";
            break;
        default:
            std::cout << "Opção inválida!\n";
            break;
    }
}

int main() {
    int opcao;
    do {
        std::cout << "==========================\n";
        std::cout << "  Sistema de Gerenciamento de Tráfego\n";
        std::cout << "==========================\n";
        std::cout << "Escolha uma opção:\n";
        std::cout << "1. Cadastrar Cidade\n";
        std::cout << "2. Cadastrar Trajeto\n";
        std::cout << "3. Cadastrar Transporte\n";
        std::cout << "4. Cadastrar Passageiro\n";
        std::cout << "5. Iniciar Viagem\n";
        std::cout << "6. Avançar Tempo\n";
        std::cout << "7. Consultar Status\n";
        std::cout << "0. Sair\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarCidade();
                break;
            case 2:
                cadastrarTrajeto();
                break;
            case 3:
                cadastrarTransporte();
                break;
            case 4:
                cadastrarPassageiro();
                break;
            case 5:
                iniciarViagem();
                break;
            case 6:
                avancarTempo();
                break;
            case 7:
                consultarStatus();
                break;
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
                break;
        }

        std::cout << "\n";
    } while (opcao != 0);

    return 0;
}
