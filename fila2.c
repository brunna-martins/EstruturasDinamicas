#include <stdio.h>
#include <stdlib.h>

// basicamente tem funcoes de inserir na fila (no final)
// ou retirar da fila (do inicio)
// estrutura fifo - first in first out

typedef struct no {
	int dado;
	struct no *proximo;
} No;

typedef struct {
	No *inicio;
	// insercao mais eficiente pois temos ponteiro para o fim da fila
	No *fim;
	int tam;
} Fila;

// inicializando a fila
void cria_fila(Fila *fila)
{
	fila->inicio = NULL;
	fila->fim = NULL;
	fila->tam = 0;
}

void push(Fila *fila, int num)
{
	No *novo = malloc(sizeof(No));
	No *aux;
	
	if(novo)
	{
		novo->dado = num;
		novo->proximo = NULL;
		// se a fila esta vazia
		if(fila->inicio == NULL)
		{
			//insercao do primeiro no
			fila->inicio = novo;
			fila->fim = novo;
		}
		else // fila nao ta vazia
		{
			// o no seguinte do no no fim e o novo
			fila->fim->proximo = novo;
			// agora o fim e esse novo no
			fila->fim = novo;
		}
		fila->tam++;
	}
	else
		printf("\nErro ao alocar memoria.\n");
		
}

No* pop(Fila *fila)
{
	No *remover = NULL;
	
	if(fila->inicio)
	{
		// ponteiro pro 1o elemento da fila
		remover = fila->inicio;
		fila->inicio = remover->proximo;
		fila->tam--;
	}
	else
		printf("\nFila vazia!\n");
		
	return remover;
}

void imprime_fila(Fila *fila)
{
	No *aux = fila->inicio;
	printf("\t-------- FILA --------\n");
	while(aux)
	{
		printf("%d ", aux->dado);
		aux = aux->proximo;
	}
	printf("\n\t------ FIM FILA ------\n");
}

int main(void)
{
	Fila fila;
	No *remove;
	int opcao, num;
	
	cria_fila(&fila);
	
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
				imprime_fila(&fila);
				break;
			default:
				if (opcao!=0) { printf("\nOpcao invalida.\n"); }
		}
		
	}while(opcao!=0);
	
	return 0;
}
