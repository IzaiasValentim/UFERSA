#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "v_vector.h"

Vetor criar_vetor(float *elementos, int q_elementos)
{

    if (q_elementos == 0)
    {
        printf("Erro: vetor vazio.\n");
    }

    // Aloca memoria para o vetor e seus dados.
    Vetor *vetor = (Vetor *)malloc(sizeof(Vetor));

    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria para o vetor.\n");
    }

    vetor->dados = (float *)malloc(q_elementos * sizeof(float));

    if (vetor->dados == NULL)
    {
        printf("Erro ao alocar memoria para os dados do vetor.\n");
        free(vetor);
        exit(1);
    }
    int i;
    // Alimentando o vetor com os elementos passados como argumento.
    for (i = 0; i < q_elementos; i++)
    {
        vetor->dados[i] = elementos[i];
    }
    vetor->capacidade = q_elementos;
    return *vetor;
}

void imprimir_vetor(Vetor *vetor)
{
    // Verifica se o vetor é nulo.
    if (vetor == NULL)
    {
        printf("Erro: vetor nulo.\n");
        return;
    }
    int i;
    printf("[ ");
    // Imprime os elementos do vetor.
    for (i = 0; i < vetor->capacidade; i++)
    {
        printf("%.2f ", vetor->dados[i]);
    }
    printf(" ]\n");
}

