#include <stdio.h>
#include <stdlib.h>

typedef struct reglista
{
    int valor;
    struct reglista *prox;
} reglista;

reglista *insert(int x);
reglista *delete (reglista *inicio, int x);
void print(reglista *aux);

int main()
{
    int opcao, numero;

    reglista *raiz, *novop, *aux;
    raiz = NULL;

    while (opcao != 4)
    {
        printf("Informe a opcao desejada:\n1. Inserir um noh de informacao\n2. Retirar um noh de informacao\n3. Imprimir todos os nohs de informacao armazenados\n4. Fim do programa\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            while (numero >= 0)
            {

                printf("\nInforme o numero >= 0 ou -1 para encerrar: ");
                scanf("%d", &numero);
                if (numero >= 0)
                {
                    if (raiz == NULL)
                    {
                        raiz = insert(numero);
                        aux = raiz;
                    }
                    else
                    {
                        aux = insert(numero);
                        novop->prox = aux;
                    }
                    novop = aux;
                }
            }
            printf("\n");
            break;
        }
        case 2:
        {
            printf("\nInforme o valor a ser retirado: ");
            scanf("%d", &numero);
            raiz = delete (raiz, numero);
            break;
        }
        case 3:
        {
            print(raiz);
            break;
        }
        case 4:
        {
            printf("\nFIM DE PROGRAMA\n\n");
            break;
        }
        default:
        {
            printf("\n\nOpcao invalida, favor nova opcao:");
            break;
        }
        }
    }
    return 0;
}

reglista *insert(int x)
{
    reglista *novo = (reglista *)malloc(sizeof(reglista));
    novo->valor = x;
    novo->prox = NULL;
    return novo;
}

reglista *delete (reglista *inicio, int x)
{
    reglista *ant = NULL;
    reglista *p = inicio;

    while (p != NULL && p->valor != x)
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL)
    {
       printf("\nValor nao encontrado\n\n");
        return inicio;
    }

    /* retira elemento do inicio */
    if (ant == NULL)
        inicio = p->prox;

    /* retira elemento do meio da lista */
    else
        ant->prox = p->prox;

    printf("\nValor deletado com sucesso\n\n");
    free(p);
    return inicio;
}

void print(reglista *aux)
{
    reglista *j = aux;
    printf("\n\nConteudo da lista:\n");

    while (j != NULL)
    {
        printf("%d\n", j->valor);
        j = j->prox;
    }
    printf("\n");
}