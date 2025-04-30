#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "v_vector.h"

/**
 * Tarefa: Questões dos slides e implementação de vetores
 * Aluno: Luis Izaías Valentim de Aquino
 *
 * Exercícios: Realize o deslocamento dos pontos usando os vetores.
    a = (2,−5) e v =< 2,4 >;
    a = (3,5,−6) e v =< −3,2,−3 >;

    Execução:
    > gcc -c b_vector.c -o b_vector.o
    > gcc exercicio_3.c  b_vector.o -o ex3
    > ./ex3.exe
 */

int main()
{
    // Criando os vetores a, b, c e d.
    int p_v_a[] = {2, 4};
    int p_v_b[] = {-3, 2, -3};

    int deslocamento_a[] = {2, -5};
    int deslocamento_b[] = {3, 5, -6};

    // Criando os vetores a e b.
    Vetor v_a = criar_vetor(p_v_a, 2);
    Vetor v_b = criar_vetor(p_v_b, 3);

    // Executando a função deslocar_vetor para calcular o deslocamento dos vetores.
    printf("Exercicio 3.1 - Deslocamento dos vetores - Somando: \n\n");
    Vetor resultado_a = deslocar_vetor_soma(v_a, deslocamento_a);
    Vetor resultado_b = deslocar_vetor_soma(v_b, deslocamento_b);

    printf("Resultado com o vetor a: ");
    imprimir_vetor(&resultado_a);
    printf("Resultado com o vetor b: ");
    imprimir_vetor(&resultado_b);
    // Executando a função deslocar_vetor para calcular o deslocamento dos vetores.
    printf("\nExercicio 3.2 - Deslocamento dos vetores - Subtraindo: \n\n");
    resultado_a = deslocar_vetor_subtracao(v_a, deslocamento_a);
    resultado_b = deslocar_vetor_subtracao(v_b, deslocamento_b);

    printf("Resultado com o vetor a: ");
    imprimir_vetor(&resultado_a);
    printf("Resultado com o vetor b: ");
    imprimir_vetor(&resultado_b);

    return 0;
}