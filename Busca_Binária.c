#include<stdio.h>
#include<stdlib.h>

int binsrch(int low, int high);
int part(int *vet ,int inicio,int fim);
void qs(int *vet,int inicio,int fim);
int *vet;
int x;
int main()
{	
	int i;
	int n;
	int num;
		
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	vet = (int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
	{
		vet[i] = i;
	}
	
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d ", vet[i]);
	}
	
	printf("\n\nDigite o elemento a ser buscado: ");
	scanf("%d", &x);
		
	qs(vet, 0, n-1);

	num = binsrch(0, n-1);
	
	if(num == -1)
	{
		printf("\nO elemento nao foi encontrado");
	}
	else
	{
		printf("\nElemento %d encontrado no vetor, na posicao %d.", vet[num], num);
	}	
	
	return 0;
}

int binsrch(int low, int high)
{
	int mid;
	
	if(low>high)
	{
		return -1;
	}
	mid = (low+high)/2;
	
	if(x == vet[mid])
	{
		return mid;
	}
	else if(x < vet[mid])
	{
		binsrch(low, mid-1);
	}
	else 
	{
		binsrch(mid+1, high);
	}
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
