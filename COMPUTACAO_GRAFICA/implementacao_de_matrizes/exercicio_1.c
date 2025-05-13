#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matriz.h"

/**
 * Tarefa: Questões dos slides e implementação de Tranformações Geométricas PT.2
 * Aluno: Luis Izaías Valentim de Aquino
 *
 * Realize as operações a seguir:

    - Multiplique a matriz m = {{9,-7}, {-3,5}} pelo escalar -1;
    - subtraia as matrizes A = {{9,-7}, {-3,5}} e B {{-7, 3}, {-5 , 8}}

    Execução:
    > gcc -c matriz.c -o matriz.o
    > gcc exercicio_1.c  matriz.o -o ex1
    > ./ex1.exe
 */

int main()
{
    float m1[2][2] = {{9, -7}, {-3, 5}};
    float m2[2][2] = {{-7, 3}, {-5, 8}};
    int escalar = -1;

    printf("Multiplique a matriz m = {{9,-7}, {-3,5}} pelo escalar -1: \n");

    // Criação da matriz
    Matriz *M1 = cria_matriz(2, 2);
    M1->matriz[0] = m1[0];
    M1->matriz[1] = m1[1];
    Matriz *M1_E = multiplica_matriz_por_escalar(M1, escalar);
    imprime_matriz(*M1_E);

    printf("Subtraia as matrizes A = {{9,-7}, {-3,5}} e B {{-7, 3}, {-5 , 8}}:\n ");

    Matriz *M2 = cria_matriz(2, 2);
    M2->matriz[0] = m2[0];
    M2->matriz[1] = m2[1];
    Matriz *resultado = subtrai_matrizes(M1, M2);
    imprime_matriz(*resultado);

    return 0;
}
