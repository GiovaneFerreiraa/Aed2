#ifndef __ARVORERN_H__
#define __ARVORERN_H__

#include <stdlib.h>
#include <stdio.h>


typedef struct no no;
typedef struct arvore arvore;
struct no
{
    int cor;
    int chave;
    no* esquerda; 
    no* direito;
    no* pai; 
};

struct arvore
{
    no* raiz;
};


no *Alocar(int chave);
char Cor(no *inicio);
void Imprimir(no *inicio);
void PercurssoEmOrdem(no *inicio);
void PercurssoPreOrdem(no *inicio);
void PercurssoPosOrdem(no *inicio);
void Inserir (arvore *inicio, no *novo);
no *Busca(no *inicio, int chave);
no *Maximo(no *inicio);
no *Minimo(no *inicio);
no *Sucessor(no *inicio);
no *Predecessor(no *inicio);
int MaiorElemento(int x ,int y);
int CorOrigem(no *inicio);
no *TioNo(no *inicio);
int AlturaPreta(no *inicio);
void RotacaoSimplesDireita(arvore *AVL, no *x);
void RotacaoSimplesEsquerda(arvore *AVL, no *x);
void RotacaoDuplaDireita(arvore *AVL, no *desreg);
void RotacaoDuplaEsquerda(arvore *AVL, no *desreg);
void Balancear(arvore *AVL, no *desreg);

#endif // __ARVORERN_H__