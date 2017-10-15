#ifndef SHIFT_OR
#define SHIFT_OR

#include <bitset>
#include <map>
#include <deque>

#include "Algorithm.h"
#define T 64


using namespace std;
class shiftOr : public Algorithm{
private:
    string pat;
    map<char, bitset<T>> masks;
public:
    shiftOr(string path, string pat);
    // ~shiftOr();
    int count();
    static map<char, bitset<T>> charMask(string, string);
    deque<int> execute(string txt, bool qtde);
    // static void printDebug(deque<bitset<T>>, string, string);
    // template <class P>
    // static string fprint(deque<P> a);
    // void debug();
    void occ();
    void setPat(string);
    deque<int> dist();
    string getPat();
    map<char, bitset<T>> getMasks();
};

#endif