#include "wuManber.h"
#include<bits/stdc++.h>

WuManber::WuManber(string path, string pattern, int err) : shiftOr(path, pattern){}
WuManber::~WuManber(){}

int WuManber::count(){} //imprime a qtde total de ocorrencias
std::deque<int> WuManber::occ(){} //lista as linhas das ocorrencias
void WuManber::setPat(std::string pat){}
void WuManber::setText(std::string text){}
std::deque<int> WuManber::dist(){} //localiza as ocorrencias aproximadas do padrao a uma distancia de edicao maxima e
