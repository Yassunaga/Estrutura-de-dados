#include<stdio.h>
#include<stdlib.h>

int main()
{
	int vet[10];
	int i;
	for(i=1;i<=5;i++)
	{
		scanf("%d", &vet[i]);
	}
	int j;
	int aux;
	for(i=2;i<=5;i++)
	{
		aux = vet[i];
		for(j=i-1;j>=1 && aux < vet[j] ;j--) 
		{
			vet[j+1] = vet[j]; //empurrando os números
		}
		vet[j+1] = aux;
	}
	
	for(i=1;i<=5;i++)
	{
		printf("%d ", vet[i]);
	}
	
	return 0;
}
