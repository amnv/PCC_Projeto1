#include <iostream>
#include <getopt.h> // *GNU* Para o getopt_long()
#include <string>
#include <queue>

#include "Decisao.h"

#define NAO_SETADA -1

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
        -h --help
    */
    int optc = 0;
    int editDistance = NAO_SETADA;
    string pattern;
    string patternfileName;
    string algorithm_name;
    queue<string> files;
    bool count = false;
    bool help = false;
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

    //no_argument = 0, required_argument = 1, opcional_argument = 2
    const struct option optionArray[] = {
        {"edit", required_argument, NULL, 'e'},
        {"pattern", required_argument, NULL, 'p'},
        {"algorithm_name", required_argument, NULL, 'a'},
        {"count", no_argument, NULL, 'c'},
        {"help", no_argument, NULL, 'h'},
        {0, 0, 0, 0}
    };

   while((optc = getopt_long(argc, argv, "e:p:a:ch", optionArray, NULL)) != -1)
   {
        switch (optc)
        {
            case 'e':
                editDistance = charToInt(optarg);
                //editDistance = optarg;
            case 'p':
                patternfileName = optarg;
                cout << "pattern" << endl;
            case 'a':
                algorithm_name = optarg;
                cout << "algorithm" << endl;
            case 'c':
                count = true;
                cout << "count" << endl;
            case 'h':
                help = true;
                cout << "help" << endl;
                break;
            default:
                cout << "codigo digitado errado" << endl;
                return 1;
        }
   }

   if (help)
   {
       cout << 
       "Para rodar o programa utilize os ./a.out pattern file_name\
       mais os seguintes parametros opcionais:\n\
       -e --edit Emax\n\
       -p --pattern patternfile\n\
       -a --algorithm algorithm_name\n\
       -c --count\n\
       -h --help!\n\
       lista de algoritmos implementados:\n\
       Ahocorasick, Seller, ShiftOr, WuManber\n";

       //Encerra execucao do programa
       return 1;
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

    //adicionar classe decisao que fara isso
    Decisao decisao(editDistance, pattern, patternfileName, algorithm_name, files, count);
    decisao.executa();

    return 0;
}