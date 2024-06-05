/*
** Função :Suponha que uma empresa aérea mantém um cadastro de aeroportos como um vetor de
ponteiros para estruturas que contêm as seguintes informações:
a. Sigla: string com até 3 caracteres;
b.Cidade: string com até 50 caracteres;
c.Pais: string com até 30caracteres;
d.Taxa: um valor real;
e.Capacidade: um valor inteiro;
Defina uma estrutura em C com o nome de aeroporto, que tenha os campos apropriados
para guardar todas as informações descritas anteriormente. Defina também um novo tipo
de dados com o nome de Aeroporto, correspondendo a essa estrutura. Defina um vetor de
Aeroportos (usando alocação dinâmica para a quantidade de aeroportos) para armazenar
todos os aeroportos que a empresa aérea trabalha. Implementar rotinas para ler, escrever e
excluir registros deste tipo
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 04/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sigla[4];  // String com até 3 caracteres, mais o caractere nulo
    char cidade[51];  // String com até 50 caracteres, mais o caractere nulo
    char pais[31];  // String com até 30 caracteres, mais o caractere nulo
    float taxa;
    int capacidade;
} Aeroporto;

void lerAeroporto(Aeroporto *aeroporto) {
    printf("Sigla (3 caracteres): ");
    fgets(aeroporto->sigla, 4, stdin);
    aeroporto->sigla[strcspn(aeroporto->sigla, "\n")] = '\0';

    printf("Cidade: ");
    fgets(aeroporto->cidade, 51, stdin);
    aeroporto->cidade[strcspn(aeroporto->cidade, "\n")] = '\0';

    printf("Pais: ");
    fgets(aeroporto->pais, 31, stdin);
    aeroporto->pais[strcspn(aeroporto->pais, "\n")] = '\0';

    printf("Taxa: ");
    scanf("%f", &aeroporto->taxa);
    getchar();

    printf("Capacidade: ");
    scanf("%d", &aeroporto->capacidade);
    getchar();
}

void imprimirAeroporto(const Aeroporto *aeroporto) {
    printf("Sigla: %s\n", aeroporto->sigla);
    printf("Cidade: %s\n", aeroporto->cidade);
    printf("Pais: %s\n", aeroporto->pais);
    printf("Taxa: %.2f\n", aeroporto->taxa);
    printf("Capacidade: %d\n", aeroporto->capacidade);
}

void excluirAeroporto(Aeroporto **aeroportos, int *n, int index) {
    if (index < 0 || index >= *n) {
        printf("Índice inválido!\n");
        return;
    }

    free(aeroportos[index]);
    for (int i = index; i < *n - 1; i++) {
        aeroportos[i] = aeroportos[i + 1];
    }

    (*n)--;
    aeroportos = realloc(aeroportos, (*n) * sizeof(Aeroporto *));
    if (aeroportos == NULL && *n > 0) {
        printf("Erro ao realocar memória!\n");
        exit(1);
    }
}

int main() {
    int n = 0;
    Aeroporto **aeroportos = NULL;
    int opcao, index;

    do {
        printf("1. Adicionar aeroporto\n");
        printf("2. Listar aeroportos\n");
        printf("3. Excluir aeroporto\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                n++;
                aeroportos = realloc(aeroportos, n * sizeof(Aeroporto *));
                if (aeroportos == NULL) {
                    printf("Erro ao alocar memória!\n");
                    exit(1);
                }
                aeroportos[n - 1] = malloc(sizeof(Aeroporto));
                if (aeroportos[n - 1] == NULL) {
                    printf("Erro ao alocar memória!\n");
                    exit(1);
                }
                lerAeroporto(aeroportos[n - 1]);
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    printf("Aeroporto %d:\n", i + 1);
                    imprimirAeroporto(aeroportos[i]);
                }
                break;
            case 3:
                printf("Índice do aeroporto a ser excluído (1 a %d): ", n);
                scanf("%d", &index);
                getchar();
                excluirAeroporto(aeroportos, &n, index - 1);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    for (int i = 0; i < n; i++) {
        free(aeroportos[i]);
    }
    free(aeroportos);

    return 0;
}