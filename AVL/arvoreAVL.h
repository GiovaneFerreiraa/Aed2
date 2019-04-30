#ifndef __ARVOREAVL_H__
#define __ARVOREAVL_H__

#include <stdlib.h>
#include <stdio.h>


typedef struct no no;
typedef struct arvore arvore;
// Estrutura da arvore
struct no
{
    int chave;
    no* esquerda; 
    no* direito;
    no* pai; 
};

struct arvore
{
    no* raiz;
};


//Funções usadas
no *Alocar(int chave);
void PercurssoEmOrdem(no *inicio);
void PercurssoPreOrdem(no *inicio);
void PercurssoPosOrdem(no *inicio);
void Inserir(arvore *inicio, no *novo);
no *Busca(no *inicio, int chave);
no *Maximo(no *inicio);
no *Minimo(no *inicio);
no *Sucessor(no *inicio);
no *Predecessor(no *inicio);
void Transplant(arvore *inicio, no *x, no *y);
void Deletar(arvore *inicio, no *chave);
int MaiorElemento(int x, int y);
int Altura(no *inicio);
no *Nodesregulado(no *inicio);
void RotacaoSimplesDireita(arvore *AVL, no *x);
void RotacaoSimplesEsquerda(arvore *AVL, no *x);
void RotacaoDuplaDireita(arvore *AVL, no *desreg);
void RotacaoDuplaEsquerda(arvore *AVL, no *desreg);
void Balancear(arvore *AVL, no *desreg);



#endif // __ARVOREAVL_H__

