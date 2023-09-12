/*
Escreva uma função em linguagem C que escreva em um vetor a soma dos elementos
correspondentes de outros dois vetores (os tamanhos dos vetores devem ser fornecidos pelo
usuário). Por exemplo, se o primeiro vetor contiver os elementos 1, 3, 0 e -2, e o segundo vetor
contiver os elementos 3, 5, -3 e 1, o vetor de soma terá valores resultantes iguais a 4, 8, -3 e -1. A
função deve receber 4 argumentos: os nomes dos três vetores e o número de elementos
presentes em cada vetor. Exemplo:
soma_vetores(vet1, vet2, resultado, 4)
*/

#include <stdlib.h>
#include <stdio.h>

void soma_vetores(int *p1, int *p2, int *ps, int tam_vetor){
    for(int i = 0; i < tam_vetor; i++) {
        ps[i] = p1[i] + p2[i];
    }

    printf("O vetor soma dos valores é: \n");
    for(int i = 0; i < tam_vetor; i++) {
        printf("%d ", ps[i]);
    }
}

int main() {
    int tam_vetor;
    int *p1, *p2, *ps;

    printf("Digite o número de valores dos vetores ");
    scanf("%d", &tam_vetor);

    p1 = (int *) malloc(tam_vetor * sizeof(int));

    for(int i = 0; i < tam_vetor; i++) {
        printf("Digite o valor %d do primeiro vetor: ", i);
        scanf("%d", &p1[i]);
    }

    p2 = (int *) malloc(tam_vetor * sizeof(int));

    for(int i = 0; i < tam_vetor; i++) {
        printf("Digite o valor %d do segundo vetor: ", i);
        scanf("%d", &p2[i]);
    }

    ps = (int *) malloc(tam_vetor * sizeof(int));

    soma_vetores(p1, p2, ps, tam_vetor);

    free(p1);
    free(p2);
    free(ps);

    return 0;

}