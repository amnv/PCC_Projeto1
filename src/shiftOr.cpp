#include "shiftOr.h"
#include <iostream>
// #include <sstream>
#include <string>

shiftOr::shiftOr(string path, string pat) : Algorithm (path) {
    this->setPat(pat);
}

int shiftOr::getBit(long long num, int i) {
    /** retorna o bit de indice i do numero recebido*/
      return num = num >> i & 1;
}

deque<int> shiftOr::execute(string txt, bool qt=false) {
    /** Dada uma string, diz em que local dela o pat se encontra */
    long long S = ~0;

    deque <int> occ;
    if (pat.size() > sizeof(long long)*8) {
        return occ;
    }
    // deque <bitset<T>> d;
    for (int i=0; i<txt.size(); i++){
        unsigned char e = txt[i];
        S = S << 1 | masks[e];
        if (!getBit(S, pat.size()-1)){ // o bit mais significativo usado eh 0
            occ.push_back(i-pat.size()+1);
            if (!qt) { //nao quer a qtde
                break;
            }
        }
        // if (debug == true) {
        //     d.push_back(S);
        // }
    }
    // if (debug) {
    //     printDebug(d, pat, txt);
    // }
    // std::cout << txt << " " << occ.size() << std::endl;
    return occ;
}

map<unsigned char, long long> shiftOr::charMask(string pat, unsigned char* ab, int sizeab){
    map <unsigned char, long long> masks; //as mascaras para cada letra do alfabeto
    long long posmask = ~1; //comecando com 111...0

    for (int i=0; i<sizeab;i++){ //criando mascara para cada elemento do alfabeto
        unsigned char e = ab[i];
        masks[e] = ~0; //comecando com tudo 1
    }
    for (int i=0; i<pat.size(); i++){
        unsigned char e = pat[i];
        masks[e] &= posmask;
        posmask = posmask << 1 | 1;
    }
    return masks;
}

// void shiftOr::printDebug(deque<bitset<T>> deck, string pat, string txt){
//     cout << "  " << txt << endl;
//     for (int j=0; j<pat.size();j++){
//         cout << pat[j] << ' ';
//         for (int i=0; i<deck.size(); i++){
//             cout << deck[i][j];
//         }
//         cout << endl;
//     }
// }

// template <class P>
// string shiftOr::fprint(deque<P> a){
//     string r = "";
//     for(int i=0; i<a.size(); i++){
//         ostringstream oss;
//         oss << a[i];
//         r = r + oss.str() + " ";
//     }
//     return r;
// }

int shiftOr::count(){
    /** Retorna a qtde total de ocorrencias de pat no arquivo*/
    this->reloadFile();
    int n = 0;
    string line;
    while (this->getLine(line)) {
        n += this->execute(line, true).size();
    }
    return n;
}

void shiftOr::occ() {
    /** Retorna todas as linhas do arquivo que ocorreram o pat */
    this->reloadFile();
    string line;
    // cout << "reloadBefore\n";
    while (this->getLine(line)) {
        // cout << "line";
        if (this->execute(line).size() > 0) { //ha ao menos 1 caso nessa linha
            cout << (line) << endl;
        }
    }
}

string shiftOr::getPat() {
    /** Para classe filha acessar */
    return this->pat;
}

map<unsigned char, long long> shiftOr::getMasks() {
    /** Para classe filha acessar */
    return this->masks;
}

// void shiftOr::debug(){
//     shiftOr* alg = new shiftOr("babracadabrac", "abra", abc);
//     string s = fprint(alg->occ());
//     std::cout << "\n" << s << std::endl;

//     delete alg;
// }

void shiftOr::setPat(string pat){
    unsigned char ab[256];
    unsigned char i=0;
    do {
        ab[i] = i;
        i++;
    } while (i>0 && i<=255);
    // cout << sizeof(ab) / sizeof(ab[0]) << endl;
    // string abc(ab);
    // string abc =  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    this->masks = charMask(pat, ab, 256);
    this->pat = pat;
}

/*
https://github.com/paguso/if76720172/commit/dd87fb4813623a1d1b415e115928cfe42a43afa9
http://www.cin.ufpe.br/~paguso/courses/if767/bib/Baeza_1992.pdf
http://www-igm.univ-mlv.fr/~lecroq/string/node6.html
*/


/** Algoritmos
    funcao charMask:
    recebe o padrao e o alfabeto
    masks eh um array de bitarray, tem 1 bitarray pra cada elemento do alfabeto
    para cada elemento no alfabeto adiciona um indice bitarray no array masks com todos valores setados
    cria-se um bitarray posmask com todos setados menos o ultimo
    para cada elemento do padrao, faz-se que sua mascara eh sua mascara & a posmask, entao da-se um shift left na pos-mask e | 1 (coloca seu ultimo elemento como setado).
    retorna o array de bitarrays, masks

    funcao shift-of:
    recebe o texto, o padrao e o alfabeto
    cria-se o masks de todos caracteres do padrao
    cria-se um bitarray S com tudo setado
    para cada elemento do texto, faz-se S = S << 1 | masks[elemento], se bit mais significativo de S estah apagado, registra-se como ocorrencia a posicao do elemento - o tamanho do padrao (para o inicio da ocorrencia)

    retorna as ocorrencias de match to padrao para aquele texto

*/
