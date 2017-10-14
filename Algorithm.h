#include <deque>
#include <string>

#ifndef ALGORITHM 
#define ALGORITHM

class Algorithm 
{
public:
    virtual int count() = 0; //imprime a qtde total de ocorrencias
    virtual std::deque<int> occ() = 0; //lista as linhas das ocorrencias
    virtual void setPat(std::string pat) = 0;
    virtual void setText(std::string text) = 0;
    virtual std::deque<int> dist() = 0; //localiza as ocorrencias aproximadas do padrao a uma distancia de edicao maxima e
};

#endif