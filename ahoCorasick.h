#include <vector>
#include <utility>
#include <string>
#include <map>
#include "Algorithm.h"

#ifndef AHO_CORASICK
#define AHO_CORASICK

using namespace std;

class ahoCorasick : public Algorithm
{
    private:
      //edge list -> pair charecter and next state position
      vector<vector<pair<char, int> > > gotoState;
      vector<int> failer;
      map<int, vector<string> > output;
      vector<string> pattern;
      string text;

    public:

        ahoCorasick(string path, vector<string> pattern);
        ~ahoCorasick();
        
        int g(char c, int state);
        void buildGotoState();
        void buildFail();
        void outputFromFail(int r, int failState);
        void debug();
        map<string, int> execute();
        int count(); //imprime a qtde total de ocorrencias
        deque<int> occ(); //lista as linhas das ocorrencias
        void setPat(std::string pat);
        void setText(std::string text);
        deque<int> dist();
};

#endif