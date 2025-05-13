#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "v_vector.h"

/**
 * Tarefa: Questões dos slides e implementação de vetores
 * Aluno: Luis Izaías Valentim de Aquino
 *
 *  Exercícios: Realize as operações nos vetores abaixo:
    Soma entre a =< 2,−5 > e v =< 2,4 >;
    Subtraçãoo entre a =< 3,2 > e v =< 1,7 >;
    Soma entre a =< 3,5,−6 > e v =< −3,2,−3 >;
    Subtração entre a =< 5,5,1 > e v =< 3,1,7 >;

    Execução:
    > gcc -c b_vector.c -o b_vector.o
    > gcc exercicio_4.c  b_vector.o -o ex4
    > ./ex4.exe
 */

int main()
{
    // Criando os vetores relativos a cada operação.
    int p_v_a1[] = {2, -5};
    int p_v_v1[] = {2, 4};

    int p_v_a2[] = {3, 2};
    int p_v_v2[] = {1, 7};

    int p_v_a3[] = {3, 5, -6};
    int p_v_v3[] = {-3, 2, -3};

    int p_v_a4[] = {5, 5, 1};
    int p_v_v4[] = {3, 1, 7};

    Vetor v_a = criar_vetor(p_v_a1, 2);
    Vetor v_b = criar_vetor(p_v_v1, 2);
    Vetor v_c = criar_vetor(p_v_a2, 2);
    Vetor v_d = criar_vetor(p_v_v2, 2);
    Vetor v_e = criar_vetor(p_v_a3, 3);
    Vetor v_f = criar_vetor(p_v_v3, 3);
    Vetor v_g = criar_vetor(p_v_a4, 3);
    Vetor v_h = criar_vetor(p_v_v4, 3);

    printf("Exercicio 4.1 - Soma entre os vetores: \n\n");

    printf("Soma entre a =< 2,-5 > e v =< 2,4 >\n");
    Vetor vetores_um[] = {v_a, v_b};
    Vetor resultado = somar_vetores(vetores_um, 2);
    imprimir_vetor(&resultado);

    printf(" Subtracao entre a =< 3,2 > e v =< 1,7 >;\n");
    Vetor vetores_dois[] = {v_c, v_d};
    resultado = subtrair_vetores(vetores_dois, 2);
    imprimir_vetor(&resultado);

    printf(" Soma entre a =< 3,5,-6 > e v =< -3,2,-3 >;\n");
    Vetor vetores_tres[] = {v_e, v_f};
    resultado = somar_vetores(vetores_tres, 3);
    imprimir_vetor(&resultado);

    printf(" Subtracao entre a =< 5,5,1 > e v =< 3,1,7 >;\n");
    Vetor vetores_quatro[] = {v_g, v_h};
    resultado = subtrair_vetores(vetores_quatro, 3);
    imprimir_vetor(&resultado);

    return 0;
}