#ifndef BLOCO_HPP_
#define BLOCO_HPP_

#include "config.hpp"
#include "musical.hpp"

class bloco {
friend class hash;
public:
    bloco(uint);
    ~bloco();
    bool vazio() const;
protected:
    uint m_idHash;
    uint m_qtd = 0;
    objeto** m_vetorObjetos; // vetor de ponteiros para um objeto
};

#endif // BLOCO_HPP_
