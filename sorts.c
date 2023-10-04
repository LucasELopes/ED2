#include "sorts.h"

void imprimirVetor(int *v, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", v[i]);
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
    int pivo = rand()%fim+1;
    int aux = v[fim];
    v[fim] = v[pivo];
    v[pivo] = aux;
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

void countingSort(int *a, int size, int k) {

    int *b = (int*)calloc(size+1, sizeof(int));
    int *c = (int*)calloc(k+1, sizeof(int));

    for(int i = 0; i < size; i++)
        c[a[i]]++;
    imprimirVetor(c, k+1);

    for(int i = 1; i < size; i++) 
        c[i] += c[i-1];
    imprimirVetor(c, k+1);

    for(int i = size-1; i >= 0; i--) {
        b[c[a[i]]+1] = a[i];
        c[a[i]]--;
    }
    imprimirVetor(b, size);

}

No* criarNo(int chave) {
    No *novoNo = (No*)calloc(1, sizeof(No));
    if(!novoNo) {
        printf("Erro na alocação!\n");
        exit(1);
    }
    novoNo->chave = chave;
    return novoNo;
}

void imprimirArvore(No **A, int nivel) {
    if(*A) {
        for(int i = 0; i < nivel; i++)
            printf("-");
        printf("%d\n", (*A)->chave);
        imprimirArvore(&(*A)->esq, nivel+1);
        imprimirArvore(&(*A)->dir, nivel+1);
    }
}

No* buscar(No **A, int chave, No **pred) {
    No *aux = *A;
    while(aux) {
        if(aux->chave == chave) break;
        else {
            *pred = aux;
            if(aux->chave > chave)
                aux = aux->esq;
            else 
                aux = aux->dir;
        }
    }
    return aux;
}

void inserirArvore(No **A, int chave) {
    No *pred, *aux;

    if(!(*A)) {
        *A = criarNo(chave);
    }
    else {
        aux = buscar(A, chave, &pred);
        
        if(aux) 
            printf("Chave já existe!\n");
        else {
            No *novoNo = criarNo(chave);

            if(pred->chave > chave)
                pred->esq = novoNo;
            else    
                pred->dir = novoNo;
        }
    }
}

No* sucessor(No **A, No **pred) {
    No *aux = *A;
    if(aux) {
        aux = aux->dir;
        while(aux && aux->esq) {
            *pred = aux;
            aux = aux->esq;
        }
        return aux;
    }
    return NULL;
}

void removerNo(No **A, int chave) {
    No *aux, *pred = NULL;
    aux = buscar(A, chave, &pred);

    if(!(*A))
        printf("Empty Tree\n");
    else if(aux){
        if(!aux->dir && !aux->esq) {
            if(!pred)
                free(aux);
            else {
                if(pred->dir == aux)
                    pred->dir = NULL;
                else 
                    pred->esq = NULL;
                free(aux);
            }
        }
        else {
            No *paiSuc = NULL;
            No *suc = sucessor(&aux, &paiSuc);
            if(aux->esq && aux->dir) {
                aux->chave = suc->chave;

                if(!paiSuc)
                    aux->dir = suc->dir;
                else 
                    paiSuc->esq = suc->dir;
                free(suc);
            }
            else {     
                if(pred) {
                    if(pred->dir == aux) {
                        if(suc) 
                            pred->dir = aux->dir;
                        else 
                            pred->dir = aux->esq;
                    }
                    else {
                        if(suc)
                            pred->esq = aux->dir;
                        else 
                            pred->esq = aux->esq;
                    }
                }
                else {
                    if(aux->dir)
                        *A = aux->dir;
                    else
                        *A = aux->esq;
                }
                free(aux);
            }
        }
    }
}



