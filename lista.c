#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	// pode ter qualquer tipo de dado
	// aqui eh int soh para facilitar
	int valor;
	struct no *proximo;
} No;

// procedimento para inserir no inicio
void inserir_inicio (No **lista, int dado)
{
	No *novo = malloc(sizeof(No));
	if (novo)
	{
		novo->valor = dado;
		// o novo proximo aponta para o comeco da lista
		novo->proximo = *lista;
		// agora a lista recebe como inicio esse novo no
		*lista = novo;
	}
	else
		printf("\nErro ao alocar memoria.\n");
}

// procedimento para inserir no fim da lista

void inserir_fim (No **lista, int dado)
{
	No *novo = malloc(sizeof(No));
	No *aux = malloc(sizeof(No));
	if (novo)
	{
		novo->valor = dado;
		// como eh o ultimo elemento, nao tem um proximo
		novo->proximo = NULL;
		
		// eh o primeiro elemento da lista?
		// o fim eh o inicio
		if (*lista == NULL)
		{
			*lista = novo;
		}
		else
		{
			aux = *lista;
			// quando isso for falso, cheguei no fim da lista
			while(aux->proximo)
			{
				aux = aux->proximo;
			}
			aux->proximo = novo;
		}
	}
	else
		printf("\nErro ao alocar memoria.\n");
}

// procedimento para inserir no meio da lista
void inserir_meio(No **lista, int dado, int dado_anterior)
{
	No *novo = malloc(sizeof(No));
	No *aux = malloc(sizeof(No));
	
	if(novo)
	{
		novo->valor = dado;
		// lista estah vazia, ou seja, esse eh o primeiro no da lista?
		if (*lista == NULL)
		{
			novo->proximo == NULL;
			*lista = novo;
		}
		else // lista nao estah vazia
		{
			// aux estah apontando pro primeiro elemento da lista
			aux = *lista;	
			// procurando o valor de dado_anterior na lista
			// eh necessario para acharmos onde posicionar nosso dado atual
			while(aux->valor!=dado_anterior && aux->proximo)
			{
				aux = aux->proximo;
			}
			// se antes tinhamos aux - proximo
			// agora temos aux - novo - proximo
			// inserimos no meio
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
	}	
	else
		printf("\nErro ao alocar memoria.\n");
}

void imprimir(No *no)
{
	printf("\n\tLista: ");
	while(no) // no !=null
	{
		printf("%d ", no->valor);
		no = no->proximo;
	}
	printf("\n\n");
}

int main(void)
{
	int opcao, valor, referencia;
	No *lista = NULL;
	
	do
	{
		printf("\n\t0 - Sair\n\t1 - Inserir no Inicio\n\t2 - Inserir no Fim\n\t3 - Inserir no Meio\n\t4 - Imprimir Lista\n");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				printf("\n\tDigite um valor inteiro: ");
				scanf("%d", &valor);
				inserir_inicio(&lista, valor);
				break;
			case 2:
				printf("\n\tDigite um valor inteiro: ");
				scanf("%d", &valor);
				inserir_fim(&lista, valor);
				break;
			case 3:
				printf("\n\tDigite um valor inteiro: ");
				scanf("%d", &valor);
				printf("\n\tDigite um valor de referencia: ");
				scanf("%d", &referencia);
				inserir_meio(&lista, valor, referencia);
				break;
			case 4:
				imprimir(lista);
				break;
			default:
				if (opcao!=0) { printf("\t\nOpcao invalida!\n"); }
		}	
	} while(opcao!=0);
	
	
	
	return 0;
}
