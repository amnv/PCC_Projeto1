#include <deque>
#include <string>

#ifndef ALGORITHM 
#define ALGORITHM

using namespace std;

class Algorithm {
private:
    ifstream file;
public:
    Algorithm(string path);
    virtual int count() = 0; //imprime a qtde total de ocorrencias
    virtual std::deque<int> occ() = 0; //lista as linhas das ocorrencias
    virtual void setPat(string pat) = 0;
    void setFile(string path) = 0;
    string getLine();
};

#endif