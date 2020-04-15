#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 500000

void quick_sort(int *x, int esq, int dir);

int main()
{
    FILE *arquivo;
    int j, tamanho;
    int vet[MAX];

    printf("Informe o numero de dados a serem ordenados: ");
    scanf("%d", &tamanho);

    arquivo = fopen("alea.dat", "r");

    for (j = 0; j < tamanho; j++)
    {
        fscanf(arquivo, "%d", &vet[j]);
        printf("%d - %d\n", j+1, vet[j]);
    }

    clock_t start, end;
    float tempo;

    getchar();

    start = clock();
    quick_sort(vet, 0, tamanho - 1);
    end = clock();
    tempo = (end - start) / (float)CLOCKS_PER_SEC;

    printf("\nTempo = %12.8f\n", tempo);
    getchar();

    printf("\nValores ordenados:\n");

    for (j = 0; j < tamanho; j++)
        printf("%d - %d\n", j+1, vet[j]);

    getchar();

    return 0;
}

void quick_sort(int *x, int esq, int dir)
{
    int esqaux, diraux, pivo, z;

    esqaux = esq;
    diraux = dir;
    pivo = x[(esq + dir) / 2];

    while (esqaux <= diraux)
    {
        while (x[esqaux] < pivo && esqaux < dir)
        {
            esqaux++;
        }
        while (x[diraux] > pivo && diraux > esq)
        {
            diraux--;
        }
        if (esqaux <= diraux)
        {
            z = x[esqaux];
            x[esqaux] = x[diraux];
            x[diraux] = z;
            esqaux++;
            diraux--;
        }
    }

    if (diraux > esq)
    {
        quick_sort(x, esq, diraux);
    }
    if (esqaux < dir)
    {
        quick_sort(x, esqaux, dir);
    }
}