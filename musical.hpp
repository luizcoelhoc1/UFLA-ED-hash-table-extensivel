#ifndef MUSICAL_HPP_
#define MUSICAL_HPP_

class objeto {
friend class hash;
friend class bloco;
public:
    objeto(uint, const char*);
    ~objeto();
    void exibir();
protected:
    uint m_id;
    char* m_nome;
    char m_atorPrincipal[50];
    char m_atrizPrincipal[50];
    char m_enredo[200];
};

#endif // MUSICAL_HPP_
