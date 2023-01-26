#include <stdio.h>
#include <stdlib.h>

// basicamente tem funcoes de inserir na fila (no final)
// ou retirar da fila (do inicio)
// estrutura fifo - first in first out

typedef struct no {
	int dado;
	struct no *proximo;
} No;

void push(No **fila, int num)
{
	No *novo = malloc(sizeof(No));
	No *aux;
	
	if(novo)
	{
		novo->dado = num;
		novo->proximo = NULL;
		// se a fila esta vazia
		if(*fila == NULL)
		{
			*fila = novo;
		}
		else
		{
			aux = *fila;
			while(aux->proximo)
			{
				aux = aux->proximo;
			}
			// percorreu a fila ate achar o fim
			aux->proximo = novo;
		}
	}
	else
		printf("\nErro ao alocar memoria.\n");
		
}

No* pop(No **fila)
{
	No *remover = NULL;
	
	if(*fila)
	{
		// ponteiro pro 1o elemento da fila
		remover = *fila;
		*fila = remover->proximo;
	}
	else
		printf("\nFila vazia!\n");
		
	return remover;
}

void imprime_fila(No *fila)
{
	printf("\t-------- FILA --------\n");
	while(fila)
	{
		printf("%d ", fila->dado);
		fila = fila->proximo;
	}
	printf("\n\t------ FIM FILA ------\n");
}

int main(void)
{
	No *fila = NULL;
	No *remove;
	int opcao, num;
	
	do{
		printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao)
		{
			case 1:
				printf("\nDigite um numero para colocar na fila: ");
				scanf("%d", &num);
				push(&fila, num);
				break;
			case 2:
				remove = pop(&fila);
				if(remove)
				{
					printf("\nRemovido com sucesso.\n");
					free(remove);
				}
				break;
			case 3:
				imprime_fila(fila);
				break;
			default:
				if (opcao!=0) { printf("\nOpcao invalida.\n"); }
		}
		
	}while(opcao!=0);
	
	return 0;
}
