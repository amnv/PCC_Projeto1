// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
#include<bits/stdc++.h>
// #include "Algorithm.h"
#include "seller.h"

using namespace std;

seller::seller(string path, string pattern, int err) : Algorithm (path){
    this->pattern = pattern;
    this->err = err;
}
// seller::~seller(){}

vector<int> seller::newColumn(vector<int> col, int j)
{
   vector<int> newCol(pattern.size() + 1, 0);

   for (int i = 1; i <= pattern.size(); ++i)
   {
       int phi = (pattern[i-1] == text[j]) ?0 :1;
       int aux = min(col[i] + 1, newCol[i-1] + 1);
       newCol[i] = min(aux , col[i-1] + phi);
   }

   return newCol;
}

vector<int> seller::execute()
{
    int tamPattern = pattern.size();
    vector<int> col(tamPattern + 1);
    vector<int> occuranceList;

    this->reloadFile();
    string texto;
    while(this->getLine(texto))
    {
        for (int i = 0; i < text.size(); ++i)
        {
            col = newColumn(col, i);
            if (col[tamPattern] <= err)
            {
                occuranceList.push_back(i);
            }
        }
    }
    return occuranceList;
}


void seller::debbug()
{
  vector<int> v = execute();

  for (int i = 0; i < v.size(); ++i)
  {
    cout << v[i] << endl;
  }
}

void seller::setPat(string pat)
{
    this->pattern = pat;
}
void seller::setText(string text)
{
    this->text = text;
}

int seller::count() 
{
    return this->execute().size();
}

deque<string> seller::occ() 
{

}