all: arvoreAVL.out


arvoreAVL.out:main.o arvoreAVL.o

	gcc arvoreAVL.o main.o -o arvoreAVL.out
  


arvoreAVL.o:arvoreAVL.c

	gcc -c arvoreAVL.c -o arvoreAVL.o



main.o:main.c

	gcc -c main.c -o main.o



clean:

	rm -f *.out *.o *.*~ *~