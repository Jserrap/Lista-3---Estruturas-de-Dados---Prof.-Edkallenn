/*
** Função :Refaça o programa anterior (com outro nome) para que o computador teste de 2 até um
número N informado pelo usuário
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/

#include <stdio.h>

int ehPrimo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N;

    printf("Digite o valor de N: ");
    scanf("%d", &N);

    if (N < 4 || N % 2 != 0) {
        printf("N deve ser um número par maior ou igual a 4.\n");
        return 1;
    }

    printf("Testando a Conjectura de Goldbach para todos os números pares de 2 a %d:\n\n", N);

    for (int num = 4; num <= N; num += 2) {
        printf("Numero par: %d\n", num);

        for (int i = 2; i <= num / 2; i++) {
            if (ehPrimo(i) && ehPrimo(num - i)) {
                printf("%d + %d\n", i, num - i);
                break;
            }
        }
        printf("\n");
    }

    return 0;
}