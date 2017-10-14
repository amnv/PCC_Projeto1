#include <deque>
#include <string>
#include <fstream> 

#ifndef ALGORITHM 
#define ALGORITHM

using namespace std;

class Algorithm {
private:
    ifstream file;
    string path;
public:
    Algorithm(string path);
    virtual int count() = 0; //imprime a qtde total de ocorrencias
    virtual deque<int> occ() = 0; //lista as linhas das ocorrencias
    virtual void setPat(string pat) = 0;
    void setFile(string path);
    void reloadFile();
    bool getLine(string& line);
    virtual deque<int> dist() = 0; //localiza as ocorrencias aproximadas do padrao a uma distancia de edicao maxima e

};

#endif