#include <bits/stdc++.h>

//algorithm implementation
#include "Decisao.h"
#include "Algorithm.h"
#include "seller.h"
#include "wuManber.h"
#include "ahoCorasick.h"
#include "shiftOr.h"

Decisao::Decisao(int editDistance, string pattern, string patternfileName, string algorithm_name, queue<string> files, bool count)
{
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
    if (this->patternfileName.empty()) //nao passou um arquivo para pegar padroes
    {
        this->pat.push_back(this->pattern);
    } else {
        //tratar
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
        cout << "passando na parte de algName" << endl;
        this->nameToALgo();
        return;
    }
    else 
    {
        if (editDistance >= 0)
        {
            //usa um dos algoritmos NAO exatos    
            if (pat[0].size() > 64)
            {
                this->algorithm = new seller(this->files.front(), this->pat[0], this->editDistance);
            }
            else
            {
                this->algorithm = new WuManber(this->files.front(), this->pat[0], this->editDistance);
            }
        } 
        else
        {
            //usa um dos algoritmos  exatos    
            if (pat.size() > 1 || pat[0].size() > sizeof(long long)*8) //ou o tamanho do padrao nao cabe no long long
            {
                this->algorithm = new ahoCorasick(this->files.front(), this->pat);
            }
            else 
            {
                this->algorithm = new shiftOr(this->files.front(), this->pat[0]);
            }
        }
        this->files.pop();
    }
    

}

void Decisao::nameToALgo()
{
    if (this->algorithm_name == "ahocorasick")
    {
        this->algorithm = new ahoCorasick(this->files.front(), pat);
    }
    else if (this->algorithm_name == "seller")
    {
        this->algorithm = new seller(this->files.front(), this->pat[0], this->editDistance);
    }
    else if (this->algorithm_name == "WuManber")
    {
        this->algorithm = new WuManber(this->files.front(), this->pat[0], this->editDistance);
    }
    else if (this->algorithm_name == "shiftOr")
    {
        this->algorithm = new shiftOr(this->files.front(), this->pat[0]);
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
        cout << "Quantidade total de ocorrencias " << algorithm->count() << endl;
    }
    else
    {
        algorithm->occ();
        // for(int i = 0; i < d.size(); i++)
        // {
        //     cout << d[i] << endl;
        // }
        // cout << endl;
    }
}


