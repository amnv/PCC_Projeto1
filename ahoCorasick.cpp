#include "ahoCorasick.h"
#include <iostream>
#include <utility>
#include <map>

using namespace std;

ahoCorasick::ahoCorasick()
{

}

ahoCorasick::~ahoCorasick()
{

}

int ahoCorasick::g(char c, int state)
{
    if (state < gotoState.size()){

        vector<pair<char, int> > v = gotoState[state];


        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i].first == c) return v[i].second;
        }
    }
    return -1;
}

void ahoCorasick::buildGotoState(vector<string> pattern)
{
    int state = 0, newState = 0;
    //start point
    for (int k = 0; k < pattern.size(); k++) 
    {
        string pat = pattern[k];

        int i = 0;

        //search the graph for a similar path        
        while(state = g(pat[i], state) >= 0)
        {
            i++;
        }

        //building new path in graph
        for (; i < pat.size(); i++)
        {   
            newState++;
            vector<pair<char, int> > v; 
            v.push_back(make_pair(pat[i], newState));
            gotoState.push_back(v);
        }

	output[newState].push_back(pat);
    }
}

void ahoCorasick::debug()
{
    vector<string> a;
    a.push_back("he");
    a.push_back("she");
    a.push_back("his");
    a.push_back("hers");

    buildGotoState(a);

    for (int i = 0; i < gotoState.size(); ++i)
    {
        for (int j = 0; j < gotoState[i].size(); ++j)
        {
            cout << "pos " << i << " val " << gotoState[i][j].first 
            << " goto " << gotoState[i][j].second << endl;
        }
	
    }

    for (map<int, vector<string> >::iterator it = output.begin(); it != output.end(); ++it)
    {
	cout << "estado " << it->first << " palavras " << endl;
        for (int j = 0; j < it->second.size(); ++j)
	{
		cout << it->second[j] << " ";
	}
		cout << endl;
    }
    
}
