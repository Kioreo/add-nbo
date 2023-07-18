add-nbo: add-nbo.o
	gcc -o add-nbo add-nbo.o

aad-nbo : add-nbo.c
	gcc -c add-nbo.c
