#ifndef SHIFT_OR
#define SHIFT_OR

#include <bits/stdc++.h>
#include "Algorithm.h"
#define T 64


using namespace std;
class shiftOr : public Algorithm{
private:
    deque<int> r;
public:
    shiftOr(string, string, string, bool);
    // ~shiftOr();
    int count();
    static map<char, bitset<T>> charMask(string, string);
    static void printDebug(deque<bitset<T>>, string, string);
    template <class P>
    static string fprint(deque<P> a);
    void debug();
    deque<int> occ();
};

#endif