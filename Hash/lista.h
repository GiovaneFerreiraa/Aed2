#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
 
typedef struct lista Lista;
 
Lista* lista_criar();
void lista_inserirInicio(Lista* l, int codigo, void *item);
void lista_inserirFim(Lista* l, int codigo, void *item);
void lista_inserir(Lista* l, int codigo, void *item, int posicao);
void* lista_buscar(Lista* l, int posicao);
void* lista_buscarCodigo(Lista* l, int codigo);
void lista_excluir(Lista* l, int posicao);
int lista_tamanho(Lista* l);
void lista_destruir(Lista* l);
 
#endif // LISTA_H_INCLUDED
