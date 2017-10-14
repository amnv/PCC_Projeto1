#ifndef WUMANBER
#define WU_MANBER

#include "shiftOr.h"
#include "Algorithm.h"

class WuManber : public shiftOr {
public:
    WuManber(string texto, string pattern, string err);
    ~WuManber();

    virtual int count() = 0; //imprime a qtde total de ocorrencias
    virtual std::deque<int> occ() = 0; //lista as linhas das ocorrencias
    virtual void setPat(std::string pat) = 0;
    virtual void setText(std::string text) = 0;
    virtual std::deque<int> dist() = 0; //localiza as ocorrencias aproximadas do padrao a uma distancia de edicao maxima e
};

#endif

/* http://www.cin.ufpe.br/~paguso/courses/if767/bib/Wu_1992.pdf
 * https://pt.slideshare.net/mailund/wu-mamber-string-algorithms-2007
 * https://arxiv.org/pdf/1407.2889.pdf
 * http://repositorio.ufpe.br/bitstream/handle/123456789/2533/arquivo4823_1.pdf
*/