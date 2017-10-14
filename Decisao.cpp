#include <bits/stdc++.h>

//algorithm implementation
#include "seller.h"
#include "wuManber.h"
#include "ahoCorasick.h"
#include "shiftOr.h"

Decisao::Decisao(int editDistance, string pattern, string patternfileName, string algorithm_name, queue<string> files, bool count)
{
    this->optc = optc;
    this->editDistance = editDistance;
    this->pattern = pattern;
    this->patternfileName = patternfileName;
    this->algorithm_name = algorithm_name;
    this->files = files;
    this->count = count;
}

Decisao::~Decisao()
{
    delete algorithm;
}

void Decisao::escolhePadrao()
{
    if (pattern.empty())
    {
        this->pat.push_back(this->pattern);
    }
}

/**
 *Lista de algoritmos possiveis
 * AhoCorasick -> caso varios padroes
 * ShiftOr -> Apenas um padrao
 * WuManber -> caso tamanho padrao < 64 e opcao edicao de texto setada
 * Seller -> Caso tamanho padrao >= 64 e opcao edicao de texto setada
 */
void Decisao::escolheAlg()
{
    //testa se foi declarado explicatamente algum algoritmo
    if (this->algorithm_name.size() > 0)
    {
        this->nameToALgo();
        Algorithm a(arg);
        a.executa()
    }
    else 
    {
        if (editDistance >= 0)
        {
            //usa um dos algoritmos NAO exatos    
            if (pat[0].size() > 64)
            {
                this->algorithm = new seller(this->files[0], this->pat[0], this->err);
            }
            else
            {
                this->algorithm = new WuManber(this->files[0], this->pat[0], this->err);
            }
        } 
        else
        {
            //usa um dos algoritmos  exatos    
            if (pat.size() > 1)
            {
                this->algorithm = new ahoCorasick(this->files[0], this->pat[0]);
            }
            else 
            {
                string file = fileToString(0);
                this->algorithm = new shiftOr(file, this->pat[0]);
            }
        }
    }


}

Algorithm* Decisao::nameToALgo()
{
    if (this->algorithm_name == "ahocorasick")
    {
        this->algorithm = new ahoCorasick(this->files[0], this->pat[0]);
    }
    else if (this->algorithm_name == "seller")
    {
        this->algorithm = new seller(this->files[0], this->pat[0], this->err);
    }
    else if (this->algorithm_name == "WuManber")
    {
        this->algorithm = new WuManber(this->files[0], this->pat[0], this->err);
    }
    else if (this->algorithm_name == "shiftOr")
    {
        this->algorithm = new shiftOr(this->files[0], this->pat[0]);
    }
    else 
    {
        //erro
    }
}

void Decisao::executa()
{
    this->escolhePadrao();
    this->escolheAlg();

    //escolhe qual funcao executar
    if (this->count)
    {
        this->algorithm->count();
    }
    else if (this->editDistance >= 0)
    {
        this->algorithm.dist();
    }
}
