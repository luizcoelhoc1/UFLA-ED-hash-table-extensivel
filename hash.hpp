#ifndef HASH_HPP_
#define HASH_HPP_

#include "bloco.hpp"

class hash {
public:
    hash();
    ~hash();
    void inserir(objeto*);
    void inserir(uint, const char*);
    void remover(uint);
    void imprimir() const;
protected:
    bloco** m_vetorBlocos; // vetor de ponteiros para bloco
};

#endif // HASH_HPP_
