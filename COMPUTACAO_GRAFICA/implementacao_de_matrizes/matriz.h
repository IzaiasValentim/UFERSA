#ifndef B_MATRIZ_H
#define B_MATRIZ_H

typedef struct
{
    int linhas;     // Número de linhas da matriz.
    int colunas;    // Número de colunas da matriz.
    float **matriz; // Ponteiro para a matriz.
} Matriz;

// Protótipos das funções para operações básicas com matrizes.
Matriz *cria_matriz(int linhas, int colunas); // Cria uma matriz com o número de linhas e colunas especificado.
void imprime_matriz(Matriz m); // Imprime a matriz na tela.
void libera_matriz(Matriz *m); // Libera a memória alocada para a matriz.
// Protótipos das funções para resolução das questões.
Matriz *multiplica_matriz_por_escalar(Matriz *m, float escalar); // Multiplica a matriz por um escalar.
Matriz *soma_matrizes(Matriz *m1, Matriz *m2);                // Soma duas matrizes.
Matriz *subtrai_matrizes(Matriz *m1, Matriz *m2);             // Soma duas matrizes.
#endif