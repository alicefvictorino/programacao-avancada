/* Um programador precisa desenvolver uma aplicação em linguagem C para manipular matrizes
capazes de armazenar representações de modelos tridimensionais.
Entende-se que o tamanho da matriz é definido pelo usuário e esta deve ser alocada em tempo
de execução. O processo de criar um modelo na matriz consiste em atribuir aos seus elementos
os valores inteiros “1” ou “0” para simbolizar que há ou não parte do modelo naquela posição.
Uma analogia para o modelo seria que a criação funciona como no jogo "Minecraft", onde "0"
representaria a ausência de objeto e "1" representaria a presença de objetos.
Nesta aplicação, as matrizes devem ser definidas como tipos de dados int. Isto posto, pede-se
que o programador prepare os algoritmos de alocação dinâmica para guardar os dados da
matriz tridimensional e crie um programa de testes para verificar se a sua implementação foi
realizada corretamente de modo a garantir as seguintes condições:
O usuário do programa de testes deverá poder fornecer o tamanho da matriz tridimensional
que deseja manipular, inserindo as dimensões da altura, largura e profundidade desta. O
programador deverá inserir no seu código comentários para indicar como as posições da matriz
poderão ser acessadas.
Crie um programa com testes que mostrem que sua implementação funciona corretamente */

#include <stdio.h>
#include <stdlib.h>

int ***alocacaoDeMatriz(int altura, int largura, int profundidade){
    int i, j;
    int ***matriz = (int ***) malloc(altura * sizeof(int **));

    //O i representa a altura, o j a largura e o k a profundidade
    for(i = 0; i < altura; i++){
        matriz[i] = (int **) malloc(largura * sizeof(int *));
        for(j = 0; j < largura; j++){
            matriz[i][j] = (int *) malloc(profundidade * sizeof(int));
        }
    }
    return matriz;
}

//Função para liberar a memória alocada para a matriz
void freeMatriz(int altura, int largura, int profundidade, int ***matriz){
    int i, j;

    for(i = 0; i < altura; i++){
        for(j = 0; j < largura; j++){
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);
}


int main(){
    int altura, largura, profundidade;
    
    printf("Altura da matriz: ");
    scanf("%d", &altura);
    printf("Largura da matriz: ");
    scanf("%d", &largura);
    printf("Profundidade da matriz: ");
    scanf("%d", &profundidade);

    //Alocando a matriz
    int ***matriz = alocacaoDeMatriz(altura, largura, profundidade);

    //Acessar e preencher os elementos da matriz
    int i, j, k;
    for(i = 0; i < altura; i++){
        for(j = 0; j < largura; j++){
            for(k = 0; k < profundidade; k++){
                matriz[i][j][k] = 1;
            }
        }
    }

    //Imprimir a matriz
    printf("\nMatriz:\n");
    for(i = 0; i < altura; i++){
        for(j = 0; j < largura; j++){
            for(k = 0; k < profundidade; k++){
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    //Liberar a memória alocada para a matriz
    freeMatriz(altura, largura, profundidade, matriz);

    return 0;
}