#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "v_vector.h"

/**
 * Tarefa: Questões dos slides e implementação de vetores
 * Aluno: Luis Izaías Valentim de Aquino
 *
 * Exercícios: Encontre a norma dos vetores abaixo.
    a =<2,−5 >;
    b =<4,2 >;
    c =<3,5,−6 >;
    d =<6,−2,1 >;

    Execução:
    > gcc -c b_vector.c -o b_vector.o
    > gcc exercicio_2.c  b_vector.o -o ex2
    > ./ex2.exe
 */

int main()
{
    // Criando os vetores a, b, c e d.
    int a[] = {2, -5};
    int b[] = {4, 2};
    int c[] = {3, 5, -6};
    int d[] = {6, -2, 1};

    Vetor v_a = criar_vetor(a, 2);
    Vetor v_b = criar_vetor(b, 2);
    Vetor v_c = criar_vetor(c, 3);
    Vetor v_d = criar_vetor(d, 3);

    // Executando a função norma_vetor para calcular a norma dos vetores.
    printf("Exercicio 2 - Normas dos vetores: \n\n");
    printf("Norma do vetor a: %.2f\n", norma_vetor(v_a));
    printf("Norma do vetor b: %.2f\n", norma_vetor(v_b));
    printf("Norma do vetor c: %.2f\n", norma_vetor(v_c));
    printf("Norma do vetor d: %.2f\n", norma_vetor(v_d));
}