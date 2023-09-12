/* 
Utilize a ideia do ponteiro para função pela função qsort() para implementar sua própria função
de ordenação, mas que seja capaz de ordenar apenas inteiros do tipo int. Para isso, sua função
deverá receber, entre outros argumentos, um ponteiro para a função de comparação que
determinará como os elementos do array serão ordenados.
*/


#include <stdlib.h>
#include <stdio.h>

// função que compara os valores para o qsort
int compararValores(const void *a, const void *b) {
    if (*(int*)a == *(int*)b) {
        return 0;
    } else if (*(int*)a < *(int*)b) {
        return -1;
    } else {
        return 1;
    }
}

void qsort_inteiros(int *array, int tamanho, int (*comparar)(const int *, const int *)) {
    int temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (comparar(&array[j], &array[j + 1]) > 0) {
                // Troca os elementos se estiverem fora de ordem
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// ordena os valores do array
void ordenaValores(int n) {
    int *p, aux;

    // alocação de memória
    p = (int*) malloc(n * sizeof(int));

    // preenchimento do array
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // faz a ordenação dos valores
    qsort_inteiros(p, n, compararValores);

    // imprime os valores ordenados
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
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