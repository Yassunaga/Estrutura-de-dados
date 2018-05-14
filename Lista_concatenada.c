#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct lista
{
    int qtd;
    struct elemento *inicio;
}lista;

typedef struct elemento
{
    int matricula;
    char nome[30];
    struct elemento *prox;
}elemento;

elemento *aloca_elemento();
lista*aloca_lista();
int inserir(lista *l, char *nome, int matricula);
void mostrar(lista *l);
elemento * buscar(lista *l, char *nome);
int remover(lista *l, char *nome);

int main()
{
	int matricula, n;
    char nome[30];
    lista *l1;
    int result;
    elemento *procurado;

    l1=aloca_lista();

    do
    {
        printf("\n\n1 - Inserir ");
        printf("\n2 - Mostrar");
        printf("\n3 - Buscar ");
        printf("\n4 - Remover ");
        printf("\n5 - Sair ");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            printf("\nDigite o nome: ");
            fflush(stdin);
            scanf("%s", nome);

            printf("\nDigite a matricula: ");
            scanf("%d", &matricula);

            if(inserir(l1, nome, matricula))
            {
                printf("\nInserido com sucesso");
            }
        break;

        case 2:
            printf("\nMostrando lista: ");
            mostrar(l1);
            printf("\nFim da lista");
        break;

        case 3:
            printf("\nDigite o nome para buscar: ");
            fflush(stdin);
            gets(nome);
            procurado = buscar(l1, nome);
            if(procurado==NULL)
            {
                printf("\nNao encontrado");
            }
            else
            {
                printf("\nNome: %s\n Matricula: %d",procurado->nome, procurado->matricula);
            }
        break;

        case 4:
            printf("\nDigite o nome para remover: ");
            fflush(stdin);
            gets(nome);

            if(remover(l1, nome))
            {
                printf("\n\nRemovido com sucesso!");
            }
            else
            {
                printf("\nNao encontrado");
            }
        break;

        case 5:
            printf("\nSaindo do programa");
        break;

        default:
        {
            printf("Opcao invalida");
        }

        }

    }while(n!=5);
    return 0;
}

elemento *aloca_elemento()
{
    elemento *novo;
    novo = (elemento*)malloc(sizeof(elemento));
    novo->matricula=0;
    strcpy(novo->nome, " ");
    novo->prox = NULL;
    return novo;
}

lista*aloca_lista()
{
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->qtd=0;
    novo->inicio=NULL;
    return novo;
}

int inserir(lista *l, char *nome, int matricula)
{
    elemento *aux, *novo;
    novo = aloca_elemento();
    strcpy(novo->nome,nome);
    novo->matricula=matricula;

    if(l->inicio==NULL)
    {
        l->inicio = novo;
        return 1;
    }
    else
    {
        aux = l->inicio;
        while(aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        aux->prox=novo;

    }
    l->qtd++;
    return 1;
}

void mostrar(lista *l)
{
    elemento*aux;
    aux = l->inicio;
    while(aux!=NULL)
    {
        printf("\n");
        puts(aux->nome);
        printf("\nMatricula: %d\n", aux->matricula);
        aux=aux->prox;
    }
}

elemento * buscar(lista *l, char *nome)
{
    elemento *aux;

    if(l->inicio==NULL)
    {
        return NULL;
    }

    aux = l->inicio;
    while((aux->prox!=NULL) && (strcmp(nome, aux->nome)!= 0))
    {
        aux=aux->prox;
    }
    if(strcmp(aux->nome, nome)==0)
    {
        return aux;
    }
    else
    {
        return NULL;
    }
}

int remover(lista *l, char *nome)
{
    elemento*aux, *ant;

    if(l->inicio==NULL)
    {
        return 0;
    }
    else
    {
        ant=NULL;
        aux=l->inicio;
        while((strcmp(aux->nome, nome)!=0) && (aux->prox!=NULL))
        {
            ant=aux;
            aux=aux->prox;
        }
        if(strcmp(aux->nome,nome)==0)
        {
            if(ant==NULL)
            {
                l->inicio=aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            free(aux);
            l->qtd--;
        }
        else
        {
            return 0;
        }
    }
}
