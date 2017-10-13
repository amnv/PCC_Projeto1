#ifdef ALG_APPROXIMATE
#define ALG_APPROXIMATE

#include <deque>


class AlgorithmApproximate : public Algorithm {
public:
    virtual std::deque<int> dist(int e); //localiza as ocorrencias aproximadas do padrao a uma distancia de edicao maxima e
};
#endif