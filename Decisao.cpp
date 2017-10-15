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
        cout << "passando na parte de algName" << endl;
        this->nameToALgo();
        this->executa();
    }
    else 
    {
        if (editDistance >= 0)
        {
            cout << "passando no edit distance" << endl;
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
            cout << "passando para ver algoritmos exatos" << endl;
            //usa um dos algoritmos  exatos    
            if (pat.size() > 1)
            {
                this->algorithm = new ahoCorasick(this->files.front(), this->pat);
            }
            else 
            {
                cout << "passou no shiftor" << endl;
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
        cout << "antes de entrar em occ" << endl;
        deque<string> d = algorithm->occ();
        cout << "ocorrencias nas linhas" << endl;
        for(int i = 0; i < d.size(); i++)
        {
            cout << "linha: " << d[i] << " ";
        }
        cout << endl;
    }
}


