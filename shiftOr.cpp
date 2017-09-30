#include <bits/stdc++.h>
#define T 64

using namespace std;
class shiftOr{
private:
    //bitarray[]
public:
    shiftOr(){} 
    ~shiftOr(){}
    void action(string ppat, string stxt, bitset<T> & R){ //recebe 
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


};
// map<string, string> char_mask(string pat, string* ab){
//     map <string, string> masks = NULL;
//     int m = pat.size();
//     masks[]
// }

// void shiftor(string txt, string pat, string* ab){
//     int n = txt.size();
//     int m = pat.size();
//     deque<bool> a;
// }

int main(){
    shiftOr* s = new shiftOr();
    s->action2("abra", "cadabra");
    /*
    deque<int> deck;
    cout << "\n" << deck[0] << "\n";
    string a = "opa";
    map<string, string> dict;
    dict.insert(pair<string, string>("a", "asdas"));
    dict.insert(pair<string, string>("b", "1"));

    cout << dict["a"] << endl;

    for (map<string, string>::iterator it = dict.begin(); it != dict.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
*/
    return 0;
}

/*
https://github.com/paguso/if76720172/commit/dd87fb4813623a1d1b415e115928cfe42a43afa9
http://www.cin.ufpe.br/~paguso/courses/if767/bib/Baeza_1992.pdf
http://www-igm.univ-mlv.fr/~lecroq/string/node6.html
*/
