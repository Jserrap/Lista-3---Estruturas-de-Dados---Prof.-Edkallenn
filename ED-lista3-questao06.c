/*
** Função : O método de Newton-Raphson é utilizado para calcular aproximadamente raízes de
funções (ou de equações). Ele se baseia na seguinte premissa:
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/
#include <stdio.h>
#include <math.h>

double func(double x) {
    return x * x - 2;
}

double derivFunc(double x) {
    return 2 * x;
}

void newtonRaphson(double x0, double tol, int max_iter) {
    double x = x0;
    int iter = 0;

    while (iter < max_iter) {
        double fx = func(x);
        double dfx = derivFunc(x);
        
        if (fabs(dfx) < 1e-6) {
            printf("Derivada muito próxima de zero, método falhou.\n");
            return;
        }
        
        double x_next = x - fx / dfx;
        
        printf("Iteração %d: x = %lf\n", iter + 1, x_next);
        
        if (fabs(x_next - x) < tol) {
            printf("Convergência alcançada após %d iterações: raiz aproximada = %lf\n", iter + 1, x_next);
            return;
        }
        
        x = x_next;
        iter++;
    }
    
    printf("Número máximo de iterações alcançado. Raiz aproximada = %lf\n", x);
}

int main() {
    double x0;
    double tol;
    int max_iter;

    printf("Digite o palpite inicial: ");
    scanf("%lf", &x0);
    printf("Digite a tolerância: ");
    scanf("%lf", &tol);
    printf("Digite o número máximo de iterações: ");
    scanf("%d", &max_iter);

    newtonRaphson(x0, tol, max_iter);

    return 0;
}