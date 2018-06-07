#include<stdio.h>
#include<stdlib.h>

void mergesort(int *vet, int inicio,int fim);

int main()
{	
	int vet[5] = {10, 9, 7, 13, 5};
	
	int i;
	printf("\nMostrando Vetor: ");
	for(i=0; i<5;i++)
	{
		printf("%d ", vet[i]);
	}
	
	mergesort(vet,0, 4);
	
	printf("\nMostrando vetor ordenado: ");
	for(i=0; i<5;i++)
	{
		printf("%d ", vet[i]);
	}
	
	return 0;
}

void mergesort(int *vet, int inicio,int fim)
{
	if(fim == inicio)
	{
		return;
	}
	int meio = (inicio+fim)/2;
	mergesort(vet, inicio, meio);
	mergesort(vet, meio+1, fim);
	
	int i=inicio;
	int j=meio+1;
	int k=0;
	int *aux;
	aux = (int*)malloc(sizeof(int)*(fim-inicio+1));
	
	while(i<meio+1 || j<fim+1)
	{
		if(i==meio+1)
		{
			aux[k] = vet[j];
			k++; j++;
		}
		if(j==fim+1)
		{
			aux[k] = vet[i];
			k++; i++;
		}
		else if(vet[i] < vet[j])
		{
			aux[k] = vet[i];
			k++; i++;
		}
		else
		{
			aux[k] = vet[j];
			k++; j++;
		}
	}
	for(i=inicio; i<=fim; i++)
		{
			vet[i] = aux[i-inicio];
		}
		free(aux);
		return;
	
}
