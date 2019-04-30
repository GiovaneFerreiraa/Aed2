#include "hash.h"
#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

#define OPERADOR    4
 
struct hash
{
	Lista* vet[OPERADOR];
};
 
Hash* hash_criar()
{
	int i;
	Hash* h = malloc(sizeof(Hash));
	for (i = 0; i < OPERADOR; i++)
	{
		h->vet[i] = lista_criar();
	}
	return h;
}
 
void hash_inserir(Hash* h, int codigo, void *item)
{
	int chave = (codigo % OPERADOR);
	lista_inserirInicio(h->vet[chave], codigo, item);
}
 
void* hash_buscar(Hash* h, int codigo)
{
    return lista_buscarCodigo(h->vet[codigo % OPERADOR], codigo);
}
 
void hash_destruir(Hash* h)
{
	int i;
	for (i = 0; i < OPERADOR; i++)
	{
		lista_destruir(h->vet[i]);
	}
	free(h);
	h = NULL;
}
