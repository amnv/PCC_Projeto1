// #include <deque>
// #include <string>
// #include <fstream> 
#include<bits/stdc++.h>

#ifndef ALGORITHM 
#define ALGORITHM

using namespace std;

class Algorithm {
private:
    ifstream file;
    string path;
public:
    Algorithm(string path);
    ~Algorithm();
    void setFile(string path);
    void reloadFile();
    bool getLine(string& line);

    //metodos abstratos
    virtual int count() = 0; //imprime a qtde total de ocorrencias
    virtual void occ() = 0; //lista as linhas das ocorrencias
    virtual void setPat(string pat) = 0;
};

#endif