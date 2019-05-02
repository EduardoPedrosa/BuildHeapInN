#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream arq ("saida.txt");
    double soma = 0;
    while(!arq.eof()){
        double aux;
        char cAux;
        arq >> cAux;
        arq >> aux;
        arq >> cAux;
        arq >> aux;
        soma += aux;
        arq >> cAux;
        arq >> cAux;
    }
    cout << soma << endl;
    return 0;
}
