#include "sorts.h"

void imprimirVetor(int *v, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void bubbleSort(int *v, int size) {
    int valor;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(v[j+1] < v[j]) {
                valor = v[j+1];
                v[j+1] = v[j];
                v[j] = valor;
            }
        }
    }
}

void insertionSort(int *v, int size) {
    int valor;
    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j > 0; j--) {
            if(v[j-1] > v[j]) {
                valor = v[j-1];
                v[j-1] = v[j];
                v[j] = valor;
            }
        }
    }
}

void selectionSort(int *v, int size) {
    int valor;
    for(int i = 0; i < size; i++) {
        valor = v[i];
        for(int j = i; j < size; j++) {
            if(valor > v[j]) {
                valor = v[j];
                v[j] = v[i];
                v[i] = valor;
            }
            
        }
    }
}

void merge(int *v, int ini, int meio, int fim) {
    int i = ini, j = meio+1, k = 0, size = (fim-ini)+1;
    int *vAux = (int*)calloc(size, sizeof(int));

    while(k < size) {
        if(i <= meio && j <= fim) {
            if(v[i] < v[j])
                vAux[k] = v[i++];
            else    
                vAux[k] = v[j++];
        }
        else {
            if(i <= meio) 
                vAux[k] = v[i++];
            else        
                vAux[k] = v[j++];
        }
        k++;
    } 

    k = 0; i = ini;
    
    while(k < size)
        v[i++] = vAux[k++];
    
    free(vAux);
}

void mergeSort(int *v, int ini, int fim) {
    if(ini < fim) {
        int meio = (fim+ini)/2;
        mergeSort(v, ini, meio);
        mergeSort(v, meio+1, fim);
        merge(v, ini, meio, fim);
    }
}

int particiona(int *v, int ini, int fim) {
    int i = ini-1, pivo = v[fim];
    int aux;

    for(int j = ini; j < fim; j++) {
        if(v[j] <= pivo) {
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    v[fim] = v[i+1];
    v[i+1] = pivo; 
    return i+1;
}

int randParticion(int *v, int ini, int fim) {
    int i = rand()%fim+1;
    int aux = v[ini];
    v[ini] = v[i];
    v[i] = aux;
    return particiona(v, ini, fim);
}

void quickSort(int *v, int ini, int fim) {
    if(ini < fim) {
        int pivo = randParticion(v, ini, fim);
        quickSort(v, ini, pivo-1);
        quickSort(v, pivo+1, fim);
    }
}

void maxHeapify(int *v, int size, int index) {
    int l = index*2+1;
    int r = index*2+2;
    int aux, maior;

    if(l < size && v[l] > v[index])
        maior = l;
    else 
        maior = index;
    if(r < size && v[r] > v[index])
        maior = r;
    if(index != maior) {
        aux = v[maior];
        v[maior] = v[index];
        v[index] = aux;
    }
}

void heapSort(int *v, int size) {
    for(int i = (size-1)/2; i >= 0; i--) {
        maxHeapify(v, size, i);
    }
}