Sistema de Gerenciamento de Tráfego entre Cidades

## Descrição

Este projeto é um sistema em C++ que gerencia o tráfego entre cidades, considerando diferentes tipos de trajetos e meios de transporte. O sistema permite o cadastro de cidades, trajetos, transportes e passageiros, e também realiza a simulação e cálculo de viagens entre as cidades.

## Funcionalidades

- **Cadastro de Cidades**: Adicione e gerencie cidades.
- **Cadastro de Trajetos**: Registre trajetos entre cidades, especificando o tipo (aquático ou terrestre) e a distância.
- **Cadastro de Transportes**: Cadastrar transportes com informações sobre tipo, capacidade, velocidade, distância entre descansos e tempo de descanso.
- **Cadastro de Passageiros**: Adicione passageiros e registre suas localizações.
- **Gestão de Viagens**: Inicie viagens, selecione transportes e passageiros, avance o tempo, e calcule o melhor trajeto.
- **Consultas e Relatórios**: Consulte o status dos passageiros e transportes, veja viagens em andamento e relatórios de cidades mais visitadas.

## Requisitos

- **Compilador**: Um compilador C++ compatível (como g++, clang++).
- **Sistema Operacional**: O sistema foi desenvolvido e testado em Windows.

## Estrutura do Projeto

- **`sistema.cpp`**: Ponto de entrada do programa e menu principal.
- **`Cidade.h`**: Definição e implementação da classe `Cidade`.
- **`Trajeto.h`**: Definição e implementação da classe `Trajeto`.
- **`Transporte.h`**: Definição e implementação da classe `Transporte`.
- **`Passageiro.h`**: Definição e implementação da classe `Passageiro`.
- **`Viagem.h`**: Definição e implementação da classe `Viagem`.

## Compilação e Execução

1. **Compilação**:

Certifique-se de que você tenha um compilador C++ instalado. Se estiver usando um sistema baseado em Unix (como Linux ou macOS), você pode instalar o `g++` ou `clang++`. Em sistemas Windows, você pode usar MinGW ou Microsoft Visual Studio.
  
   ```bash
   g++ -o programa sistema.cpp Cidade.h Trajeto.h Transporte.h Passageiro.h Viagem.h

   programa.exe
