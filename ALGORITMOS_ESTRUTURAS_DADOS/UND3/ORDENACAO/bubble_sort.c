#include <stdio.h>

void bubble_sort(int v[], int n);

int main(void){
int n;
    printf("Informe a quantidade de elementos do vetor: ");
    scanf("%d", &n);
    int v[n];
    int i;

    printf("\nInforme os elementos do vetor: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    printf("\nVetor não ordenado:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", v[i]);
    }

    bubble_sort(v, n);

    printf("\nVetor ordenado:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", v[i]);
    }
    
    return 0;
}

void bubble_sort(int v[], int n){
    int i,j;

    for(i=0; i<n-1;i++){
        for(j=0; j<n -i -1; j++){
            if(v[j] > v[j+1]){
                int temp =v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}