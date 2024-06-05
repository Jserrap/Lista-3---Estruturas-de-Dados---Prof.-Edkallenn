/*
** Função :Defina um registro (estrutura - struct) empregado para armazenar os dados (nome, data de
nascimento, RG, data de admissão e salário)de um empregado de uma empresa. Criar um
novo tipo de dados chamado Empregado usando a estrutura empregado. Defina um vetor
de empregados (usando alocação dinâmica) para armazenar todos os empregados de sua
empresa. Implementar rotinas para ler, escrever e excluir registros deste tipo.
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 04/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char dataNascimento[11];
    char rg[15];
    char dataAdmissao[11];
    float salario;
} Empregado;

void lerEmpregado(Empregado *emp) {
    printf("Nome: ");
    fgets(emp->nome, 50, stdin);
    emp->nome[strcspn(emp->nome, "\n")] = '\0';

    printf("Data de nascimento (dd/mm/yyyy): ");
    fgets(emp->dataNascimento, 11, stdin);
    emp->dataNascimento[strcspn(emp->dataNascimento, "\n")] = '\0';

    printf("RG: ");
    fgets(emp->rg, 15, stdin);
    emp->rg[strcspn(emp->rg, "\n")] = '\0';

    printf("Data de admissão (dd/mm/yyyy): ");
    fgets(emp->dataAdmissao, 11, stdin);
    emp->dataAdmissao[strcspn(emp->dataAdmissao, "\n")] = '\0';

    printf("Salário: ");
    scanf("%f", &emp->salario);
    getchar();
}

void imprimirEmpregado(const Empregado *emp) {
    printf("Nome: %s\n", emp->nome);
    printf("Data de nascimento: %s\n", emp->dataNascimento);
    printf("RG: %s\n", emp->rg);
    printf("Data de admissão: %s\n", emp->dataAdmissao);
    printf("Salário: %.2f\n", emp->salario);
}

void excluirEmpregado(Empregado **empregados, int *n, int index) {
    if (index < 0 || index >= *n) {
        printf("Índice inválido!\n");
        return;
    }

    for (int i = index; i < *n - 1; i++) {
        (*empregados)[i] = (*empregados)[i + 1];
    }

    (*n)--;
    *empregados = realloc(*empregados, (*n) * sizeof(Empregado));
    if (*empregados == NULL && *n > 0) {
        printf("Erro ao realocar memória!\n");
        exit(1);
    }
}

int main() {
    int n = 0;
    Empregado *empregados = NULL;
    int opcao, index;

    do {
        printf("1. Adicionar empregado\n");
        printf("2. Listar empregados\n");
        printf("3. Excluir empregado\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                n++;
                empregados = realloc(empregados, n * sizeof(Empregado));
                if (empregados == NULL) {
                    printf("Erro ao alocar memória!\n");
                    exit(1);
                }
                lerEmpregado(&empregados[n - 1]);
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    printf("Empregado %d:\n", i + 1);
                    imprimirEmpregado(&empregados[i]);
                }
                break;
            case 3:
                printf("Índice do empregado a ser excluído (1 a %d): ", n);
                scanf("%d", &index);
                getchar();
                excluirEmpregado(&empregados, &n, index - 1);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    free(empregados);

    return 0;
}