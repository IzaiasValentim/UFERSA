#include <stdio.h>

// Variáveis que irão contabilizar a ocorrência de cada operação.
int chamadasRec = 0;
int retornoCRec = 0;
int atrOuSoma = 0;
int divOuMult = 0;

int funcRecursiva(int n)
{
    // Incremento para cada chamada recursiva.
    chamadasRec++;
    if (n == 0)
    {
        // Incremento para cada retorno recursivo.
        retornoCRec++;
        return 1;
    }

    int k = funcRecursiva (n -1);

    // Incremento do retorno da chamada recursiva.
    retornoCRec++;
    // Incremento da soma.
    atrOuSoma++;
    // Increment da vid/mult.
    divOuMult++;
    return k + 1/ k ;

}

int main()
{
    // Chamada da função recursiva.
    funcRecursiva(5);

    float t_chamadasRec = 2.0 * (float)chamadasRec;
    float t_retornoCRec = 1.0 * (float)retornoCRec;
    float t_atrOuSoma = 0.5 * (float)atrOuSoma;
    float t_divOuMult = 1.5 * (float)divOuMult;

    float t_total = t_chamadasRec + t_retornoCRec + t_atrOuSoma + t_divOuMult;

    printf("O tempo total de execucao da funRecursiva(5) e: %.2f ns", t_total);
    return 0;
}