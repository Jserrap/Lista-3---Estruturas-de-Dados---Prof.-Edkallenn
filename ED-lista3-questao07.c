/*
** Função : Implemente uma função que classifica os elementos de um vetor em ordem crescente
usando o algoritmo “quicksort”, que pode ser estabelecido da forma a seguir:
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int i = inicio, j = fim;
        int pivo = vetor[(inicio + fim) / 2];
        while (i <= j) {
            while (vetor[i] < pivo) i++;
            while (vetor[j] > pivo) j--;
            if (i <= j) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                i++;
                j--;
            }
        }
        quicksort(vetor, inicio, j);
        quicksort(vetor, i, fim);
    }
}

void imprimirVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = 10;
    int vetor[tamanho];

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // Gera valores aleatórios entre 0 e 99
    }

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    quicksort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}