#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "v_vector.h"

/**
 * Tarefa: Questões dos slides e implementação de vetores
 * Aluno: Luis Izaías Valentim de Aquino
 *
 *  Exercícios: Realize as operações nos vetores abaixo:
     Calcule o produto vetorial entre os vetores a =< 2,−4 > e b =< 5,3 >;
     Calcule o produto vetorial entre os vetores a =< 1,7,5 > e b =< 2,4,5 >;

    Execução:
    > gcc -c b_vector.c -o b_vector.o
    > gcc exercicio_7.c  b_vector.o -o ex7
    > ./ex7.exe
 */

int main()
{
    // Criando os vetores relativos a cada operação.
    float p_v_1a[] = {2.0, -4.0, 0.0};
    float p_v_1b[] = {5.0, 3.0, 0.0};

    float p_v_2a[] = {1.0, 7.0, 5.0};
    float p_v_2b[] = {2.0, 4.0, 5.0};

    // Criando os vetores a e b para cada questão.
    Vetor va1 = criar_vetor(p_v_1a, 3);
    Vetor vb1 = criar_vetor(p_v_1b, 3);
    Vetor va2 = criar_vetor(p_v_2a, 3);
    Vetor vb2 = criar_vetor(p_v_2b, 3);

    printf("Produto vetorial entre os vetores a =< 2,-4 > e b =< 5,3 >:\n");
    Vetor resultado1 = produto_vetorial((Vetor[]){va1, vb1}, 2);
    imprimir_vetor(&resultado1);

    printf("Produto vetorial entre os vetores a =< 1,7,5 > e b =< 2,4,5 >:\n");
    Vetor resultado2 = produto_vetorial((Vetor[]){va2, vb2}, 2);
    imprimir_vetor(&resultado2);

    return 0;
}