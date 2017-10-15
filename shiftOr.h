#ifndef SHIFT_OR
#define SHIFT_OR

#include <map>
#include <deque>

#include "Algorithm.h"


using namespace std;
class shiftOr : public Algorithm{
private:
    string pat;
    map<char, long long> masks;
public:
    shiftOr(string path, string pat);
    // ~shiftOr();
    int count();
    static map<char, long long> charMask(string, string);
    deque<int> execute(string txt, bool qtde);
    // static void printDebug(deque<bitset<T>>, string, string);
    // template <class P>
    // static string fprint(deque<P> a);
    // void debug();
    void occ();
    void setPat(string);
    deque<int> dist();
    string getPat();
    int getBit(long long num, int indice);
    map<char, long long> getMasks();
};

#endif