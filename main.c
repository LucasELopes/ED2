#include "sorts.h"

int main() {
    int v[] = {2, 1, 12, 32, 90, 89, 42, 241, 423, -1, -20, 0};
    // int v[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int size = sizeof(v)/sizeof(v[0]);
    
    imprimirVetor(v, size);
    heapSort(v, size);
    imprimirVetor(v, size);

    return 0;
}