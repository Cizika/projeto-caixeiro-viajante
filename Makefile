all: conexao.o pilha.o Main
	gcc main.o conexao.o pilha.o -o pvc -std=c99 -pedantic-errors -Wall -lm

pilha.o:
	gcc -c ./TAD_Pilha/pilha.c -o pilha.o

conexao.o:
	gcc -c ./TAD_Conexao/conexao.c -o conexao.o 

Main:
	gcc -c main.c -I ./TAD_Conexao -I ./TAD_Pilha

clean:
	rm *.o conexao