#include <cstdlib>
#include "bloco.hpp"

bloco::bloco(uint p_id) {
    m_vetorObjetos = new objeto*[TAM_BLOCO];
    for (uint i = 0; i < TAM_BLOCO; ++i) {
        m_vetorObjetos[i] = NULL;
    }
    m_idHash = p_id;
}

bloco::~bloco() {
    for (uint i = 0; i < TAM_BLOCO; ++i) {
        delete m_vetorObjetos[i];
    }
    delete[] m_vetorObjetos;
}

bool bloco::vazio() const {
    return m_qtd == 0;
}
