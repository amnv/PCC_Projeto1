
#ifndef SELLER
#define SELLER

#include <vector>
#include <string>
#include <deque>

#include "Algorithm.h"

using namespace std;

class seller : public Algorithm
{
private:
    string text;
    string pattern;
    int err;
public:
    seller(string path, string pattern, int err);
    // ~seller();
    vector<int> execute();
    vector<int> newColumn(vector<int>col, int i);
    void debbug();
    int count(); //imprime a qtde total de ocorrencias
    void occ(); //lista as linhas das ocorrencias
    void setPat(string pat);
    void setText(string text);
};

#endif