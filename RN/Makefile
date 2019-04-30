all: arvoreRN.out


arvoreRN.out:main.o arvoreRN.o

	gcc arvoreRN.o main.o -o arvoreRN.out
  


arvoreRN.o:arvoreRN.c

	gcc -c arvoreRN.c -o arvoreRN.o



main.o:main.c

	gcc -c main.c -o main.o



clean:

	rm -f *.out *.o *.*~ *~
