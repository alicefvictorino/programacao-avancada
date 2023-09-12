/*
Implemente em linguagem C uma função em um programa de computador que leia n valores do
tipo float e os apresente em ordem crescente. Utilize alocação dinâmica de memória para
realizar a tarefa.
*/

#include <stdlib.h>
#include <stdio.h>

void ordenaValores(int n) {
    float *p, aux;

    p = (float*) malloc(n * sizeof(float));

    printf("Digite os valores: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &p[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%f ", p[i]);
    }

    free(p);
    p = NULL;

}

int main() {
    int n;

    printf("Digite o numero de valores: ");
    scanf("%d", &n);

    ordenaValores(n);

    return 0;
}