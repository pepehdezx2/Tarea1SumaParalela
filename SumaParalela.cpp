#include <omp.h>
#include <iostream>

#define N 1000
#define chunk 100
#define show 10

void printArray(float *d);

int main() {
    std::cout << "Sumando arreglos de forma paralela\n";
    float arrayA[N], arrayB[N], arrayRes[N];
    int i;

    for(i=0; i<N; i++){
        arrayA[i] = rand() % 100;
        arrayB[i] = rand() % 100;
    }

    int pieces = chunk;

    #pragma omp parallel for \
        shared(arrayA, arrayB, arrayRes, pieces) private(i) \
        schedule(static, pieces)
    for(i=0; i<N; i++){
        arrayRes[i] = arrayA[i] + arrayB[i];
    }

    std::cout << "Imprimiendo los primeros " << show << " valores del arreglo a: " << std::endl;
    printArray(arrayA);
    std::cout << "Imprimiendo los primeros " << show << " valores del arreglo b: " << std::endl;
    printArray(arrayB);
    std::cout << "Imprimiendo los primeros " << show << " valores del arreglo respuesta: " << std::endl;
    printArray(arrayRes);
}

void printArray(float *d) {
    for(int x=0; x<N; x++){
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}