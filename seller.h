#include <vector>
#include <string>
#include <deque>

#ifndef SELLER
#define SELLER

using namespace std;

class seller 
{
private:
    string text;
    string pattern;
    int err;
public:
    seller(string text, string pattern, int err);
    ~seller();
    vector<int> execute();
    vector<int> newColumn(vector<int>col, int i);
    void debbug();
    int count(); //imprime a qtde total de ocorrencias
    deque<int> occ(); //lista as linhas das ocorrencias
    void setPat(std::string pat);
    void setText(std::string text);
    deque<int> dist(int e) = 0; //localiza as ocorrencias aproximadas do padrao a uma distancia de edicao maxima e
};

#endif