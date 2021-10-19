all: conexao.o caminho.o pilha.o lista.o Main
	gcc -g main.o caminho.o conexao.o pilha.o lista.o -o PVC -std=c99 -pedantic-errors -Wall -lm

run: 
	./PVC

test: 
	valgrind --leak-check=full ./PVC < ./Tests/1.in > ./Tests/1.out

pilha.o:
	gcc -g -c ./TAD_Pilha/Pilha.c -o pilha.o -I ./TAD_Caminho

caminho.o:
	gcc -g -c ./TAD_Caminho/Caminho.c -o caminho.o

conexao.o:
	gcc -g -c ./TAD_Conexao/Conexao.c -o conexao.o

lista.o:
	gcc -g -c ./TAD_Lista/Lista.c -o lista.o -I ./TAD_Lista

Main:
	gcc -g -c main.c -I ./TAD_Conexao -I ./TAD_Pilha -I ./TAD_Caminho

clean:
	rm *.o PVC