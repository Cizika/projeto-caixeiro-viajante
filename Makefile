all: conexao.o caminho.o pilha.o Main
	gcc -g main.o caminho.o conexao.o pilha.o -o PVC -std=c99 -pedantic-errors -Wall -lm

run: 
	./PVC

test: 
	valgrind --leak-check=full ./PVC < ./Tests/Teste1.in > ./Tests/Teste1.out

pilha.o:
	gcc -g -c ./TAD_Pilha/Pilha.c -o pilha.o -I ./TAD_Caminho

caminho.o:
	gcc -g -c ./TAD_Caminho/Caminho.c -o caminho.o

conexao.o:
	gcc -g -c ./TAD_Conexao/Conexao.c -o conexao.o

Main:
	gcc -g -c main.c -I ./TAD_Conexao -I ./TAD_Pilha -I ./TAD_Caminho

clean:
	rm *.o PVC