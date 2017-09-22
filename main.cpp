#include <iostream>
#include <unistd.h>
#include "pessoa.h"

using namespace std;

int main(int argc, char const *argv[])
{
    pessoa p* = new pessoa();
    p::fala();


    return 0;
}