#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "v_vector.h"

/**
 * Tarefa: Questões dos slides e implementação de vetores
 * Aluno: Luis Izaías Valentim de Aquino
 *
 *  Exercícios: Realize as operações nos vetores abaixo:
    Multiplique o vetor v =< 2,4 > pelo escalar 3;
    Multiplique o vetor v =< 1,7,5 > pelo escalar-5;
    Normalize o vetor v =< 12,3 >;
    Normalize o vetor v =< −3,4,−5 >

    Execução:
    > gcc -c b_vector.c -o b_vector.o
    > gcc exercicio_5.c  b_vector.o -o ex5
    > ./ex5.exe
 */

int main()
{
    // Criando os vetores relativos a cada operação.
    float p_v_1[] = {2.0, 4.0};
    float p_v_2[] = {1, 7, 5};
    float p_v_3[] = {12, 3};
    float p_v_4[] = {-3, 4, -5};

    Vetor v_a = criar_vetor(p_v_1, 2);
    Vetor v_b = criar_vetor(p_v_2, 3);
    Vetor v_c = criar_vetor(p_v_3, 2);
    Vetor v_d = criar_vetor(p_v_4, 3);

    printf("Exercicio 5.1 - Multiplique o vetor v =< 2,4 > pelo escalar 3;\n\n");
    Vetor v_a_1 = multiplicar_vetor_por_escalar(v_a, 3);
    imprimir_vetor(&v_a_1);

    printf("\nExercicio 5.2 - Multiplique o vetor v =< 1,7,5 > pelo escalar-5;\n\n");
    Vetor v_b_1 = multiplicar_vetor_por_escalar(v_b, -5);
    imprimir_vetor(&v_b_1);

    printf("\nExercicio 5.3 - Normalize o vetor v =< 12,3 >;\n\n");
    Vetor v_c_1 = normalizar_vetor(v_c);
    imprimir_vetor(&v_c_1);
    printf("\nNorma do vetor resultante: %.2f\n", norma_vetor(v_c_1));

    printf("\nExercicio 5.4 - Normalize o vetor v =< -3,4,-5 >;\n\n");
    Vetor v_d_1 = normalizar_vetor(v_d);
    imprimir_vetor(&v_d_1);
    printf("\nNorma do vetor resultante: %.2f\n", norma_vetor(v_d_1));

    return 0;
}