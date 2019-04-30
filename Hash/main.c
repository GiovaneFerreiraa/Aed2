#include "hash.h"
#include "contato.h"
#include <stdio.h>
#include <stdlib.h>


//Usado para alocar os elemtos na hash

int main()
{

	Hash* h = hash_criar();
	hash_inserir(h, 2, contato_criar(2, "Julio ", "323123123", "julio.cesar@gmail.com"));
	hash_inserir(h, 6, contato_criar(6, " Wagner", "903123120", "wagnerad@gmail.com"));
	hash_inserir(h, 13, contato_criar(13, "Mariana", "83813", "mariana@gmail.com"));
	hash_inserir(h, 12, contato_criar(12, "Marcela", "87872222", "marcela@gmail.com"));
	hash_inserir(h, 7, contato_criar(7, "Marta", "77887777", "marta@gmail.com"));
	hash_inserir(h, 7, contato_criar(7, "Lucas", "77812313", "lucassouza@gmail.com"));
	hash_inserir(h, 15, contato_criar(15, "Mario", "73217737", "mario@gmail.com"));
	int i;
	for (i = 0; i < 20; i++)
	{
		Contato *c = (Contato*)hash_buscar(h, i);
		if (c != NULL)
		{
			printf("%d - %d: %s - %s\n", i % 4, i, contato_getNome(c), contato_getEmail(c));
		}
	}
	hash_destruir(h);
	return 0;
}
