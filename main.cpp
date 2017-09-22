#include <iostream>
#include <unistd.h>
#include "pessoa.h"

using namespace std;

/*para rodar executar 
    g++ *.h *.cpp
*/

int main(int argc, char const *argv[])
{
   pessoa p;
    p.fala();

    return 0;
}