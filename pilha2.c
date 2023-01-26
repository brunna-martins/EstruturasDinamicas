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

typedef struct {
	No *topo;
	int tam;
} Pilha;

void cria_pilha(Pilha *p)
{
	p->topo = NULL;
	p->tam = 0;
}

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
void push(Pilha *p)
{
	No *novo = malloc(sizeof(No));
	
	if (novo)
	{
		novo->dado = ler_dado();
		novo->proximo = p->topo;
		p->topo = novo;
		p->tam++;
	}
	else 
		printf("\nErro ao alocar memoria...\n");
		
}

// funcao para desempilhar dados
No* pop(Pilha *p)
{
	if(p->topo)
	{
		No *remover = p->topo;
		p->topo = remover->proximo;
		p->tam--;
		return remover;
	}
	else
		printf("\nPilha vazia!\n");
	return NULL;
}

void imprime_pilha(Pilha *p)
{
	No *aux = p->topo;
	printf("\n------------ PILHA TAM: %d------------\n", p->tam);
	
	while(aux)
	{
		imprime_dado(aux->dado);
		aux = aux->proximo;
	}
	
	printf("\n---------- FIM PILHA ----------\n");

	
}

int main(void)
{
	Pilha p;
	No *remover;
	int opcao;
	
	cria_pilha(&p);
	
	do 
	{
		printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao)
		{
			case 1:
				push(&p);
				break;
			case 2:
				remover = pop(&p);
				if(remover)
				{
					printf("\nElemento removido.\n");
					imprime_dado(remover->dado);
					free(remover);
				}
				else
					printf("\nSem no a remover\n");	
				break;
			case 3:
				imprime_pilha(&p);
				break;
			default:
				if(opcao != 0) printf("\nOpcao Invalida!\n");
		}
			
	} while (opcao != 0);
	
	return 0;
}
