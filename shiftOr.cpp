#include <bits/stdc++.h>

using namespace std;

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