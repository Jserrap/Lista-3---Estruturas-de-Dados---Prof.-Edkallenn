/*
** Função :Implemente uma função que classifica os elementos de um vetor em ordem crescente
usando o seguinte algoritmo (conhecido como “classificação por seleção”):
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 04/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void generateRandomArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 10;
    int arr[n];

    generateRandomArray(arr, n);

    printf("Vetor original:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Vetor classificado:\n");
    printArray(arr, n);

    return 0;
}