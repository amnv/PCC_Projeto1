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

    public:

        ahoCorasick();
        ~ahoCorasick();
        
        int g(char c, int state);
        void buildGotoState(vector<string> pattern);
        void buildFail();
        void outputFromFail(int r, int failState);
        void debug();
};

#endif