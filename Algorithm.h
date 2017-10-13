#include <deque>

#ifndef ALGORITHM 
#define ALGORITHM

class Algorithm 
{
public:
    virtual int count(); //imprime a qtde total de ocorrencias
    virtual std::deque<int> occ(); //lista as linhas das ocorrencias
    
};

#endif