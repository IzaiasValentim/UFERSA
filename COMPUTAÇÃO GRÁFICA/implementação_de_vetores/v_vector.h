#ifndef B_VECTOR_H
#define B_VECTOR_H

typedef struct
{
    float *dados;
    int capacidade;
} Vetor;

Vetor criar_vetor(float *elementos, int q_elementos);
void imprimir_vetor(Vetor *vetor);

Vetor *encontrar_vetor(int *p1, int *p2, int dimensao);
float norma_vetor(Vetor vetor);
Vetor deslocar_vetor_soma(Vetor vetor, int *p);
Vetor deslocar_vetor_subtracao(Vetor vetor, int *p);
Vetor somar_vetores(Vetor *vetores, int q_vetores);
Vetor subtrair_vetores(Vetor *vetores, int q_vetores);
Vetor multiplicar_vetor_por_escalar(Vetor vetor, int escalar);
Vetor normalizar_vetor(Vetor vetor);
float produdo_escalar(Vetor * vetores, int q_vetores); // Produto interno.
Vetor produto_vetorial(Vetor *vetores, int q_vetores); // Produto vetorial.
void liberar_vetor(Vetor *vetor);

#endif