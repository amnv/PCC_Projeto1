#ifndef DECISAO
#define DECISAO

#include <bits/stdc++.h>
#include "Algorithm.h"

using namespace std;

class Decisao 
{
private:
    vector<string> pat;
    Algorithm *algorithm;
    int editDistance;
    string pattern;
    string patternfileName;
    string algorithm_name;
    queue<string> files;
    bool count;

public:
    Decisao(int editDistance,string pattern, string patternfileName, string algorithm_name, queue<string> files, bool count);
    ~Decisao();
    void escolhePadrao();
    void escolheAlg();
    void executa(); //escolhe algoritmo e acao correta a ser executado
    void nameToALgo();
};
#endif