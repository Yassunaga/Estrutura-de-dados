#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void qs(int *vet,int inicio,int fim);

int main()
{
	int *vet, n, i;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	vet = (int*)malloc(sizeof(int)*n);
	
	printf("\n");
	for(i=0; i<n;i++)
	{
		printf("Elemento %d: ", i+1);
		scanf("%d", &vet[i]);
	}
	
	qs(vet, 0, n-1);
	
	printf("\n: : : Mostrando vetor ordenado : : : \n\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d ", vet[i]);
	}
	
	return 0;
}

void qs(int *vet,int inicio,int fim)
{
	if(fim>inicio)
	{
		int pivo = part(vet , inicio, fim);
		qs(vet, inicio, pivo-1);
		qs(vet, pivo+1, fim);
	}
	
	
}

int part(int *vet ,int inicio,int fim)
{
	int esquerda = inicio;
	int direita = fim;
	int pivo = vet[inicio];
	int aux;
	while(esquerda<direita)
	{
		while(vet[esquerda] <= pivo && esquerda <=fim)
		{
			esquerda++;
		}
		while(vet[direita] > pivo)
		{
			direita--;
		}
		if(esquerda<direita)
		{
			aux = vet[direita];
			vet[direita] = vet[esquerda];
			vet[esquerda] = aux;	
		}
	}
	vet[inicio] = vet[direita];
	vet[direita] = pivo;
	return direita;
}
