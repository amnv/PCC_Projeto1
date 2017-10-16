#include <iostream>
#include <getopt.h> // *GNU* Para o getopt_long()
#include <string>
#include <queue>
#include "Decisao.h"

// #include "Algorithm.h"
// #include "ahoCorasick.h"
// #include "shiftOr.h"

#define NAO_SETADA -1

using namespace std;

/*
    compile all files at once
    g++ *.h *.cpp

    run project 
    ./a.out
*/

//def1ne
//def1n1
//defin3
//de
//padr135
int main(int argc, char **argv)
{
    // vector<string> pats;
    // pats.push_back("padroes"); 
    // Algorithm* a = new ahoCorasick("./main.cpp", pats);
    // Algorithm* b = new shiftOr("./main.cpp", "padroes");
    // cout << "vai comecar" << endl;
    // deque<string> opa = a->occ();
    // cout << "terminou ahocorasick" << endl;
    // deque<string> opa2 = b->occ();
    // cout << "terminou shiftOr" << endl;
    
    // for (int i=0; i<opa.size(); i++) {
    //     cout << opa[i] << endl;
    //     cout << opa2[i] << endl;
        
    // }
    // return 0;
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
    string patternfileName = "";
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
                editDistance = atoi(optarg);
                //editDistance = optarg;
                break;
            case 'p':
                patternfileName = optarg;
                break;
            case 'a':
                algorithm_name = optarg;
                break;
            case 'c':
                count = true;
                break;
            case 'h':
                help = true;
                break;
            default:
                cout << "Codigo digitado errado" << endl;
                return 1;
        }
   }

   if (help)
   {
       cout << 
       "USO: " << argv[0] << " [OPCOES] {PADRAO|-p FILE} ARQUIVO\n\
       OPCOES:\n\
       -e --edit Emax\n\
       -p --pattern patternfile\n\
       -a --algorithm [ahocorasick, seller, shiftor or wumanber]\n\
       -c --count\n\
       -h --help!\n\
       Algoritmos usados:\n\
       ahocorasick, seller, shiftor, wumanber\n";

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
    if (patternfileName.empty()) { //nao setou nenhum arquivo para o padrao
        pattern = argv[optind++];
    }
    while(optind < argc) files.push(argv[optind++]);
    
    if (files.empty()) cout << "Erro! Falta dados" << endl;
    
    //adicionar classe decisao que fara isso
    Decisao decisao(editDistance, pattern, patternfileName, algorithm_name, files, count);
    decisao.executa();

    return 0;
}