/*  Um usuário precisa implementar o controle de uma matriz de leds com 8 8 elementos. Para isso,
 ele criou um programa em C dotado de uma matriz da forma
 unsigned char m[8][8];
 para armazenar os estados dos leds. Como existem apenas dois estados possíveis para os leds
 (aceso ou apagado), ele assumiu que leds acessos seriam denotados pelo inteiro "1" nessa matriz
 e leds apagados seriam denotados pelo inteiro "0".
   Ocorre que a função que controla os leds exige que a informação que controla a matriz seja
 enviada via porta serial usando uma função que recebe um único inteiro não sinalizado de
 64 bits. Nesse inteiro, os bytes mais significativos deverão guardar os estados das linhas
 superiores da matriz de leds, enquanto os bytes menos significativos devem guardar os estados
 das linhas inferiores da matriz. Assim, é necessário que cada estado previsto na matriz "m" seja
 codificado em um bit correspondente na variável enviada pela função.
  Crie um programa em linguagem C para realizar essa codificação e explique na forma de
 comentários como sua codificação da matriz "m" na variável de 64 bits foi realizada.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para codificar a matriz em um inteiro de 64 bits
unsigned long long int codificaMatriz(unsigned char m[8][8]) {
    unsigned long long int codificacao = 0;

    //Usada para verificar cada elemento da matriz e definir os bits em codificacao conforme necessário
    unsigned long long int bit = 1;

    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            // Se o LED estiver aceso (1), adicione bit à codificação
            if (m[linha][coluna] == 1) {
                codificacao = codificacao + bit;
            }
            // Multiplica bit por 2 a cada iteração
            bit = bit * 2;
        }
    }
    return codificacao;
}

int main() {
    unsigned char m[8][8];
    unsigned long long int n = 0;
    int i, j;

    // Inicializa a matriz com valores aleatórios
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            m[i][j] = rand() % 2;

    // Imprime a matriz
    printf("Matriz:\n");
    for (i = 0; i < 8; i++) {
        printf("\t");
        for (j = 0; j < 8; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }

    // Chama a função para codificar a matriz
    n = codificaMatriz(m);

    // Imprime a variável de 64 bits
    printf("\nVariável de 64 bits:\n\t%llu\n", n);

    return 0;
}



