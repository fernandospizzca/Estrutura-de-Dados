#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct
{
    int n;
    float vet[MAX];

} pilha;

typedef pilha Pilha;

Pilha *cria();
void push(Pilha *p, float v);
void pop(Pilha *p);
int vazia(Pilha *p);
void libera(Pilha *p);
void mostrarPilha(Pilha *p);

int main()
{
    Pilha *p;
    float valor;
    int opcao = 0;

    while (opcao != 6)
    {
        printf("\nOpcoes:\n1. Criar Nova Pilha\n2. Add item a pilha\n3. Remover item da pilha\n4. Liberar a pilha\n5. Mostrar pilha\n6. Fim\n\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            p = cria();
            break;
        }

        case 2:
        {
            printf("Informe um valor: ");
            scanf("%f", &valor);
            push(p, valor);
            break;
        }

        case 3:
        {
            pop(p);
            break;
        }

        case 4:
        {
            libera(p);
            break;
        }
        case 5:
        {
            mostrarPilha(p);
            break;
        }
        }
    }
    return 0;
}

Pilha *cria(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

void push(Pilha *p, float v)
{
    if (p->n == MAX)
    {
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

void pop(Pilha *p)
{
    float v;
    if (vazia(p))
    {
        printf("Pilha vazia.\n");
        return;
       
    }
    v = p->vet[p->n - 1];
    p->n--;
    printf("Valor %.2f retirado\n",v);
}

int vazia(Pilha *p)
{
    return (p->n == 0);
}

void libera(Pilha *p)
{
    free(p);
}

void mostrarPilha(Pilha *p)
{
    int tam = 0;

    while (tam < p->n)
    {
        printf("item - %i - valor - %.2f\n", tam+1, p->vet[tam]);
        tam++;
    }
}