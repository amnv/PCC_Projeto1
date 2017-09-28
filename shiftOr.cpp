#include <bits/stdc++.h>

using namespace std;

class bitarray {
private:
    int n;
    deque<bool> data;
public:
    bitarray(int n){
        this->n = n;
        deque<bool> deck;
        this->data = deck;
        
    }
    bitarray(deque<bool> n){
        this->n = n.size();
        this->data = n;
    }

    deque<bool> getData(){
        return this->data;
    }

    bitarray* operator&(bitarray* c){
        deque<bool> a = this->getData(), b = c->getData();

        deque<bool> r;
        int m = max(a.size(), b.size());
        for (int i=0; i<m; i++){
            bool el;
            if (a.size() >= i+1 && b.size() >= i+1){
                el = a[i] & b[i];
            } else if (a.size() >= i+1){
                el = a[i];
            } else{
                el = b[i];
            }
            r.push_back(el);
        }
        return new bitarray(r);
    }

    void print(){
        cout << "opa" << n << endl;
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

int main()
{
    bitarray* opa = new bitarray(2);
    opa->print();
    deque<int> deck;
    cout << "\n" << deck[0] << "\n";
    string a = "opa";
    map<string, string> dict;
    dict.insert(pair<string, string>("a", "asdas"));
    dict.insert(pair<string, string>("b", "1"));

    cout << dict["a"] << endl;

    for (map<string, string>::iterator it = dict.begin(); it != dict.end(); ++it)
        cout << it->first << " => " << it->second << '\n';

    return 0;
}

/*
https://github.com/paguso/if76720172/commit/dd87fb4813623a1d1b415e115928cfe42a43afa9
http://www.cin.ufpe.br/~paguso/courses/if767/bib/Baeza_1992.pdf
http://www-igm.univ-mlv.fr/~lecroq/string/node6.html
*/