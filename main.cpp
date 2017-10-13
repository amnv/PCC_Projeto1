#include <iostream>
#include <getopt.h> // *GNU* Para o getopt_long()
#include <string>
#include <queue>

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

int charToInt(char* texto)
{
    int x;
    //falta implementar
    return x;
}



int main(int argc, char **argv)
{
    /*fazer os seguinte padroes
        -e --edit Emax
        -p --pattern patternfile
        -a --algorithm algorithm_name
        -c --count
    */
    int optc = 0;
    int editDistance = 0;
    string pattern;
    string patternfileName;
    string algorithm_name;
    queue<string> files;
    bool count = false;

/*
   seller s("abracadabra", "abra", 2);
   s.debbug();
*/
 /*   vector<string> v;
    v.push_back("he");
    v.push_back("she");
    v.push_back("his");
    v.push_back("hers");
    
    ahoCorasick a("his asd her hers", v);
  a.debug();
*/
    return 0;

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
                editDistance = charToInt(optarg);
                //editDistance = optarg;
                break;
            case 'p':
                patternfileName = optarg;
                cout << "pattern" << endl;
                break;
            case 'a':
                algorithm_name = optarg;
                cout << "algorithm" << endl;
                break;
            case 'c':
                count = true;
                cout << "count" << endl;
                break;
            default:
                cout << "codigo digitado errado" << endl;
                return 1;
        }
   }


   //optind pega argumentos restantes
   //variavel de getopt
   if (optind >= argc)
   {
        cout << "Erro! Falta dados" << endl;
        return 1;
   }

   pattern = argv[optind++];

   while(optind < argc) files.push(argv[optind++]);

   if (files.empty()) cout << "Erro! Falta dados" << endl;

   while(!files.empty())
   {
        cout << files.front() << endl;
        files.pop();
   } 

   return 0;
}