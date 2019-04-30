#include "arvoreRN.h"


// Definição da cor dos nos das arvores

// 0 -> Vermelha;
// 1 -> Preto
no *Alocar(int chave)
{
    no *novo = (no*)malloc(sizeof(no));
    novo->esquerda = NULL;
    novo->direito = NULL;
    novo->pai = NULL;
    novo->chave = chave;
    novo->cor = 0;
    return novo;
}
// Definir a cor do no add

char Cor(no *no)
{
    if(no->cor == 0)
    {
        return 'R';
    }
    else
    {
        return 'N';
    }
}

//Imprimir os nos da arvore
void Imprimir(no *inicio)
{ 
    if(inicio != NULL)
    {
        printf("%d%c ", inicio->chave, Cor(inicio));
        /*if(inicio->pai != NULL)
        {
            printf("%d%c ",inicio->pai->chave, Cor(inicio));
            Cor(inicio->pai);
        }
        if(TioNo(inicio) != NULL)
        {
            no *tio = TioNo(inicio);
            printf("%d%c ", tio->chave, Cor(inicio));
            Cor(tio);
        }*/

       // printf("\n");
    }
    
}


void PercurssoEmOrdem(no *inicio)
{
    if(inicio != NULL){
        PercurssoEmOrdem(inicio->esquerda);
        Imprimir(inicio);
        PercurssoEmOrdem(inicio->direito);
    }

}

void PercurssoPreOrdem(no *inicio)
{   printf("(");
    if(inicio != NULL){
        Imprimir(inicio);
        if(inicio->esquerda != NULL){
            printf(" ");
            PercurssoPreOrdem(inicio->esquerda);
            if(inicio->direito == NULL){
                printf(" (X)");
                //free(inicio);
            }
        }
        if (inicio->direito != NULL)
        {   printf(" ");
            PercurssoPreOrdem(inicio->direito);
            //free(inicio);
            if(inicio->esquerda == NULL){
                printf("(X) ");
                //free(inicio);

            }
        }


        printf(")");
    }
    
}

void PercurssoPosOrdem(no *inicio)
{
    if(inicio != NULL){
        PercurssoPosOrdem(inicio->esquerda);
        PercurssoPosOrdem(inicio->direito);
        Imprimir(inicio);
    }

}
// insere o no
void Inserir (arvore *inicio, no *novo)
{   
    
    

    no *anterior = NULL;
    no *proximo = inicio->raiz;

    while(proximo != NULL)
    {
        anterior = proximo;
        if(novo->chave < proximo->chave)
        {
            proximo = proximo->esquerda;
        }
        else
        {
            proximo = proximo->direito;
        }
    }

    novo->pai = anterior;
    if(anterior == NULL)
    {
        inicio->raiz = novo;
    }

    else if(novo->chave < anterior->chave)
    {
        anterior->esquerda = novo;
    }
    else
    {
        anterior->direito = novo;
    }

    Balancear(inicio, novo);

}


no *Busca(no *inicio, int chave)
{
    if(inicio == NULL || inicio->chave == chave)
    {
        return inicio;
    }
    if(chave < inicio->chave)
    {
        return Busca(inicio->esquerda, chave);
    }
    else
    {
        return Busca(inicio->direito, chave);
    }
}

no *Maximo(no *inicio)
{
    if(inicio != NULL){
        while(inicio->direito != NULL){
            inicio = inicio->direito;
        }
        return inicio;
    }
}

no *Minimo(no *inicio)
{
    if(inicio != NULL){
        while(inicio->esquerda != NULL){
            inicio = inicio->esquerda;
        }
        return inicio;
    }
}

no *Sucessor(no *inicio)
{
    no *anterior;
    anterior = inicio->pai;
    if(inicio != NULL)
    {
        if(inicio->direito != NULL){
            return Minimo(inicio->direito);
        }
        else{
            while(anterior != NULL && inicio == anterior->direito){

                inicio = anterior;
                anterior = anterior->pai;
            }
            return anterior;
        }

    }
        
    
}

no *Predecessor(no *inicio)
{
    no *anterior;
    anterior = inicio->pai;
    if(inicio != NULL)
    {
        if(inicio->esquerda != NULL)
        {
            Maximo(inicio->esquerda);
        }else{
            while(anterior != NULL && inicio == anterior->esquerda){

                inicio = anterior;
                anterior = anterior->pai;
            }
            return anterior;
        }
    }

}

int MaiorElemento(int x ,int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}


