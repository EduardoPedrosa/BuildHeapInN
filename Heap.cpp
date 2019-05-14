#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
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

public:
    Heap(int quantidade, bool randomico){
        vetor = new int[quantidade];
        size = 0;
        if(randomico){
            srand(time(0));
            for(unsigned int i = quantidade; i > 0; i--) {
                vetor[size] = rand();
                size++;
            }
        } else {
            for(unsigned int i = quantidade; i > 0; i--) {
                vetor[size] = i;
                size++;
            }
        }
    }
    
    ~Heap(){
        delete[] vetor;
    }

    void imprimir(){
        for(unsigned int i = 0; i < size; i++) {
            cout << vetor[i] << " ";
        }
        cout << endl;
        
    }
    
    void heapify(){
        int inicio = (floor(size / 2.0f)) -1;
        for(int i = inicio; i >= 0; i--) {
            int menor = menorFilho(i);
            if((menor != -1) and (vetor[menor] < vetor[i])){
                swap(menor,i);
                int menorF = menorFilho(menor);
                bool acabou = false;
                while((menorF != -1)&&(!acabou)){
					if(vetor[menorF] < vetor[menor]){
						swap(menorF,menor);
						menor = menorF;
						menorF = menorFilho(menor);
					} else {
						acabou = true;
					}
				}
            }
        }
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
    //system("clear");
    cout << "1) Testar com numeros randomicos" << endl;
    cout << "2) Testar no pior caso (numeros decrescentes)" << endl;
    int opcao;
    cin >> opcao;
    bool randomico = false;
    if(opcao == 1)
        randomico = true;
    ofstream arq("saida.txt");
    clock_t inicioT,fimT;
    inicioT = clock();
    double somaT = 0;
    for (int i = 1; i< pow(10,6); i+=100) {
        Heap heap(i,randomico);
        clock_t inicio, fim;
        inicio = clock();
        heap.heapify();
        fim = clock();
        double tempoIteracao = (double)(fim-inicio)/CLOCKS_PER_SEC;
        somaT += tempoIteracao;
        arq << i << "," << tempoIteracao << endl;
    }
    fimT = clock();
    cout << "Execucao finalizada" << endl;
    cout << "Tempo total: " << (double)(fimT-inicioT)/CLOCKS_PER_SEC << " segundos" << endl;
    cout << "Tempo gasto no heapify: " << somaT << " segundos" << endl;
    return 0;
}
