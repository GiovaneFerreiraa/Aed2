#ifndef CONTATO_H_INCLUDED
#define CONTATO_H_INCLUDED
 
typedef struct contato Contato;
 
Contato* contato_criar(int codigo, char nome[], char telefone[], char email[]);
 
int contato_getCodigo(Contato *c);
char* contato_getNome(Contato *c);
char* contato_getTelefone(Contato *c);
char* contato_getEmail(Contato *c);
 
void contato_setCodigo(Contato *c, int codigo);
void contato_setNome(Contato *c, char nome[]);
void contato_setTelefone(Contato *c, char telefone[]);
void contato_setEmail(Contato *c, char email[]);
 
void contato_destruir(Contato *c);
 
#endif // CONTATO_H_INCLUDED
