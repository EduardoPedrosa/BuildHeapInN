#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Heap {
private:
    vector<int> vetor;

    int filhoDireita(int indice){
        int result = (indice * 2 + 1) + 1;
        return result >= vetor.size() ? -1 : result;
    }

    int filhoEsquerda(int indice){
        int result = (indice * 2 + 1);
        return result >= vetor.size() ? -1 : result;
    }
    
    int menorFilho(int indice){
        int esquerda = filhoEsquerda(indice);
        int direita = filhoDireita(indice);
        if(esquerda == -1){
            if(direita == -1){
                return -1;
            } else {
                return direita;
            }
        }
        if(direita == -1) {
            return esquerda;
        }
        return (vetor.at(esquerda)) < (vetor.at(direita)) ? esquerda : direita;
    }

    void swap(int a, int b){ //troca os elementos do vetor que estão nas posicoes passadas por parametro
        int aux = vetor.at(a);
        vetor.at(a) = vetor.at(b);
        vetor.at(b) = aux;
    }

    void heapify(){
        int inicio = (floor(vetor.size() / 2.0f)) -1;
        for(int i = inicio; i >= 0; i--) {
            int menor = menorFilho(i);
            if((menor != -1) and (vetor.at(menor < vetor.at(i)))){
                swap(menor,i);
                corrigeDescendo(menor);
            }
        }
    }

    void corrigeDescendo(int indice){
        int menor = menorFilho(indice);
        if((menor != -1) and (vetor.at(menor < vetor.at(indice)))){
            swap(menor,indice);
            corrigeDescendo(menor);
        }
    }

public:
    Heap(int quantidade){
        for(unsigned int i = quantidade; i > 0; i--) {
            vetor.push_back(i);
        }
        heapify();
    }

    void imprimir(){
        for(unsigned int i = 0; i < vetor.size(); i++) {
            cout << vetor.at(i) << " ";
        }
        cout << endl;
        
    }
};

int main(){
    int quantidade;
    cin >> quantidade;
    Heap heap(quantidade);
    heap.imprimir();
    return 0;
}
