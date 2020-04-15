#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int codigo;
    float peso;
    char sexo;
    struct lista *prox;
} lista;

typedef lista Lista;

void maispesado(Lista *inicio);
void menospesado(Lista *inicio);
void pesqpessoa(Lista *inicio, int cod);
Lista *inserir(Lista *inicio, int cod, float pes, char sex, int *contador);
Lista *delete (Lista *inicio, int cod, int *contador);
void totalp(int x);
void mostratudo(Lista *aux);

int main()
{
    Lista *raiz;
    int opcao, ncod, aux2, contador = 0;
    float npeso;
    char nsexo;

    raiz = NULL;

    while (opcao != 8)
    {
        printf("\nOpcoes:\n1. Mais pesado\n2. Menos pesado\n3. Consultar Pessoa\n4. Inserir Pessoa\n5. Remover Pessoa\n6. Numero de Pessoas\n7. Mostrar Pessoas\n8. Fim\n\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            maispesado(raiz);
            break;
        }

        case 2:
        {
            menospesado(raiz);
            break;
        }

        case 3:
        {
            printf("\n\ninforma o codigo para pesquisa: ");
            scanf("%d", &ncod);
            pesqpessoa(raiz, ncod);
            break;
        }

        case 4:
        {
            aux2 = 1;

            while (aux2 == 1)
            {
                printf("Informe o codigo da Pessoa: ");
                scanf("%d", &ncod);
                printf("Informe o Peso da Pessoa: ");
                scanf("%f", &npeso);
                printf("Informe o sexo da Pessoa M/F: ");
                getchar();
                scanf("%c", &nsexo);

                if (raiz == NULL)
                {
                    raiz = inserir(raiz, ncod, npeso, nsexo, &contador);
                }
                else
                {
                    raiz = inserir(raiz, ncod, npeso, nsexo, &contador);
                }

                printf("\nSe deseja inserir nova pessoa digite 1 ou 0 para encerrar: ");
                getchar();
                scanf("%d", &aux2);
            }

            printf("\n");
            break;
        }

        case 5:
        {
            printf("\n\nInforma o codigo para excluir: ");
            scanf("%d", &ncod);
            raiz = delete (raiz, ncod, &contador);
            break;
        }

        case 6:
        {
            totalp(contador);
            break;
        }

        case 7:
        {
            mostratudo(raiz);
            break;
        }

        case 8:
        {
            printf("FIM\n");
            break;
        }

        default:
            printf("\nErro, por favor digite uma opcao valida\n");
        }
    }
    return 0;
}

void maispesado(Lista *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    else
        printf("\nPessoa com maior peso |Codigo: %-5d |Peso: %-6.2f |Sexo: %c |\n", inicio->codigo, inicio->peso, inicio->sexo);
}
void menospesado(Lista *inicio)
{
    Lista *y = inicio;

    if (y == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    else
    {
       while (y->prox != NULL)
           y = y->prox;

        printf("\nPessoa com menor peso |Codigo: %-5d |Peso: %-6.2f |Sexo: %c |\n", y->codigo, y->peso, y->sexo);
    }
}
void pesqpessoa(Lista *inicio, int cod)
{
    Lista *p = inicio;

    if (p == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    else
    {
        while (p != NULL && p->codigo != cod)
            p = p->prox;

        if (p == NULL)
            printf("\nPessoa nao encontrado\n\n");

        else
            printf("\nPessoa com menor peso |Codigo: %-5d |Peso: %-6.2f |Sexo: %c |\n", p->codigo, p->peso, p->sexo);
    }
}
Lista *inserir(Lista *inicio, int cod, float pes, char sex, int *contador)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->codigo = cod;
    novo->peso = pes;
    novo->sexo = sex;

    Lista *ant = NULL;
    Lista *p = inicio;

    while (p != NULL && p->peso > pes)
    {
        ant = p;
        p = p->prox;
    }
    if (ant == NULL)
    {
        novo->prox = inicio;
        inicio = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;   
    }

    *contador += 1;
    return inicio;
}
Lista *delete (Lista *inicio, int cod, int *contador)
{
    Lista *ant = NULL;
    Lista *p = inicio;

    if (inicio == NULL)
    {
        printf("\nLista Vazia\n");
        return inicio;
    }

    else
    {
        while (p != NULL && p->codigo != cod)
        {
            ant = p;
            p = p->prox;
        }

        if (p == NULL)
        {
            printf("\nPessoa nao encontrado\n\n");
            return inicio;
        }

        /* retira elemento do inicio */
        if (ant == NULL)
            inicio = p->prox;

        /* retira elemento do meio da lista */
        else
            ant->prox = p->prox;

        *contador -= 1;
        printf("\nPessoa deletada com sucesso\n\n");
        free(p);
        return inicio;
    }
}
void totalp(int x)
{
    printf("\nNumero de Pessoas no Programa: %d\n", x);
}
void mostratudo(Lista *aux)
{
    Lista *j = aux;
    if (j == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    else
    {
        printf("\n\nLista de Pessoas no Programa:\n");

        while (j != NULL)
        {
            printf("Codigo: %-5d | Peso: %-6.2f | Sexo: %c |\n", j->codigo, j->peso, j->sexo);
            j = j->prox;
        }
    }
    printf("\n");
}