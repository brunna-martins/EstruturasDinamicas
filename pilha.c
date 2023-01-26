#include <stdio.h>
#include <stdlib.h>

// duas funcoes basicas: empilhar e desempilhar
// push e pop
// estrutura lifo - last in, first out

typedef struct no {
	// pode ser qualquer dado, aqui e int para facilitar
	int dado;
	// ponteiro para o proximo dado alocado
	struct no *proximo; 
} No;

void imprime_dado(int dado)
{
	printf("\nDado: %d\n", dado);
}

// funcao para coletar dado
int ler_dado()
{
	int dado;
	printf("\nDigite o dado a ser armazenado: ");
	scanf("%d", &dado);
	printf("\n");
	return dado;
}

// funcao para empilhar dados
No* push(No *topo)
{
	No *novo = malloc(sizeof(No));
	
	if (novo)
	{
		novo->dado = ler_dado();
		novo->proximo = topo;
		return novo;
	}
	else 
		printf("\nErro ao alocar memoria...\n");
	return NULL;
		
}

// funcao para desempilhar dados
// atencao para o ponteiro de ponteiro
// para de fato poder alterar a regia de memoria
// e nao pega-la por copia
No* pop(No **topo)
{
	if(*topo != NULL)
	{
		No *remover = *topo;
		*topo = remover->proximo;
		return remover;
	}
	else
		printf("\nPilha vazia!\n");
	return NULL;
}

void imprime_pilha(No *topo)
{
	printf("\n------------ PILHA ------------\n");
	
	while(topo)
	{
		imprime_dado(topo->dado);
		topo = topo->proximo;
	}
	
	printf("\n---------- FIM PILHA ----------\n");

	
}

int main(void)
{
	// todas as operacoes sao feitas no topo
	// inicialmente a pilha e vazia
	No *topo = NULL;
	No *remover;
	int opcao;
	
	do 
	{
		printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao)
		{
			case 1:
				topo = push(topo);
				break;
			case 2:
				remover = pop(&topo);
				if(remover)
				{
					printf("\nElemento removido.\n");
					imprime_dado(remover->dado);
				}
				else
					printf("\nSem no a remover\n");	
				break;
			case 3:
				imprime_pilha(topo);
				break;
			default:
				if(opcao != 0) printf("\nOpcao Invalida!\n");
		}
			
	} while (opcao != 0);
	
	return 0;
}
