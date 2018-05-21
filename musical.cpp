#include <cstdlib>
#include <iostream> // retirar iostream -> implementar sobrecarga em um novo cpp para funcoes diversas
#include <cstring>
#include "musical.hpp"

// implementar os outros campos do objeto
objeto::objeto(uint p_id, const char* p_nome) {
    m_id = p_id;
    m_nome = new char;
    strcpy(m_nome, p_nome);
}

// destrutor
objeto::~objeto() {
    delete m_nome;
}

// implementar sobrecarga
void objeto::exibir() {
    std::cout << "id: "   << m_id              << std::endl
              << "nome: " << m_nome            << std::endl;
}
