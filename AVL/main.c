#include "arvoreAVL.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
 

 /*int main()
 {
    arvore *inicio = (arvore*)malloc(sizeof(arvore));
    inicio->raiz = NULL;


     //Atribuição de valores 
    // So pode dois numeros neg ativos
    

    int valor1 = 21, valor2 = 3, valor3 = 41, valor4 = 13, valor5 = 4, valor6 = 6, valor7 = 84;//, valor8 = 105, valor9 = 1;


     //Inserir valores

    Inserir(inicio, Alocar(valor1));
    Inserir(inicio, Alocar(valor2));
    Inserir(inicio, Alocar(valor3));
    Inserir(inicio, Alocar(valor4));
    Inserir(inicio, Alocar(valor5));
    Inserir(inicio, Alocar(valor6));
    Inserir(inicio, Alocar(valor7));
    //Inserir(inicio, Alocar(valor8));
    //Inserir(inicio, Alocar(valor9));
     
    //Exibindo 

    printf("\nEM ORDEM: \n");
    PercurssoEmOrdem(inicio->raiz);

    printf("\nPRE ORDEM: \n");
    PercurssoPreOrdem(inicio->raiz);

    printf("\nPOS ORDEM: \n");
    PercurssoPosOrdem(inicio->raiz);
    printf("\n");

    int alt = Altura(inicio->raiz);
    printf("Altura da Arvore: %d\n", alt);

    return 0;

	






 }*/
// Função onde sera usada para carregar os elementos do arquivo
    
int main(int argc, char **argv)
{
	arvore *inicio = (arvore*)malloc(sizeof(arvore));

	FILE* Salvar;

    char op;
	
	if(argc > 5)
    {
        exit(-1);
    }

    while((op = getopt(argc, argv, "f:")) > 0 )
    {
        switch(op){
            case 'f':
            Salvar = fopen(optarg, "r");
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
        }
    }}