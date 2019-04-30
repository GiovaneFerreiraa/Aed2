all:hash.out


hash.out:main.o hash.o contato.o lista.o

	gcc hash.o main.o contato.o lista.o -o hash.out


lista.o:lista.c
	gcc -c lista.c -o lista.o  


contato.o:contato.c
	
	gcc -c contato.c -o contato.o

hash.o:hash.c

	gcc -c hash.c -o hash.o



main.o:main.c

	gcc -c main.c -o main.o



clean:

	rm -f *.out *.o *.*~ *~
