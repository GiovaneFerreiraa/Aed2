#include "contato.h"
#include "string.h"
#include <stdlib.h>
 /*  
		Definiçaõ da estrutua contato que sera usada np armazenamento da hash
	onde foi usado algumas carcteristicas de uma agenda, sendo cada posisão do hash ira ocupar 
	um pessoa com codigo, nome, telone e email.
		Apresenta as definições de cada função onde é criado e pegado o dado de cada estrutura


 */
struct contato
{
	int codigo;
	char nome[255];
	char telefone[30];
	char email[50];
};
 // Criação dos dados
Contato* contato_criar(int codigo, char nome[], char telefone[], char email[])
{
	Contato *c = (Contato*) malloc (sizeof(Contato));
	c->codigo = codigo;
	strcpy(c->nome, nome);
	strcpy(c->telefone, telefone);
	strcpy(c->email, email);
	return c;
}
 
int contato_getCodigo(Contato *c)
{
	return c->codigo;
}
 
char* contato_getNome(Contato *c)
{
	return c->nome;
}
 
char* contato_getTelefone(Contato *c)
{
	return c->telefone;
}
 
char* contato_getEmail(Contato *c)
{
	return c->email;
}
 
void contato_setCodigo(Contato *c, int codigo)
{
    c->codigo = codigo;
}
 
void contato_setNome(Contato *c, char nome[])
{
    strcpy(c->nome, nome);
}
 
void contato_setTelefone(Contato *c, char telefone[])
{
    strcpy(c->telefone, telefone);
}
 
void contato_setEmail(Contato *c, char email[])
{
    strcpy(c->email, email);
}
 
void contato_destruir(Contato *c)
{
    free(c);
    c = NULL;
}
