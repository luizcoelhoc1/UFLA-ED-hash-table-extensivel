#include <cstdlib>
#include <iostream> // retirar iostream -> implementar sobrecarga em um novo cpp para funcoes diversas
#include "hash.hpp"

hash::hash() {
    m_vetorBlocos = new bloco*[CAPACIDADE];
    for (uint i = 0; i < CAPACIDADE; ++i) {
        m_vetorBlocos[i] = NULL;
    }
}

hash::~hash() {
    for (uint i = 0; i < CAPACIDADE; ++i) {
        delete m_vetorBlocos[i];
    }
    delete[] m_vetorBlocos;
}

/* 
 * Re: Trabalho de ED
 * por JOAQUIM QUINTEIRO UCHOA - DOCENTE - DCC - sexta, 11 Mai 2018, 07:16
 *  
 * 
 * O tratamento de colisões não será feito pela tabela hash e sim pelo bloco. 
 * 
 * A tabela hash contém apenas qual o bloco associado à chave de cada registro.
 *
 */

// inserir recebe um ponteiro de objeto?
// ou parametro?
// ou so chama inserir do bloco?

// insere um objeto criado
void hash::inserir(objeto* p_obj) {
    // calcula hash pelo id do objeto
    // como a função nao existe, vai ser mod 16 :)
    uint id = p_obj->m_id % CAPACIDADE;
    
    if (m_vetorBlocos[id] == NULL) {
        m_vetorBlocos[id] = new bloco(id);
    }
    bloco* b = m_vetorBlocos[id]; // pra nao ficar vetor->vetor etc :)
    bool inseriu = false;
    for (uint i = 0; i < TAM_BLOCO && !inseriu; ++i) {
        if (b->m_vetorObjetos[i] == NULL) {
            b->m_vetorObjetos[i] = p_obj;
            ++b->m_qtd;
            inseriu = true;
        }
    }
    if (!inseriu) {
        delete p_obj;
    }
}

// cria um objeto e insere
void hash::inserir(uint p_id, const char* p_nome) {
    objeto* obj = new objeto(p_id, p_nome);
    
    // calcula hash pelo id do objeto
    // como a função nao existe, vai ser mod 16 :)
    uint id = obj->m_id % CAPACIDADE;
    
    if (m_vetorBlocos[id] == NULL) {
        m_vetorBlocos[id] = new bloco(id);
    }
    bloco* b = m_vetorBlocos[id]; // pra nao ficar vetor->vetor etc :)
    bool inseriu = false;
    for (uint i = 0; i < TAM_BLOCO && !inseriu; ++i) {
        if (b->m_vetorObjetos[i] == NULL) {
            b->m_vetorObjetos[i] = obj;
            ++b->m_qtd;
            inseriu = true;
        }
    }
    if (!inseriu) {
        delete obj;
    }
}


// remover
// se bloco voltar vazio
// volta a ser nulo <- TODO
void hash::remover(uint p_idRemover) {
    uint id = p_idRemover % CAPACIDADE;
    
    if (m_vetorBlocos[id] == NULL) {
        return; // bloco nao existe
    }
    
    bloco* b = m_vetorBlocos[id]; // pra nao ficar vetor->vetor
    objeto** o = b->m_vetorObjetos; // pra nao fica vetor->vetor->obj
    bool removeu = false;
    objeto* aux;
    for (uint i = 0; i < TAM_BLOCO && !removeu; ++i) {
        if (o[i]->m_id == p_idRemover) {
            aux = o[i];
            o[i] = NULL;
            removeu = true;
        }
    }
    
    if (removeu) {
        --b->m_qtd;
        delete aux; // removeu
    }
    if (b->vazio()) {
        delete b;
        m_vetorBlocos[id] = NULL;
    }
}

// implementar sobrecarga
void hash::imprimir() const {
    std::cout << "\n-------------------------------\n\n";
    for (uint i = 0; i < CAPACIDADE; ++i) {
        if (m_vetorBlocos[i] != NULL) {
            bloco* b = m_vetorBlocos[i];
            std::cout << " ~^.^~ -> ID HASH <- :  ~^.^~ "<< b->m_idHash << std::endl;
            for (uint j = 0; j < TAM_BLOCO; ++j) {
                if (b->m_vetorObjetos[j] != NULL) {
                    b->m_vetorObjetos[j]->exibir();
                    std::cout << std::endl;
                }
            }
            std::cout << "-------------------------------\n\n";
        }
        
    }
}
