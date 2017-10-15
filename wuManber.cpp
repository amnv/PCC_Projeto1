#include "wuManber.h"
#include<bits/stdc++.h>
#define T 64

WuManber::WuManber(string path, string pattern, int err) : shiftOr(path, pattern), err(err){}
WuManber::~WuManber() {}

std::deque<int> WuManber::execute(string txt, bool qtde=false) {
    map<char, bitset<T>> masks = this->getMasks();
    string pat = this->getPat();

    bitset<T> all = bitset<T>().set();
    deque<int> occs;
    deque<bitset<T>> S;
    S[0] = all;
    for (int i=1; i<=this->err; i++)
        S[i] = S[i-1] >> 1;

    for (int j=0; j<txt.size(); j++) {
        bitset<T> S1 = S[0];
        char e = txt[j];
        S[0] = S[0] << 1 | masks[e];
        for (int k=1; k<=this->err; k++) {
            bitset<T> Sold = S[k];
            S[k] = (S[k] << 1 | masks[e]) & (S1 << 1) & (S[k-1] << 1) & S1;
            S1 = Sold;
        }
        if (S[this->err][pat.size()-1] == 0) {
            occs.push_back(j - pat.size() + 1);
            if (!qtde) //soh quer saber se tem occ na linha
                break;
        }
    }
    return occs;
}

int WuManber::count() { //imprime a qtde total de ocorrencias
    this->reloadFile();
    string line;
    int n = 0;
    while (this->getLine(line)) {
        n += this->execute(line, true).size();
    }
    return n;
}

void WuManber::occ() {
    /** Retorna todas as linhas do arquivo que ocorreram o pat */
    this->reloadFile();
    string line;
    while (this->getLine(line)) {
        if (this->execute(line).size() > 0) { //ha ao menos 1 caso nessa linha
            std::cout << (line) << std::endl;
        }
    }
}

void WuManber::setPat(std::string pat) {
    shiftOr::setPat(pat);
}



string WuManber::getPat() {
    return shiftOr::getPat();
}

map<char, bitset<T>> WuManber::getMasks() {
    return shiftOr::getMasks();
}