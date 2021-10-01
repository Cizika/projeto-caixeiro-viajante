all: conexao.o lista.o Main
	gcc main.o conexao.o lista.o -o pvc -std=c99 -pedantic-errors -Wall -lm

run: 
	valgrind ./pvc

lista.o:
	gcc -c ./TAD_Lista/Lista.c -o lista.o -I ./TAD_Conexao

conexao.o:
	gcc -c ./TAD_Conexao/Conexao.c -o conexao.o 

Main:
	gcc -c main.c -I ./TAD_Conexao -I ./TAD_Lista

clean:
	rm *.o pvc