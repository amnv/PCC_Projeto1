
Algorithm::Algorithm(string path) {
    file.open(path);
}

string Algorithm::getLine() {
/** Retorna a próxima linha do arquivo, se não existir o retorno é NULL */
    string r;
    if (!file.eof()) {
        file >> r;
    } else {
        r = NULL;
    }
    return r;
}

void Algorithm::setFile(string path) {
    if (file && file.is_open()) {
        file.close();
    }
    file.open(path);
}