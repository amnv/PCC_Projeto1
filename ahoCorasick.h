#include <vector>
#include <utility>
#include <string>

#ifndef AHO_CORASICK
#define AHO_CORASICK

using namespace std;

class ahoCorasick
{
    private:
        vector<vector<pair<char, int> > > gotoState;

    public:

        ahoCorasick();
        ~ahoCorasick();
        
        int g(char c, int state);
        void buildGotoState(vector<string> pattern);
        void debug();
};

#endif