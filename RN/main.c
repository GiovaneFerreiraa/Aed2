#include "arvoreRN.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
 /*int main()
 {
    arvore *inicio = (arvore*)malloc(sizeof(arvore));
    inicio->raiz = NULL;


    // Atribuição de valores 

    int valor1 = 12, valor2 = 2, valor3 = 13, valor4 = 32, valor5 = 1, valor6 = 10, valor7 = 4, valor8 = 0;


    // Inserir valores

    Inserir(inicio, Alocar(valor1));
    Inserir(inicio, Alocar(valor2));
    Inserir(inicio, Alocar(valor3));
    Inserir(inicio, Alocar(valor4));
    Inserir(inicio, Alocar(valor5));
    Inserir(inicio, Alocar(valor6));
    Inserir(inicio, Alocar(valor7));
    Inserir(inicio, Alocar(valor8));
    // Exibindo 

    printf("\nEM ORDEM: \n");
    PercurssoEmOrdem(inicio->raiz);

    printf("\nPRE ORDEM: \n");
    PercurssoPreOrdem(inicio->raiz);

    printf("\nPOS ORDEM: \n");
    PercurssoPosOrdem(inicio->raiz);
    printf("\n");

    int alt = AlturaPreta(inicio->raiz);
    printf("Altura da Arvore Preta: %d\n", alt);






 }*/

int main(int argc, char **argv)
{
    arvore *inicio = (arvore*)malloc(sizeof(arvore));

    FILE* Salvar;

    char op;
    
    if(argc > 5)
    {
        exit(-1);
    }

    while((op = getopt(argc, argv, "o:f:")) > 0 )
    {
        switch(op){
            case 'f':
                Salvar = fopen(optarg, "rb");
                int receber;
                    while(fscanf(Salvar, "%d", &receber)!=EOF)
                        {   
                    //printf("AQUIII\n");
                    Inserir(inicio, Alocar(receber));
                    //PercurssoPreOrdem(inicio->raiz);

                        }
            printf("\nPRE ORDEM: \n");
            PercurssoPreOrdem(inicio->raiz);
            printf("\n");
            fclose(Salvar);
        
            case 'o':
                Salvar = fopen(optarg, "wb+");
                int gravar;
                

        }
    

    }
}