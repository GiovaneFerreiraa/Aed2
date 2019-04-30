#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct no No;
 
struct no
{
    int codigo;
	void* item;
	No* proximo;
};
 
struct lista
{
	int tamanho;
	No* inicio;
	No* fim;
};
 
Lista* lista_criar()
{
	Lista* l = malloc(sizeof(Lista));
	l->tamanho = 0;
	l->inicio = NULL;
	l->fim = NULL;
	return l;
}
 
void lista_inserirInicio(Lista* l, int codigo, void* item)
{
	No* n = malloc (sizeof(No));
	n->codigo = codigo;
	n->item = item;
	if (l->tamanho == 0)
	{
		n->proximo = NULL;
		l->inicio = n;
		l->fim = n;
		l->tamanho++;
		return;
	}
	n->proximo = l->inicio;
	l->inicio = n;
	l->tamanho++;
}
 
void lista_inserirFim(Lista* l, int codigo, void *item)
{
	if(l->tamanho == 0)
	{
		lista_inserirInicio(l, codigo, item);
		return;
	}
	No* n = malloc(sizeof(No));
	n->codigo = codigo;
	n->item = item;
	n->proximo = NULL;
	l->fim->proximo = n;
	l->fim = n;
	l->tamanho++;
}
 
void lista_inserir(Lista* l, int codigo, void *item, int posicao)
{
	if (posicao <= 0)
	{
		lista_inserirInicio(l, codigo, item);
		return;
	}
	if (posicao >= l->tamanho)
	{
		lista_inserirFim(l, codigo, item);
		return;
	}
	int i;
	No* local = l->inicio;
	for (i = 0; i < posicao - 1; i++)
	{
		local = local->proximo;
	}
	No* n = malloc(sizeof(No));
	n->codigo = codigo;
	n->item = item;
	n->proximo = local->proximo;
	local->proximo = n;
	l->tamanho++;
}
 
void* lista_buscar(Lista* l, int posicao)
{
	if (l->tamanho == 0)
	{
		return ""; // Lista vazia
	}
	if ((posicao < 0) || (posicao >= l->tamanho))
	{
		return ""; // fora da area de abrangencia
	}
	No* local = l->inicio;
	int i;
	for (i = 0; i < posicao; i++)
	{
		local = local->proximo;
	}
	return local->item;
}
 
void* lista_buscarCodigo(Lista* l, int codigo)
{
    No* local = l->inicio;
    while (local != NULL)
    {
        if (local->codigo == codigo)
        {
            return local->item;
        }
        local = local->proximo;
    }
    return NULL;
}
 
void lista_excluir(Lista* l, int posicao)
{
	if (l->tamanho == 0)
	{
		return;
	}
	if (l->tamanho == 1)
	{
		free(l->inicio);
		l->tamanho = 0;
		l->inicio = NULL;
		l->fim = NULL;
	}
	if (posicao == 0)
	{
		No* aux = l->inicio;
		l->inicio = aux->proximo;
		free(aux);
		l->tamanho--;
		return;
	}
	No* local = l->inicio;
	int i = 0;
	for (i = 0; i < posicao - 1; i++)
	{
		local = local->proximo;
	}
	No* aux = local->proximo;
	local->proximo = aux->proximo;
	free(aux->item);
	free(aux);
	if (local->proximo == NULL)
	{
		l->fim = local;
	}
	l->tamanho--;
}
 
int lista_tamanho(Lista* l)
{
	return l->tamanho;
}
 
void lista_destruir(Lista* l)
{
	if (l->tamanho == 0)
	{
		return;
	}
	while (l->inicio != NULL)
	{
		No* aux = l->inicio;
		l->inicio = l->inicio->proximo;
		free(aux->item);
		free(aux);
	}
	l->tamanho = 0;
	free(l);
	l = NULL;
}
