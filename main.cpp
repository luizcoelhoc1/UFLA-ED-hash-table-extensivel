#include <cstdlib>
#include <iostream>
#include "hash.hpp"

/* 
 * TODO
 * implementar arquivo < importante
 * mexer na impressao 4 < imprimir na ordem de insercao / armazenamento
 * criar impressao 5 < ordenada em um bloco
 * mexer na insercao 1 < inserir ordenado
 * implementar busca 3 < binaria (precisa ordenar) ou sequencial
 * DESCOBRIR PRA QUE QUE SERVE BINARIO
 * RELATORIO <<<<<<<<<<<<<<<<<<<<<<<-
 * ESCREVER CABECALHO NOS HEADERS
 * EXPLICANDO FUNCOES
 * COMENTARIOS
 */

int main() {
    hash h;
    uint id;
    char nome[256];
    int opcao = 0;
    while (opcao != 6) {
        std::cout << "MENU" << std::endl;
        std::cout << "1: inserir" << std::endl;
        std::cout << "2: remover" << std::endl;
        std::cout << "3: consultar - nao existe" << std::endl;
        std::cout << "4: imprimir tudo" << std::endl;
        std::cout << "5: imprimir bloco - ler id - nao existe" << std::endl;
        std::cout << "6: sair" << std::endl;
        
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                std::cout << "id: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "nome: ";
                std::cin.getline(nome, 256);
                h.inserir(id, nome);
                break;
            case 2:
                std::cout << "id: ";
                std::cin >> id;
                h.remover(id);
                break;
            case 3:
                continue;
            case 4:
                h.imprimir();
                std::cin.ignore();
                std::cout << "aperte enter para continuar...";
                std::cin.get();
                break;
            case 5:
                continue;
            case 6:
                exit(EXIT_SUCCESS);
                
        }
        system("clear");
    }
    
    return 0;
}
