#include <bits/stdc++.h>
#define T 64

using namespace std;
class shiftOr{
private:
    //bitarray[]
public:
    shiftOr(){} 
    ~shiftOr(){}
/*
void action(string ppat, string stxt, bitset<T> & R){ //recebe pedaco do padrao e pedaco do texto e coloca em R 0 ou 1 
        int patsize = ppat.size();
        int txtsize = stxt.size(); 
        if (ppat != stxt.substr(txtsize-patsize,txtsize)){
            std::cout << ppat << "!=" << stxt.substr(txtsize-patsize, txtsize) << std::endl;
            R.set(patsize-1);
        } else{
            std::cout << ppat << "==" << stxt.substr(txtsize-patsize, txtsize) << std::endl;
        }
    }

    void action2(string pat, string txt){
        int patsize = pat.size();
        int txtsize = txt.size();
        std::cout << "a" << std::endl;
        for (int j=patsize-1; j<txtsize; j++){ //percorrendo as partes do texto
            bitset<T> R;
            for (int i=0; i<patsize; i++){ //tentando cada parte do padrao
                action(pat.substr(0,i+1), txt.substr(0, j+1), R);
            }
            std::cout << R << std::endl;
        }
    }
*/
};
map<char, bitset<T>> char_mask(string pat, string ab){
    map <char, bitset<T>> masks; //as mascaras para cada letra do alfabeto
    bitset<T> posmask = bitset<T>().set();
    posmask.reset(0); //comecando com 111...0

    for (int i=0; i<ab.size();i++){ //colocando bitset para cada elemento do alfabeto
        char e = ab[i];
        masks[e] = bitset<T>().set(); //comecando com 1
    }
    for (int i=0; i<pat.size(); i++){ 
        char e = pat[i];
        masks[e] &= posmask;
        posmask = posmask << 1;
        posmask[0] = 1; //ou 1
    }
    return masks;
}

void printDebug(deque<bitset<T>> deck, string pat, string txt){
    cout << "  " << txt << endl;
    for (int j=0; j<pat.size();j++){
        cout << pat[j] << ' ';
        for (int i=0; i<deck.size(); i++){
            cout << deck[i][j];
        }
        cout << endl;
    }
}

deque<int> shiftor(string txt, string pat, string ab){
    map<char, bitset<T>> masks = char_mask(pat, ab);
    bitset <T> S;
    S.set();
    deque <int> occ;
    deque <bitset<T>> debug;
    for (int i=0; i<txt.size(); i++){
        char e = txt[i];
        S = S << 1 | masks[e];
        if (S[pat.size()-1] == 0){
            occ.push_back(i-pat.size()+1);
        }
        debug.push_back(S);
    }
    printDebug(debug, pat, txt);
    return occ;
}

template <class P>
string fprint(deque<P> a){
    string r = "";
    for(int i=0; i<a.size(); i++){
        ostringstream oss;
        oss << a[i];
        r = r + oss.str() + " ";
    }
    return r;
}

int main(){
    string abc =  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s = fprint(shiftor("babracadabrac", "abra", abc));
    cout << "\n" << s << endl;
    return 0;
}

/*
https://github.com/paguso/if76720172/commit/dd87fb4813623a1d1b415e115928cfe42a43afa9
http://www.cin.ufpe.br/~paguso/courses/if767/bib/Baeza_1992.pdf
http://www-igm.univ-mlv.fr/~lecroq/string/node6.html
*/


/** Algoritmos
    funcao char_mask:
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
