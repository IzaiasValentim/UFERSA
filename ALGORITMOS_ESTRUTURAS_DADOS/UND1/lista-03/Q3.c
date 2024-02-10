#include <stdio.h>
#include <stdlib.h>

// Protótipo da função.
void uniao(int *v1, int n1, int *v2, int n2);

int main(void)
{

  // Declaração dos ponteiros e outras variáveis.
  int *v1, *v2, n1, n2, i;

  // Entrada do tamanho dos vetores.
  printf("Informe o tamanho do primeiro vetor: ");
  scanf("%d", &n1);

  printf("\nInforme o tamanho do segundo vetor: ");
  scanf("%d", &n2);

  // Alocação dinâmica dos vetores(v1 e v2).
  v1 = (int *)malloc(n1 * sizeof(int));
  v2 = (int *)malloc(n2 * sizeof(int));

  if (v1 == NULL || v2 == NULL)
  {
    printf("Erro ao alocar memória");
    return 1;
  }

  // Alimentação dos vetores.
  printf("\nInforme os elemtos do primeiro vetor: ");
  for (i = 0; i < n1; i++)
  {
    scanf("%d", (v1 + i));
  }

  printf("\nInforme os elemtos do segundo vetor: ");
  for (i = 0; i < n2; i++)
  {
    scanf("%d", (v2 + i));
  }

  // Chamada da função de união. 
  uniao(v1, n1, v2, n2);

  // Liberando a memória dos ponteiros deste escopo.
  free(v1);
  free(v2);

  return 0;
}

void uniao(int *v1, int n1, int *v2, int n2)
{
  // Tamanho necessário para alocar v3.
  int total = n1 + n2;
  
  // i = contador do for e b funciona como um contador auxiliar em v2.
  int i;
  int b = 0;
  
  // Alocação do v3.
  int *v3 = (int *)malloc(total * sizeof(int));

  // Laço que une os elementos de v1 e v2 em v3.
  printf("\nA uniao entre os dois vetores: ");
  for (i = 0; i < total; i++)
  {
    // Se i<n1 v3 receberá a posição v1[i]
    if (i < n1)
    {
      *(v3 + i) = *(v1 + i);
    }
    else
    {
      //v3 receberá a posição v1[b]
      *(v3 + i) = *(v2 + b);
      b++;
    }
    // Saída = v3[i].
    printf(" %d", *(v3 + i));
  }

  // Liberando a memória de v3.
  free(v3);
}