Vetor *encontrar_vetor(int *p1, int *p2, int dimensao)
{
    // vetor resultante = p2 - p1;

    if ((sizeof(p1) == 0 || sizeof(p2) == 0))
    {
        // Os pontos devem ter a mesma quantidade de elementos e não podem ser nulos.
        printf("Pontos inválidos.\n");
        exit(1);
    }

    int capacidade = dimensao;
    Vetor *vetor = (Vetor *)malloc(sizeof(Vetor));
    vetor->dados = (float *)malloc(capacidade * sizeof(float));

    if (vetor == NULL || vetor->dados == NULL)
    {
        printf("Erro ao alocar memoria para o vetor.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < capacidade; i++)
    {
        vetor->dados[i] = p2[i] - p1[i];
    }
    vetor->capacidade = capacidade;
    return vetor;
}

float norma_vetor(Vetor vetor)
{
    // |vetor| = sqrt(vetor[0]^2 + vetor[1]^2 + ... + vetor[n]^2);

    float soma = 0.0;
    int i;

    for (i = 0; i < vetor.capacidade; i++)
    {
        soma += vetor.dados[i] * vetor.dados[i];
    }
    return sqrt(soma);
}

Vetor deslocar_vetor_soma(Vetor vetor, int *p)
{
    // vetor = vetor + p;

    Vetor resultado;
    resultado.capacidade = vetor.capacidade;
    resultado.dados = (float *)malloc(resultado.capacidade * sizeof(float));

    if (resultado.dados == NULL)
    {
        printf("Erro ao alocar memoria para o vetor.\n");
        return resultado;
    }
    int i;
    for (i = 0; i < vetor.capacidade; i++)
    {
        resultado.dados[i] = vetor.dados[i] + p[i];
    }
    return resultado;
}

Vetor deslocar_vetor_subtracao(Vetor vetor, int *p)
{
    // vetor = vetor + p;

    Vetor resultado;
    resultado.capacidade = vetor.capacidade;
    resultado.dados = (float *)malloc(resultado.capacidade * sizeof(float));

    if (resultado.dados == NULL)
    {
        printf("Erro ao alocar memoria para o vetor.\n");
        return resultado;
    }
    int i;
    for (i = 0; i < vetor.capacidade; i++)
    {
        resultado.dados[i] = vetor.dados[i] - p[i];
    }
    return resultado;
}

Vetor somar_vetores(Vetor *vetores, int q_vetores)
{

    Vetor v1 = vetores[0];
    Vetor v2 = vetores[1];

    if (v1.capacidade != v2.capacidade)
    {
        printf("Os vetores devem ter a mesma capacidade.\n");
        exit(1);
    }
    Vetor resultado;
    resultado.capacidade = v1.capacidade;
    resultado.dados = (float *)malloc(resultado.capacidade * sizeof(float));

    if (resultado.dados == NULL)
    {
        printf("Erro ao alocar memoria para o vetor.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < resultado.capacidade; i++)
    {
        resultado.dados[i] = v1.dados[i] + v2.dados[i];
    }
    return resultado;
}

Vetor subtrair_vetores(Vetor *vetores, int q_vetores)
{
    Vetor v1 = vetores[0];
    Vetor v2 = vetores[1];

    if (v1.capacidade != v2.capacidade)
    {
        printf("Os vetores devem ter a mesma capacidade.\n");
        exit(1);
    }
    Vetor resultado;
    resultado.capacidade = v1.capacidade;
    resultado.dados = (float *)malloc(resultado.capacidade * sizeof(float));

    if (resultado.dados == NULL)
    {
        printf("Erro ao alocar memoria para o vetor.\n");
        exit(1);
    }
    int i;

    for (i = 0; i < resultado.capacidade; i++)
    {
        resultado.dados[i] = v1.dados[i] - v2.dados[i];
    }
    return resultado;
}

Vetor multiplicar_vetor_por_escalar(Vetor vetor, int escalar)
{
    // vetor * escalar = < vx * escalar, vy * escalar, vz * escalar>

    Vetor resultado;
    resultado.capacidade = vetor.capacidade;
    resultado.dados = (float *)malloc(resultado.capacidade * sizeof(float));

    if (resultado.dados == NULL)
    {
        printf("Erro ao alocar memoria para o vetor.\n");
        return resultado;
    }
    int i;
    for (i = 0; i < vetor.capacidade; i++)
    {
        resultado.dados[i] = vetor.dados[i] * escalar;
    }
    return resultado;
}

Vetor normalizar_vetor(Vetor vetor)
{
    // vetor = vetor / |vetor|

    Vetor resultado;
    resultado.capacidade = vetor.capacidade;
    resultado.dados = (float *)malloc(resultado.capacidade * sizeof(float));

    if (resultado.dados == NULL)
    {
        printf("Erro ao alocar memoria para o vetor.\n");
        return resultado;
    }
    float norma = norma_vetor(vetor);
    int i;
    for (i = 0; i < vetor.capacidade; i++)
    {
        resultado.dados[i] = vetor.dados[i] / norma;
    }
    return resultado;
}

float produdo_escalar(Vetor *vetores, int q_vetores)
{
    // res = v1 . v2  = vx1*vx2 + vy1*vy2 + vz1*vz2;

    float resultado = 0.0;
    Vetor v1 = vetores[0];
    Vetor v2 = vetores[1];

    if (v1.capacidade != v2.capacidade)
    {
        printf("Os vetores devem ter a mesma capacidade.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < v1.capacidade; i++)
    {
        resultado += v1.dados[i] * v2.dados[i];
    }
    return resultado;
}

Vetor produto_vetorial(Vetor *vetores, int q_vetores)
{
    Vetor v1 = vetores[0];
    Vetor v2 = vetores[1];

    Vetor resultado;

    if (v1.capacidade != 3 || v2.capacidade != 3)
    {
        printf("Os vetores devem ter 3 dimensões.\n");
        exit(1);
    }

    resultado.capacidade = 3;
    resultado.dados = (float *)malloc(resultado.capacidade * sizeof(float));
    resultado.dados[0] = v1.dados[1] * v2.dados[2] - v1.dados[2] * v2.dados[1];
    resultado.dados[1] = v1.dados[2] * v2.dados[0] - v1.dados[0] * v2.dados[2];
    resultado.dados[2] = v1.dados[0] * v2.dados[1] - v1.dados[1] * v2.dados[0];
    return resultado;
}
