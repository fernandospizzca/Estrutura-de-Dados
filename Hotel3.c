#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int codigo;
  float peso;
  char sexo;
} hospede;

typedef hospede hotel;

hotel pessoa[10];

//Verifica quantas pessoas existem cadastradas no hotel
void numeroPessoas(int fim)
{
  if (fim == -1)
    printf("Nao ha pessoas cadastradas");

  else
  {
    printf("Numero de hospedes eh de %d", fim + 1);
  }
}

//retorna a pessoa mais pesada
void maisPesado(int t)
{
  if (t == -1)
    printf("\nNao ha pessoas cadastradas\n");
  else
  {
    printf("\nPessoa codigo %d possui o maior peso: %.2fKg\n\n", pessoa[0].codigo, pessoa[0].peso);
  }
}

//retorna a pessoa menos pesada
void menosPesado(int t)
{

  if (t == -1)
    printf("\nNao ha pessoas cadastradas\n");
  else
    printf("\nPessoa codigo %d possui o menor peso: %.2fKg\n\n", pessoa[t].codigo, pessoa[t].peso);
}

//retorna a pessoa no codigo indicado
int mostrarPessoa(int cod, int fim)
{
  int y = 0;
  if (fim == -1)
  {
    printf("\nNao ha pessoas cadastradas\n");
    return 0;
  }
  else
  {
    for (y = 0; y <= fim; y++)
    {
      if ((pessoa + y)->codigo == cod)
        return printf("\nDados encontrados: Codigo: %d Peso: %.2f Sexo: %c\n\n", pessoa[y].codigo, pessoa[y].peso, pessoa[y].sexo);
    }

    printf("\nPessoa nao encontrada\n");
  }
}

// excluir uma pessoa do hotel
void delete (int cod, int *fim)
{
  int k, i = 0;

  if (*fim == -1)
  {
    printf("\nNao ha pessoas cadastradas\n");
    return;
  }
  else
  {
    for (k = 0; k <= *fim; k++)
    {
      if ((pessoa + k)->codigo == cod)
      {
        for (i = k; i <= *fim - 1; i++)
        {
          *(pessoa + i) = *(pessoa + i + 1);
        }

        (pessoa + i)->codigo = '\0';
        (pessoa + i)->peso = '\0';
        (pessoa + i)->sexo = '\0';
       
        *fim -= 1;
        printf("\nPessoa removida com sucesso\n");
        return;
      }
    }
  }
}

//Mostra os dados de todas as pessoas cadastradas
void mostrarTudo(int fim)
{

  if (fim == -1)
  {
    printf("\nNao ha pessoas cadastradas\n");
    return;
  }

  else
  {
    for (int x = 0; x <= fim; x++)
      printf("\nCodigo: %d Peso: %.2f Sexo: %c\n", pessoa[x].codigo, pessoa[x].peso, pessoa[x].sexo);
  }
}

//Inserir uma pessoa na lista
void inserirPessoa(int *fim, int index)
{
  int i;
  hotel novo;

  if (*fim == 9)
    printf("Nao ha vagas para novos hospedes");

  else
  {
    printf("Informe o codigo do hospede: ");
    scanf("%d", &novo.codigo);
    printf("Informe o Peso do Hospede: ");
    scanf("%f", &novo.peso);
    printf("Informe o sexo do Hospede M/F: ");
    getchar();
    scanf("%c", &novo.sexo);
    index = *fim + 1;

    for (i = 0; i <= *fim; i++)
    {

      if ((pessoa + i)->peso <= novo.peso)
      {
        index = i;
        i = *fim;
      }
    }

    if (*fim >= 0)
    {

      for (i = *fim; i >= index; i--)
      {
        *(pessoa + i + 1) = *(pessoa + i);
      }
    }
    *(pessoa + index) = novo;

    *fim += 1;
  }
}

int main()
{
  int opcao, codigo, index = 0;
  int fim = -1;
  float peso;
  char sexo;

  while (opcao != 8)
  {
    printf("\nOpcoes:\n1. Mais pesado\n2. Menos pesado\n3. Consultar Pessoa\n4. Inserir Pessoa\n5. Remover Pessoa\n6. Numero de hospedes\n7. Mostrar Pessoas\n8. Fim\n\nDigite a opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {
      maisPesado(fim);
      break;
    }

    case 2:
    {
      menosPesado(fim);
      break;
    }

    case 3:
    {
      printf("\n\ninforma o codigo para pesquisa: ");
      scanf("%d", &codigo);
      mostrarPessoa(codigo, fim);
      break;
    }

    case 4:
    {
      inserirPessoa(&fim, index);
      break;
    }

    case 5:
    {
      printf("\n\nInforma o codigo para excluir: ");
      scanf("%d", &codigo);
      delete (codigo, &fim);
      break;
    }

    case 6:
    {
      numeroPessoas(fim);
      break;
    }

    case 7:
    {
      mostrarTudo(fim);
      break;
    }

    case 8:
    {
      printf("FIM");
      break;
    }

    default:
      printf("\nErro, por favor digite um valor valido\n");
    }
  }
  return 0;
}
