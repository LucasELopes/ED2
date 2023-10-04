#include "sorts.h"

int main() {
    // int v[] = {2, 1, 12, 32, 90, 89, 42, 241, 423, -1, -20, 0};
    // int v[] = {2, 5, 3 ,0, 2, 3, 0, 3};
    // int size = sizeof(v)/sizeof(v[0]);
    
    No *A = NULL;
    inserirArvore(&A, 12);
    inserirArvore(&A, 11);
    inserirArvore(&A, 8);

    imprimirArvore(&A, 0);
    printf("\n");
    removerNo(&A, 12);
    imprimirArvore(&A, 0);
    printf("\n");

    return 0;
}