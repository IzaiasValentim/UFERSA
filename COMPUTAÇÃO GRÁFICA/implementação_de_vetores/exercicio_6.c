#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "v_vector.h"

/**
 * Tarefa: Questões dos slides e implementação de vetores
 * Aluno: Luis Izaías Valentim de Aquino
 *
 *   Exercícios: Realize as operações nos vetores abaixo:
    Calcule o produto escalar entre os vetores a =< 2,−4 > e b =< 5,3 >;
    Calcule o produto interno entre os vetores a =< 1,7,5 > e b =< 2,4,5 >;
    Transforme o vetor v =< 12,3 > em vetor unitário;
    Transforme o vetor v =< −3,4,−5 > em vetor unitário.

    Execução:
    > gcc -c b_vector.c -o b_vector.o
    > gcc exercicio_6.c  b_vector.o -o ex6
    > ./ex6.exe
 */

int main()
{
    // Criando os vetores relativos a cada operação.
    float p_v_1a[] = {2.0, -4.0};
    float p_v_1b[] = {5.0, 3.0};
    float p_v_2a[] = {1.0, 7.0, 5.0};
    float p_v_2b[] = {2.0, 4.0, 5.0};
    float p_v_3[] = {12.0, 3.0};
    float p_v_4[] = {-3.0, 4.0, -5.0};

    Vetor v_a = criar_vetor(p_v_1a, 2);
    Vetor v_b = criar_vetor(p_v_1b, 2);
    Vetor v_c = criar_vetor(p_v_2a, 3);
    Vetor v_d = criar_vetor(p_v_2b, 3);
    Vetor v_e = criar_vetor(p_v_3, 2);
    Vetor v_f = criar_vetor(p_v_4, 3);

    printf("Exercicio 5.1 - Calcule o produto escalar entre os vetores a =< 2,-4 > e b =< 5,3 >;\n\n");
    Vetor v1s[] = {v_a, v_b};
    float produto_escalar = produdo_escalar(v1s, 2);
    printf("Produto escalar: %.2f\n", produto_escalar);

    printf("\nExercicio 5.2 - Calcule o produto interno entre os vetores a =< 1,7,5 > e b =< 2,4,5 >;\n\n");
    Vetor v2s[] = {v_c, v_d};
    float produto_interno = produdo_escalar(v2s, 3);
    printf("Produto interno: %.2f\n", produto_interno);

    printf("\nExercicio 5.3 - Transforme o vetor v =< 12,3 > em vetor unitário;\n\n");
    Vetor v_e_1 = normalizar_vetor(v_e);
    imprimir_vetor(&v_e_1);
    printf("\nNorma do vetor resultante: %.2f\n", norma_vetor(v_e_1));

    printf("\nExercicio 5.4 - Transforme o vetor v =< -3,4,-5 > em vetor unitário;\n\n");
    Vetor v_f_1 = normalizar_vetor(v_f);
    imprimir_vetor(&v_f_1);
    printf("\nNorma do vetor resultante: %.2f\n", norma_vetor(v_f_1));

    return 0;
}