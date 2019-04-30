#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
 
typedef struct hash Hash;
 
Hash* hash_criar();
void hash_destruir(Hash* h);
void* hash_buscar(Hash* h, int codigo);
void hash_inserir(Hash* h, int codigo, void *item);
 
#endif // HASH_H_INCLUDED
