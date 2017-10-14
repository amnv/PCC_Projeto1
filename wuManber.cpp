#include "wuManber.h"
#include<bits/stdc++.h>

WuManber::WuManber(string path, string pattern, int err) : shiftOr(path, pattern){}
WuManber::~WuManber(){}

int WuManber::count(){} //imprime a qtde total de ocorrencias
std::deque<string> WuManber::occ(){ //lista as linhas das ocorrencias
    
}

void WuManber::setText(std::string text){}

void WuManber::setPat(std::string pat) {
    shiftOr::setPat(pat);
}

std::deque<int> WuManber::execute(string txt) {

}

string WuManber::getPat() {
    std::cout << "opa" << std::endl;
    return shiftOr::getPat();
}

map<char, bitset<T>> WuManber::getMasks() {
    return shiftOr::getMasks();
}