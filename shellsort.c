#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

#define MAX 500000

void shell_sort(int *a, int tam);

int main()
{
    FILE *arquivo;
    int i, tamanho;
    int vet[MAX];

    printf("Digite o numero de numero a ser lidos e ordenados: ");
    scanf("%d", &tamanho);

    arquivo = fopen("alea.dat", "r");

    for (i = 1; i <= tamanho; i++)
    {
        fscanf(arquivo, "%d", &vet[i]);
        printf("%d - %d\n", i, vet[i]);
    }

    clock_t start, end;
    float tempo;

    getchar();

    start = clock();
    shell_sort(vet, tamanho);
    end = clock();
    tempo = (end - start) / (float)CLOCKS_PER_SEC;

    printf("\ntempo = %12.8f\n", tempo);
    getchar();

    printf("\n\nValores ordenados\n");
    for (i = 1; i <= tamanho; i++)
    {
        printf("%d - %d\n",i, vet[i]);
    }
    getchar();

    return 0;
}

void shell_sort(int *a, int tam)
{
    int i, j;
    int h = 1;
    int x;
    do
    {
        h = h * 3 + 1;
    } while (h < tam);

    do
    {
        h = h / 3;
        for (i = h + 1; i <= tam; i++)
        {
            x = a[i];
            j = i;
            while (a[j - h] > x)
            {
                a[j] = a[j - h];
                j -= h;
                if (j <= h)
                    break;
            }
            a[j] = x;
        }
    } while (h != 1);
}
