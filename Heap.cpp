#include <iostream>
#include <cmath>

using namespace std;

class Heap {
private:
    int* vetor;
    int size;
    int filhoDireita(int indice){
        int result = (indice * 2 + 1) + 1;
        return result >= size ? -1 : result;
    }

    int filhoEsquerda(int indice){
        int result = (indice * 2 + 1);
        return result >= size ? -1 : result;
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
        return (vetor[esquerda]) < (vetor[direita]) ? esquerda : direita;
    }

    void swap(int a, int b){ //troca os elementos do vetor que estão nas posicoes passadas por parametro
        int aux = vetor[a];
        vetor[a] = vetor[b];
        vetor[b] = aux;
    }

    void heapify(){
        int inicio = (floor(size / 2.0f)) -1;
        for(int i = inicio; i >= 0; i--) {
            int menor = menorFilho(i);
            if((menor != -1) and (vetor[menor] < vetor[i])){
                swap(menor,i);
                corrigeDescendo(menor);
            }
        }
    }

    void corrigeDescendo(int indice){
        int menor = menorFilho(indice);
        if((menor != -1) and (vetor[menor] < vetor[indice])){
            swap(menor,indice);
            corrigeDescendo(menor);
        }
    }

public:
    Heap(int quantidade){
        vetor = new int[quantidade];
        size = 0;
        for(unsigned int i = quantidade; i > 0; i--) {
            size++;
            vetor[size-1] = i;
        }
        heapify();
    }

    void imprimir(){
        for(unsigned int i = 0; i < size; i++) {
            cout << vetor[i] << " ";
        }
        cout << endl;
        
    }

    bool isHeap(){
        for (int i=0; i<=(size-2)/2; i++) 
        { 
            if (vetor[2*i +1] < vetor[i]) {
                    cout << "Nao e um heap" << endl;
                    return false; 
            }
     
            if (2*i+2 < size && vetor[2*i+2] < vetor[i]) {
                    cout << "Nao e um heap" << endl;
                    return false; 
            }
        } 
        cout << "E um heap" << endl;
        return true; 
    } 
};

int main(){
    int quantidade;
    cin >> quantidade;
    Heap heap(quantidade);
    //heap.isHeap();
    //heap.imprimir();
    return 0;
}
