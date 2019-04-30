#include "arvoreAVL.h"

//Alocar o espaço para o novo elemento a ser inserido

no *Alocar(int chave)
{
    no *novo = (no*)malloc(sizeof(no));
    novo->esquerda = NULL;
    novo->direito = NULL;
    novo->pai = NULL;
    novo->chave = chave;
    return novo;

}

void PercurssoEmOrdem(no *inicio)
{
    if(inicio != NULL){
        PercurssoEmOrdem(inicio->esquerda);
        printf("%d\n", inicio->chave);
        PercurssoEmOrdem(inicio->direito);
    }

}
//Mostra o percusso em  pre ordem ja ordenado da AVL 
void PercurssoPreOrdem(no *inicio)
{
    if(inicio != NULL){
        printf("(%d", inicio->chave);
        if(inicio->esquerda != NULL){
            printf(" ");
            PercurssoPreOrdem(inicio->esquerda);
            if(inicio->direito == NULL){
                printf(" (X)");
            }
        }
        if (inicio->direito != NULL)
        {   printf(" ");
            PercurssoPreOrdem(inicio->direito);
            if(inicio->esquerda == NULL){
                printf("(X) ");

            }
        }


        printf(")");
    }
    //printf("\n");
}

void PercurssoPosOrdem(no *inicio)
{
    if(inicio != NULL){
        PercurssoPosOrdem(inicio->esquerda);
        PercurssoPosOrdem(inicio->direito);
        printf("%d\n", inicio->chave);
    }

}

// Aqui é onde se é inserido o novo elemento
void Inserir(arvore *inicio, no *novo)
{   //printf("Inserir\n");
    no *anterior = NULL;
    no *proximo = inicio->raiz;

	while(proximo != NULL){

		anterior = proximo;

		if(novo->chave <= proximo->chave ){

			proximo = proximo->esquerda;

		}else{

			proximo = proximo->direito;

		}

	}

	novo->pai = anterior;

	if(anterior == NULL){

		inicio->raiz = novo;

	}

	else if(novo->chave <= anterior->chave){

		anterior->esquerda = novo;

	}

	else{

		anterior->direito = novo;

	}

    //Aqui faz a verificaçção se tera um no desregulado e assim executar o balanceamento

  no* desreg  = Nodesregulado(novo);
    
    if(desreg != NULL)
    {
       //Função para balancear;
       Balancear(inicio, desreg);
    }
}

// Buscar o elemeto na arvore de acordo com seu valor
no *Busca(no *inicio, int chave)
{
    if(inicio == NULL || inicio->chave == chave){
        
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

// O maximo
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


//Mostra o elemento sucessor
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

// Elemento predecessor
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
// Essa função sera usada para deletar o elemento
void Transplant(arvore *inicio, no *x, no *y)
{
    if(x == NULL || x == inicio->raiz)
    {
        inicio->raiz = y;
    }
    else if(x == x->pai->esquerda)
    {
        x->pai->esquerda = y;
    }
    else
    {
        x->pai->direito = y;
    }
    if( y != NULL)
    {
        y->pai = x->pai;
    }
}
void Deletar(arvore *inicio, no *chave)
{
    no *aux = NULL;
    if (chave->esquerda == NULL)
    {
        Transplant(inicio, chave, chave->direito);
    }
    else if(chave->direito == NULL)
    {
        Transplant(inicio, chave, chave->esquerda);
    }
    else
    {
        aux = Maximo(chave->direito);
        if(aux->pai != chave)
        {
            Transplant(inicio, aux, aux->direito);
            aux->direito = chave->direito;
            aux->direito->pai = chave;
        };
        Transplant(inicio, chave, aux);
        aux->esquerda = chave->esquerda;
        aux->esquerda->pai = aux;
    }
}

// Selecionar o maior elemento
int MaiorElemento(int x, int y)
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


// Calcular a altura da arvore para que se possa fazer o balaceamento
int Altura(no *inicio)
{   //printf("Altura\n");
    if(inicio == NULL)
    {
        return 0;
    }
    else 
    {
        //printf("Return\n");
        return MaiorElemento(Altura(inicio->esquerda), Altura(inicio->direito)+1);
    }
}

// Função que é chamada no inserir para ver se o no esta desregulado
no *Nodesregulado(no *inicio)
{
    no *pai = inicio->pai;
    if(pai == NULL)
    {
        return NULL;
    }
    while(pai != NULL)
    {
        if (abs(Altura(pai->esquerda) - Altura(pai->direito)) > 1)
        {
            return pai;
        }
        pai = pai->pai;
    }
    return NULL;

}

//Primeira rotação simples a direita
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

//Rotação simples a esquerda
void RotacaoSimplesEsquerda(arvore *AVL, no *x)
{   //printf("Sucesso RotacaoSimplesEsquerda\n");
    no *y = x->direito;

    if(y != NULL)
    {
        x->direito = y->esquerda;
    }
    //printf("Primeiro if\n");
    if(y->esquerda != NULL)
    {
        printf("y->esquerda\n");
        y->esquerda->pai = x;
        printf("x\n");
    }

    y->pai = x->pai;
    //printf("segundo IF\n");
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

    //printf("Sucesso Re\n");
}


void RotacaoDuplaDireita(arvore *AVL, no *desreg)
{   
    //Chamada das funções das rotações onde segue a sequencia

    RotacaoSimplesEsquerda(AVL, desreg->esquerda);
    RotacaoSimplesDireita(AVL, desreg);

}

void RotacaoDuplaEsquerda(arvore *AVL, no *desreg)
{
    RotacaoSimplesDireita(AVL, desreg->direito);
    RotacaoSimplesEsquerda(AVL, desreg);
}


// Aqui vai ser chamada a funçaõ que ira balancear a arvore sendo assim fazendo algumas verificações
void Balancear(arvore * AVL, no *desreg)
{   //printf("Funçao Balancear\n");
	if(Altura(desreg->esquerda) > Altura(desreg->direito))
    {
        //printf("Altura esquerda maior\n");
        no *auxiliar = desreg->esquerda;
        if(Altura(auxiliar->esquerda) > Altura(auxiliar->direito))
        {   //printf("auxiliar\n");
            RotacaoSimplesDireita(AVL,desreg);
        }
        else
        {   //printf("RDD\n");
            RotacaoDuplaDireita(AVL,desreg);
        }
    }
    else
    {   //printf("auxiliar2\n");
        no *auxiliar2 = desreg->direito;
        if(Altura(auxiliar2->direito) > Altura(auxiliar2->esquerda))
        {
            RotacaoSimplesEsquerda(AVL,desreg);
        }
        else
        {
            RotacaoDuplaEsquerda(AVL,desreg);
        }

        }
    }



