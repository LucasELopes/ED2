#ifndef INCLUDED_SORTS_H
#define INCLUDED_SORTS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirVetor(int *v, int size);

void bubbleSort(int *v, int size); 

void insertionSort(int *v, int size);

void selectionSort(int *v, int size);

void merge(int *v, int ini, int meio, int fim);
void mergeSort(int *v, int ini, int fim);

int particiona(int *v, int ini, int fim);
int randParticion(int *v, int ini, int fim);
void quickSort(int *v, int ini, int fim);

void maxHeapify(int *v, int size, int index);
void heapSort(int *v, int size);

void countingSort(int *a, int size, int k);

//Árvore binária de busca.
typedef struct no {
    int chave;
    struct no *dir, *esq;
}No;

No* criarNo(int chave);
void imprimirArvore(No **A, int nivel);
No* buscar(No **A, int chave, No **pred);
void inserirArvore(No **A, int chave);
void removerNo(No **A, int chave);
No* sucessor(No **A, No **pred);

#endif