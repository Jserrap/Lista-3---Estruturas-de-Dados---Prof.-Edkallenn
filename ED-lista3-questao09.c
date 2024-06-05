/*
** Função : Crie uma função para ordenar elementos de um vetor (pode ser de inteiros ou reais)
usando o "método BubbleSort" (ordenação Bolha). Em seguida realize a CONTAGEM do
números de if's realizados e a quantidade de trocas realizadas. Mostre, ao final, após o
vetor estar ordenado, a quantidade de if's e de trocas realizadas. Use a função em umprograma que solicita a quantidade de elementos do vetor para o usuário e preenche este
vetor com valores aleatórios
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *vetor, int tamanho, int *contagemIfs, int *contagemTrocas) {
    int i, j, temp;
    *contagemIfs = 0;
    *contagemTrocas = 0;
    
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            (*contagemIfs)++;
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*contagemTrocas)++;
            }
        }
    }
}

void imprimirVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;
    int contagemIfs, contagemTrocas;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // Gera valores aleatórios entre 0 e 99
    }

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    bubbleSort(vetor, tamanho, &contagemIfs, &contagemTrocas);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    printf("Numero de comparacoes (ifs): %d\n", contagemIfs);
    printf("Numero de trocas: %d\n", contagemTrocas);

    free(vetor);

    return 0;
}