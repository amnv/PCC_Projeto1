#ifndef WUMANBER
#define WU_MANBER

#include "shiftOr.h"
#include "Algorithm.h"
#include<bits/stdc++.h>


class WuManber : public shiftOr {
public:
    WuManber(string path, string pattern, int err);
    ~WuManber();

    int count(); //imprime a qtde total de ocorrencias
    std::deque<int> occ(); //lista as linhas das ocorrencias
    void setPat(std::string pat);
    void setText(std::string text);
    std::deque<int> dist(); //localiza as ocorrencias aproximadas do padrao a uma distancia de edicao maxima e
};

#endif

/* http://www.cin.ufpe.br/~paguso/courses/if767/bib/Wu_1992.pdf
 * https://pt.slideshare.net/mailund/wu-mamber-string-algorithms-2007
 * https://arxiv.org/pdf/1407.2889.pdf
 * http://repositorio.ufpe.br/bitstream/handle/123456789/2533/arquivo4823_1.pdf
*/