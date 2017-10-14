#include "Algorithm.h"

Algorithm::Algorithm(string path) {
    // file.open(path);
    this->path = path;
}

bool Algorithm::getLine(string& line) {
/** Retorna a próxima linha do arquivo, se não existir o retorno é NULL */
/** Retorna se ainda consegue ler e se sim, coloca a proxima linha na var do parametro */ 
    if (!file.eof()) {
        std::getline(file, line);
        return true;
    } else {
        return false;
    }
}

void Algorithm::reloadFile() {
    /** Usada qd jah leu todas linhas do arquivo e precisa ler dnv */
    this->setFile(this->path);
}

void Algorithm::setFile(string path) {
    /** Seta um novo caminho de arquivo e fecha um anterior se existir */
    if (file && file.is_open()) {
        file.close();
    }
    file.open(path);
}