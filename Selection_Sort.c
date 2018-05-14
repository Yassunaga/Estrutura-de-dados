#include<stdio.h>
#include<stdlib.h>

int main()
{
	int vet[5];
	int i;
	for(i=1;i<=5;i++)
	{
		scanf("%d", &vet[i]);
	}	
	
	int aux;
	int indice;
	int j;
	
	for(j=1; j<=4; j++)
	{
		indice = j;
		for(i=j+1;i<=5;i++)
		{
			if(vet[i] < vet[indice])
			{
				indice = i;
			}
		}
		aux = vet[j];
		vet[j] = vet[indice];
		vet[indice] = aux;
	}
	
	for(i=1;i<=5;i++)
	{
		printf("%d ", vet[i]);
	}
	return 0;
}
