#include <iostream>
#include <getopt.h> // *GNU* Para o getopt_long()

//algorithm implementation
#include "seller.h"
#include "wuManber.h"
#include "ahoCorasick.h"
#include "shiftOr.h"

using namespace std;

/*
    compile all files at once
    g++ *.h *.cpp

    run project 
    ./a.out
*/


int main(int argc, char **argv)
{
    /*fazer os seguinte padroes
        -e --edit Emax
        -p --pattern patternfile
        -a --algorithm algorithm_name
        -c --count
    */
    int optc = 0;

    //no_argument = 0, required_argument = 1, opcional_argument = 2
    const struct option optionArray[] = {
        {"edit", required_argument, NULL, 'e'},
        {"pattern", required_argument, NULL, 'p'},
        {"algorithm_name", required_argument, NULL, 'a'},
        {"count", no_argument, NULL, 'c'},
        {0, 0, 0, 0}
    };

   while((optc = getopt_long(argc, argv, "e:p:a:c:", optionArray, NULL)) != -1)
   {
        switch (optc)
        {
            case 'e':
                cout << "edit" << endl;
                break;
            case 'p':
                cout << "pattern" << endl;
                break;
            case 'a':
                cout << "algorithm" << endl;
                break;
            case 'c':
                cout << "count" << endl;
                break;
            default:
                cout << "codigo digitado errado" << endl;
        }
   }

   return 0;
}