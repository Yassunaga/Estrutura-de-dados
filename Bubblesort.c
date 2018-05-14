#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void bubblesort(int vet[],int n);

int main()
{
    int vet[100];
    int i, n;
    int opcao;

    while(opcao!=0)
    {
        printf("\n 1 - Inserir vetor ");
        printf("\n 2 - Ordenar vetor ");
		printf("\n 0 - Sair do programa: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            printf("\nDigite o tamanho de numeros do vetor: ");
            scanf("%d", &n);
            for(i=0;i<n; i++)
            {
                printf("Digite o numero %d: ", i);
                scanf("%d", &vet[i]);
            }
        break;

        case 2:
            bubblesort(vet, n);
            printf("\nMostrando vetores ordenados: ");
            for(i=0;i<n;i++)
            {
                printf("%d ", vet[i]);
            }
            printf("\n");
        break;
        
        case 3:
        	return 0;
        break;
		}
    }
}

void bubblesort(int vet[],int n)
{
    int trocou=1;
    int pass;
    int i;
    int hold=0;

    for(pass=0;pass<n-1 && trocou==1; pass++)
    {
        trocou=0;
        for(i=0;i<n-pass-1;i++)
        {
            if(vet[i]>vet[i+1])
            {
                trocou=1;
                hold = vet[i+1];
                vet[i+1] = vet[i];
                vet[i] = hold;
            }
        }
    }
}
