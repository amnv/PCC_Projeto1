#include <vector>
#include <string>
#include <deque>

#include "AlgorithmApproximate.h"

#ifndef SELLER
#define SELLER

using namespace std;

class seller 
{
private:
    string text;
    string pattern;
    int err;
public:
    seller(string text, string pattern, int err);
    ~seller();
    vector<int> execute();
    vector<int> newColumn(vector<int>col, int i);
    void debbug();
};

#endif