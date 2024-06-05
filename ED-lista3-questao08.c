/*
** Função : Crie um novo TAD (Tipo Abstrato de Dado) de arquivo único chamado Complexo para
realizar aritmética com números complexos. Utilize variáveis double para representar os
campos deste tipo. Implemente funções para as seguintes operações: criar e destruir um
número complexo; ler um número complexo, somar dois números complexos, subtrair dois
números complexos, multiplicar dois números complexos, dividir dois números complexos,
mostrar um número complexo na forma (a,b) onde a é a parte real e b, a parte imaginária.
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imaginario;
} Complexo;

Complexo* criarComplexo(double real, double imaginario) {
    Complexo* c = (Complexo*)malloc(sizeof(Complexo));
    if (c != NULL) {
        c->real = real;
        c->imaginario = imaginario;
    }
    return c;
}

void destruirComplexo(Complexo* c) {
    if (c != NULL) {
        free(c);
    }
}

Complexo* lerComplexo() {
    double real, imaginario;
    printf("Digite a parte real: ");
    scanf("%lf", &real);
    printf("Digite a parte imaginaria: ");
    scanf("%lf", &imaginario);
    return criarComplexo(real, imaginario);
}

Complexo* somarComplexos(Complexo* c1, Complexo* c2) {
    return criarComplexo(c1->real + c2->real, c1->imaginario + c2->imaginario);
}

Complexo* subtrairComplexos(Complexo* c1, Complexo* c2) {
    return criarComplexo(c1->real - c2->real, c1->imaginario - c2->imaginario);
}

Complexo* multiplicarComplexos(Complexo* c1, Complexo* c2) {
    double real = c1->real * c2->real - c1->imaginario * c2->imaginario;
    double imaginario = c1->real * c2->imaginario + c1->imaginario * c2->real;
    return criarComplexo(real, imaginario);
}

Complexo* dividirComplexos(Complexo* c1, Complexo* c2) {
    double denom = c2->real * c2->real + c2->imaginario * c2->imaginario;
    if (denom == 0) {
        printf("Erro: Divisao por zero!\n");
        return NULL;
    }
    double real = (c1->real * c2->real + c1->imaginario * c2->imaginario) / denom;
    double imaginario = (c1->imaginario * c2->real - c1->real * c2->imaginario) / denom;
    return criarComplexo(real, imaginario);
}

void mostrarComplexo(Complexo* c) {
    if (c != NULL) {
        printf("(%lf, %lf)\n", c->real, c->imaginario);
    }
}

int main() {
    Complexo* c1 = lerComplexo();
    Complexo* c2 = lerComplexo();

    Complexo* soma = somarComplexos(c1, c2);
    Complexo* subtracao = subtrairComplexos(c1, c2);
    Complexo* multiplicacao = multiplicarComplexos(c1, c2);
    Complexo* divisao = dividirComplexos(c1, c2);

    printf("Soma: ");
    mostrarComplexo(soma);

    printf("Subtracao: ");
    mostrarComplexo(subtracao);

    printf("Multiplicacao: ");
    mostrarComplexo(multiplicacao);

    printf("Divisao: ");
    mostrarComplexo(divisao);

    destruirComplexo(c1);
    destruirComplexo(c2);
    destruirComplexo(soma);
    destruirComplexo(subtracao);
    destruirComplexo(multiplicacao);
    destruirComplexo(divisao);

    return 0;
}