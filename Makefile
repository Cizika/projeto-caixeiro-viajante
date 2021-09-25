all: conexao.o lista.o Main
	gcc main.o conexao.o lista.o -o pvc -std=c99 -pedantic-errors -Wall -lm

lista.o:
	gcc -c ./TAD_Lista/lista.c -o lista.o

conexao.o:
	gcc -c ./TAD_Conexao/conexao.c -o conexao.o 

Main:
	gcc -c main.c -I ./TAD_Conexao -I ./TAD_Lista

clean:
	rm *.o conexao