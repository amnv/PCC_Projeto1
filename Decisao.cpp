#include <bits/stdc++.h>


Decisao::Decisao(int editDistance, string pattern, string patternfileName, string algorithm_name, queue<string> files, bool count)
{
    this.optc = optc;
    this.editDistance = editDistance;
    this.pattern = pattern;
    this.patternfileName = patternfileName;
    this.algorithm_name = algorithm_name;
    this.files = files;
    this.count = count;
}

void Decisao::escolhePadrao()
{
    if (pattern.empty())
    {
        this.pat.push_back(this.pattern;
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
    if (this.algorithm_name.size() > 0)
    {
        this.algorithm = this.nameToALgo();
    }
    else 
    {
        if (editDistance >= 0)
        {
            //usa um dos algoritmos NAO exatos    
            if (pat[0].size() > 64)
            {
                this.algorithm = 
            }
            else
            {

            }
        } 
        else
        {
            //usa um dos algoritmos  exatos    
        }
    }


}

Algorithm Decisao::nameToALgo()
{

}

void Decisao::executa()
{
    this.escolhePadrao();
    this.escolheArqTxt();
    this.escolheAlg();



}