/* 
Reimplemente o programa da questão anterior utilizando a função qsort() do C. Comente o seu
código, explicando o que faz cada uma das linhas.
*/

#include <stdlib.h>
#include <stdio.h>

// função que compara os valores para o qsort
int compararValores(const void *a, const void *b) {
    if (*(float*)a == *(float*)b) {
        return 0;
    } else if (*(float*)a < *(float*)b) {
        return -1;
    } else {
        return 1;
    }
}


// ordena os valores do array
void ordenaValores(int n) {
    float *p, aux;

    // alocação de memória
    p = (float*) malloc(n * sizeof(float));

    // preenchimento do array
    for (int i = 0; i < n; i++) {
        scanf("%f", &p[i]);
    }

    // faz a ordenação dos valores
    qsort(p, n, sizeof(float), compararValores);

    // imprime os valores ordenados
    for (int i = 0; i < n; i++) {
        printf(" %f ", p[i]);
    }

    // libera a memória
    free(p);
    p = NULL;

}

int main() {
    int n;

    // entrada da quantidade de números
    printf("Digite o numero de valores: ");
    scanf("%d", &n);

    ordenaValores(n);

    return 0;
}