//Saber qual sera a cor de do elemento
int CorOrigem(no *inicio)
{
    if(inicio->cor == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// Função usada para saber qual sera o tio do elemento
no *TioNo(no *inicio)
{
    no *tio = NULL;
    if(inicio->pai != NULL && inicio->pai->pai != NULL)
    {
        if(inicio->pai == inicio->pai->pai->direito)
        {
            tio = inicio->pai->pai->esquerda;
        }
        else if(inicio->pai == inicio->pai->pai->esquerda)
        {
            tio = inicio->pai->pai->direito;
        }
    }
    return tio;
}


//Ira calcular a altura dos nos pretos da arvore RN
//Que é um fator obrigatorio
int AlturaPreta(no *inicio)
{
    int altura, dir, esq;
    if(inicio == NULL)
    {
        return 0;
    }
    esq = AlturaPreta(inicio->esquerda);
    dir = AlturaPreta(inicio->direito);
    altura = MaiorElemento(esq, dir);
    if(CorOrigem(inicio) == 1)
    {
        altura++;
    }
    return altura;
}

void RotacaoSimplesDireita(arvore *AVL, no *x)
{
    no *y = x->esquerda;

    if(y != NULL)
    {
        x->esquerda = y->direito;
    }
    
    if(y->direito != NULL)
    {
        y->direito->pai = x;
    }

    y->pai = x->pai;
    
    if(x->pai == NULL)
    {
        AVL->raiz = y;
    }

    else if(x == x->pai->esquerda)
    {
        x->pai->esquerda = y;
    }

    else
    {
        x->pai->direito = y;
    }

    y->direito = x;
    x->pai = y;


}


void RotacaoSimplesEsquerda(arvore *AVL, no *x)
{
    no *y = x->direito;

    if(y != NULL)
    {
        x->direito = y->esquerda;
    }
    
    if(y->esquerda!= NULL)
    {
        y->esquerda->pai = x;
    }

    y->pai = x->pai;
    
    if(x->pai == NULL)
    {
        AVL->raiz = y;
    }

    else if(x == x->pai->esquerda)
    {
        x->pai->esquerda = y;
    }

    else
    {
        x->pai->direito = y;
    }

    y->esquerda = x;
    x->pai = y;


}


void RotacaoDuplaDireita(arvore *AVL, no *desreg)
{
    RotacaoSimplesEsquerda(AVL, desreg->esquerda);
    RotacaoSimplesDireita(AVL, desreg);

}

void RotacaoDuplaEsquerda(arvore *AVL, no *desreg)
{
    RotacaoSimplesDireita(AVL, desreg->direito);
    RotacaoSimplesEsquerda(AVL, desreg);
}

// Essa funçãod e balancear apresenta uma complexidade maior que o da AVL por apresentar casos a mais
void Balancear(arvore *AVL, no*desreg)
{
    if(desreg->pai == NULL)
    {
        desreg->cor = 1;
    }
    else if(desreg->pai->cor == 0)
    {
        if(TioNo(desreg) != NULL && TioNo(desreg)->cor == 0)
        {
            desreg->pai->cor = 1;
            //Verificar o tio
            TioNo(desreg)->cor = 1;
            desreg->pai->pai->cor = 0;
            Balancear(AVL, desreg->pai->pai);
        }
        else if(desreg == desreg->pai->esquerda)
        {
            if(desreg->pai == desreg->pai->pai->esquerda)
            {
                desreg->pai->cor = 1;
                desreg->pai->pai->cor = 0;
                RotacaoSimplesDireita(AVL, desreg->pai->pai);
            }
            else if(desreg == desreg->pai->esquerda && desreg->pai == desreg->pai->pai->direito)
            {
                desreg->cor = 1;
                desreg->pai->pai->cor = 0;
                RotacaoDuplaEsquerda(AVL, desreg->pai->pai);
            }
        }


    else if(desreg == desreg->pai->direito){

           if(desreg->pai == desreg->pai->pai->direito){

               

               desreg->pai->cor = 1;

               desreg->pai->pai->cor = 0;

               RotacaoSimplesEsquerda(AVL, desreg->pai->pai);

           }else if(desreg == desreg->pai->direito && desreg->pai == desreg->pai->pai->esquerda){

               

               desreg->cor = 1;

               desreg->pai->pai->cor = 0;

               RotacaoDuplaDireita(AVL, desreg->pai->pai);

           }

       }

   }
}
           

       


