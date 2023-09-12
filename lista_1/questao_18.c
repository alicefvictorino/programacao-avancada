/*
 Crie uma função capaz de realizar multiplicação matricial da forma C = AxB. A função deve
receber 6 argumentos: os ponteiros para as matrizes A, B e C, o número de linhas e colunas de A
e o número de colunas de B (assuma que o número de coluna de A é igual ao número de linhas
de B). O resultado da multiplicação deve ficar armazenado em C. Crie um programa para testar
sua implementação, capaz de utilizar a função de multiplicação e imprimir as três matrizes. A
função criada para multiplicação não deve realizar nenhum tipo de saída de dados no terminal.
Exemplo: para multiplicar duas matrizes (A e B) de dimensões 2x3 e 3x4, respectivamente (o
resultado deve ficar armazenado em C).
multiplica_matrizes(A, B, C, 2, 3, 4)
*/

#include <stdlib.h> 
#include <stdio.h>

// função que multiplica duas matrizes
void multiplica_matrizes(int *A, int *B, int *C, int nl_A, int nc_A, int nc_B){
    
    for(int i = 0; i < nl_A; i++){
        for(int j = 0; j < nc_B; j++){
            *(C + (i*nc_B + j)) = 0;
            for(int k = 0; k < nc_A; k++){
                *(C + (i*nc_B + j)) += *(A + (i*nc_A + k)) * *(B + (k*nc_B + j));
            }
        }
    }
}

int main() {
    int *A, *B, *C, nl_A, nc_A, nl_B, nc_B;

    printf("Digite o numero de linhas da matriz A: ");
    scanf("%d", &nl_A);

    printf("Digite o numero de colunas da matriz A: ");
    scanf("%d", &nc_A);

    printf("Digite o numero de colunas da matriz B: ");
    scanf("%d", &nc_B);

    nl_B = nc_A;

// alocação dinâmica de memória e preenchimento das matrizes A e B
    A = (int *) malloc(nl_A * nc_A * sizeof(int *));
    for(int i = 1; i < nl_A; i++){
        A[i] = A[i-1] + nc_A;
    }

    for(int i = 0; i < nl_A; i++){
        for(int j = 0; j < nc_A; j++){
            printf("Digite o elemento A[%d][%d]: ", i, j);
            scanf("%d", &A[i*nc_A + j]);
        }
    }

    B = (int *) malloc(nl_B * nc_B * sizeof(int *));
    for(int i = 1; i < nl_B; i++){
        B[i] = B[i-1] + nc_B;
    }

    for(int i = 0; i < nl_B; i++){
        for(int j = 0; j < nc_B; j++){
            printf("Digite o elemento B[%d][%d]: ", i, j);
            scanf("%d", &B[i*nc_B + j]);
        }
    }

// alocação dinâmica de memória para a matriz C
    C = (int *) malloc(nl_A * nc_B * sizeof(int *));
    for(int i = 1; i < nl_A; i++){
        C[i] = C[i-1] + nc_B;
    }

    multiplica_matrizes(A, B, C, nl_A, nc_A, nc_B);

// impressão da matriz C
    printf("Matriz C:\n");
    for(int i = 0; i < nl_A; i++){
        for(int j = 0; j < nc_B; j++){
            printf("%d ", C[i*nc_B + j]);
        }
        printf("\n");
    }

// liberação de memória das matrizes A, B e C
    free(A);
    free(B);
    free(C);

    return 0;
}