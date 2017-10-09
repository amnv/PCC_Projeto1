#include <vector>
#include <utility>
#include <string>
#include <map>

#ifndef AHO_CORASICK
#define AHO_CORASICK

using namespace std;

class ahoCorasick
{
    private:
      //edge list -> pair charecter and next state position
      vector<vector<pair<char, int> > > gotoState;
      vector<int> failer;
      map<int, vector<string> > output;
      vector<string> pattern;
      string text;

    public:

        ahoCorasick(string text, vector<string> pattern);
        ~ahoCorasick();
        
        int g(char c, int state);
        void buildGotoState();
        void buildFail();
        void outputFromFail(int r, int failState);
        void debug();
        map<string, int> execute();
};

#endif