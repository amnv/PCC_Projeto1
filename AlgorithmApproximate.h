#ifdef ALG_APPROXIMATE
#define ALG_APPROXIMATE

#include <deque>
#include "Algorithm.h"

class AlgorithmApproximate : public Algorithm 
{
public:
    virtual std::deque<int> dist(int e) = 0; //localiza as ocorrencias aproximadas do padrao a uma distancia de edicao maxima e
};

#endif