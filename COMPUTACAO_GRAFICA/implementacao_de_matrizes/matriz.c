#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"

Matriz *cria_matriz(int linhas, int colunas)
{
    Matriz *m = (Matriz *)malloc(sizeof(Matriz));
    if (m == NULL)
    {
        printf("Erro ao alocar memoria para a matriz.\n");
        return NULL;
    }
    m->linhas = linhas;
    m->colunas = colunas;
    m->matriz = (float **)malloc(linhas * sizeof(float *));
    if (m->matriz == NULL)
    {
        printf("Erro ao alocar memoria para as linhas da matriz.\n");
        free(m);
        return NULL;
    }
    int l;
    for (l = 0; l < linhas; l++)
    {
        m->matriz[l] = (float *)malloc(colunas * sizeof(float));
        if (m->matriz[l] == NULL)
        {
            printf("Erro ao alocar memoria para as colunas da matriz.\n");
            libera_matriz(m);
            return NULL;
        }
    }
    return m;
}

void imprime_matriz(Matriz m)
{
    int l, c;
    for (l = 0; l < m.linhas; l++)
    {
        printf("[ ");
        for (c = 0; c < m.colunas; c++)
        {
            printf("%.2f ", m.matriz[l][c]);
        }
        printf("]\n");
    }
}

void libera_matriz(Matriz *m)
{
    if (m != NULL)
    {
        int l;
        for (l = 0; l < m->linhas; l++)
        {
            free(m->matriz[l]);
        }
        free(m->matriz);
        free(m);
    }
}

Matriz *multiplica_matriz_por_escalar(Matriz *m, float escalar)
{
    Matriz *resultado = cria_matriz(m->linhas, m->colunas);
    int l, c;
    for (l = 0; l < m->linhas; l++)
    {
        for (c = 0; c < m->colunas; c++)
        {
            resultado->matriz[l][c] = m->matriz[l][c] * escalar;
        }
    }
    return resultado;
}

Matriz *soma_matrizes(Matriz *m1, Matriz *m2)
{
    if (m1 == NULL || m2 == NULL || m1->linhas != m2->linhas || m1->colunas != m2->colunas)
    {
        printf("Matrizes inválidas para soma.\n");
        return NULL;
    }

    Matriz *resultado = cria_matriz(m1->linhas, m1->colunas);
    if (resultado == NULL)
    {
        return NULL;
    }

    int l, c;
    for (l = 0; l < resultado->linhas; l++)
    {
        for (c = 0; c < resultado->colunas; c++)
        {
            resultado->matriz[l][c] = m1->matriz[l][c] + m2->matriz[l][c];
        }
    }
    return resultado;
}

Matriz *subtrai_matrizes(Matriz *m1, Matriz *m2)
{
    if (m1 == NULL || m2 == NULL || m1->linhas != m2->linhas || m1->colunas != m2->colunas)
    {
        printf("Matrizes inválidas para subtração.\n");
        return NULL;
    }

    Matriz *resultado = cria_matriz(m1->linhas, m1->colunas);
    if (resultado == NULL)
    {
        return NULL;
    }

    int l, c;
    for (l = 0; l < resultado->linhas; l++)
    {
        for (c = 0; c < resultado->colunas; c++)
        {
            resultado->matriz[l][c] = m1->matriz[l][c] - (m2->matriz[l][c]);
        }
    }
    return resultado;
}