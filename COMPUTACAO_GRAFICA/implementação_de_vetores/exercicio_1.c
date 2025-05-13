#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "v_vector.h"

/**
 * Tarefa: Questões dos slides e implementação de vetores
 * Aluno: Luis Izaías Valentim de Aquino
 * 
 *Encontre o vetor a partir dos pontos abaixo:
    a =(2,4) e b = (6,2);
    a =(6,7) e b = (−1,−2);
    a =(2,2,4) e b = (1,1,1);
    a =(−2,4,−5) e b = (5,2,−5);

    Execução:
    > gcc -c b_vector.c -o b_vector.o
    > gcc exercicio_1.c  b_vector.o -o ex1
    > ./ex1.exe
 */

int main()
{
    // Definindo os pontos a e b como arrays de inteiros.
    printf("Exercicio 1 - Vetores resultantes: \n\n");
    int a1[] = {2, 4};
    int b1[] = {6, 2};

    int a2[] = {6, 7};
    int b2[] = {-1, -2};

    int a3[] = {2, 2, 4};
    int b3[] = {1, 1, 1};

    int a4[] = {-2, 4, -5};
    int b4[] = {5, 2, -5};

    Vetor *v1 = encontrar_vetor(a1, b1, 2);
    Vetor *v2 = encontrar_vetor(a2, b2, 2);
    Vetor *v3 = encontrar_vetor(a3, b3, 3);
    Vetor *v4 = encontrar_vetor(a4, b4, 3);

    printf("\nVetor 1: ");
    imprimir_vetor(v1);
    printf("\nVetor 2: ");
    imprimir_vetor(v2);
    printf("\nVetor 3: ");
    imprimir_vetor(v3);
    printf("\nVetor 4: ");
    imprimir_vetor(v4);
}