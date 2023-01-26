#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int numero;
	struct no *proximo;
} No;

No* push(No *pilha, int num)
{
	No *novo = malloc(sizeof(No));
	
	if(novo)
	{
		novo->numero = num;
		novo->proximo = pilha;
		return novo;
	}
	else
		printf("\nErro ao alocar memoria.\n");
	return NULL;
}

No* pop(No **pilha)
{
	No *remover = NULL;
	
	if(*pilha)
	{
		remover = *pilha;
		*pilha = remover->proximo;
	}
	else
		printf("\nPilha vazia.\n");
	return remover;
}

void imprime_pilha(No *pilha)
{
	printf("\n\tPILHA\n");
	while(pilha)
	{
		printf("\t%d\n", pilha->numero);
		pilha = pilha->proximo;
	}
	printf("\n");
}

int fatorial(int num)
{
	No *pilha = NULL;
	No *remover;
	
	while(num > 1)
	{
		pilha = push(pilha, num);
		num--;
	}
	
	imprime_pilha(pilha);
	
	while(pilha)
	{
		remover = pop(&pilha);
		num = num * remover->numero;
		free(remover);
	}
	
	return num;
}

int main(void)
{
	int meunumero;
	
	printf("Digite um valor maior que zero para calcular seu fatorial: ");
	scanf("%d", &meunumero);
	printf("\tFatorial de %d: %d\n", meunumero, fatorial(meunumero));
	return 0;
}
