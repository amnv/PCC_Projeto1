#include "ahoCorasick.h"
// #include <iostream>
// #include <utility>
// #include <map>
// #include <queue>
#include<bits/stdc++.h>

using namespace std;

#define FAIL -1
#define ZERO 0

ahoCorasick::ahoCorasick(string path, vector<string> pattern): Algorithm (path), pattern(pattern) 
{
    buildGotoState();
    buildFail();
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

    return state == 0 ? ZERO : FAIL;
}

void ahoCorasick::buildGotoState()
{
    int state = 0, newState = 0;
    //start point
    for (int k = 0; k < pattern.size(); k++) 
    {
        string pat = pattern[k];
        int i = state = 0;

        //search the graph for a similar path        
        int aux;
        while((aux = g(pat[i], state)) > 0)
        {
            state = aux;
            i++;
        }

        //building new path in graph
        if (state < gotoState.size())
        {
            newState++;
            gotoState[state].push_back(make_pair(pat[i], newState));
            gotoState.push_back(vector<pair<char, int> >());
            i++;
        }
        
        for (; i < pat.size(); ++i)
        {   
            newState++;
            vector<pair<char, int> > v; 
            v.push_back(make_pair(pat[i], newState));
            gotoState.push_back(v);
        }

	   output[newState].push_back(pat);
    }
}


void ahoCorasick::buildFail()
{
    queue<pair<char, int> > states;
    failer.resize(gotoState.size(), FAIL);

    vector<pair<char, int> > inicialState = gotoState[0];
    for (int i = 0; i < inicialState.size(); i++)
    {
        states.push(inicialState[i]);
        failer[inicialState[i].second] = 0;
    }

    while(!states.empty())
    {
        pair<char, int> r = states.front();
        states.pop();

        //adding edge list of r to queue
        vector<pair<char, int> > aux = gotoState[r.second];
        int failState;
        for (int i = 0; i < aux.size(); i++)
        {
            states.push(aux[i]);
            int state = failer[r.second];
            while((failState = g(aux[i].first, state)) == FAIL) state = failer[state];
            failer[aux[i].second] = failState;        

            //adding output 
            outputFromFail(aux[i].second, failState);        
        }
    }
}

void ahoCorasick::outputFromFail(int r, int failState)
{
    if (output[r].size() > 0)
    {
        for (int i = 0; i < output[failState].size(); i++)
            output[r].push_back(output[failState][i]);
    }
 //   cout << "asd" << endl;
}

map<string, int> ahoCorasick::execute()
{
    int state = 0, newState = 0;
    map<string, int> v;
    for (int i = 0; i < text.size(); i++)
    {
        while((newState = g(state, text[i])) == FAIL) state = failer[state];

        if (!output[newState].size())
        {
            cout << newState << " " ;
            for (int j = 0; j < output[newState].size(); ++j)
            {
                cout << output[newState][j] << endl;
            }
            
        }
    }

    return v;
}




void ahoCorasick::debug()
{
    vector<string> a;
    a.push_back("he");
    a.push_back("she");
    a.push_back("his");
    a.push_back("hers");

    buildGotoState();
    buildFail();

    //print g function
    for (int i = 0; i < gotoState.size(); ++i)
    {
        for (int j = 0; j < gotoState[i].size(); ++j)
        {
            cout << "pos " << i << " val " << gotoState[i][j].first 
            << " goto " << gotoState[i][j].second << endl;
        }
	
    }

    //print output function
    for (map<int, vector<string> >::iterator it = output.begin(); it != output.end(); ++it)
    {
    cout << "estado " << it->first << " palavras " << endl;
        for (int j = 0; j < it->second.size(); ++j)
    {
        cout << it->second[j] << " ";
    }
        cout << endl;
    }
    

    //print f function
    cout << "imprimindo f function" << endl;
    for (int i = 0; i < failer.size(); ++i)
    {
        cout << "estado " << i << " goto " << failer[i] << endl;
    }
}

int ahoCorasick::count()
{
    int state = 0, newState = 0;
    int count = 0;

    this->reloadFile();
    string texto;
    while(this->getLine(texto))
    {
        for (int i = 0; i < text.size(); i++)
        {
            while((newState = g(state, text[i])) == FAIL) state = failer[state];

            if (!output[newState].size())
            {
                cout << newState << " " ;
                for (int j = 0; j < output[newState].size(); ++j)
                {
                    count++;
                }
                
            }
        }
    }
    return count;
}

deque<string> ahoCorasick::occ()
{
    this->reloadFile();
    int state = 0, newState = 0;
    deque<string> ret;
    string texto;
    while(this->getLine(texto))
    {
        for (int i = 0; i < texto.size(); i++)
        {
            while((newState = g(state, texto[i])) == FAIL) state = failer[state];

            if (!output[newState].size())
            {
                cout << newState << " " ;
                for (int j = 0; j < output[newState].size(); ++j)
                {
                    ret.push_back(texto);
                }
                
            }
        }
    }
    return ret;
}

void ahoCorasick::setPat(std::string pat)
{
    //nao definido pois passa um vetor de string
}

void ahoCorasick::setText(std::string text)
{
    this->text = text;
}
