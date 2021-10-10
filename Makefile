all: caminho.o conexao.o pilha.o Main
	gcc -g main.o caminho.o conexao.o pilha.o -o pvc -std=c99 -pedantic-errors -Wall -lm

run: 
	./pvc < ./Tests/Teste1.in > ./T

pilha.o:
	gcc -g -c ./TAD_Pilha/Pilha.c -o pilha.o -I ./TAD_Caminho

conexao.o:
	gcc -g -c ./TAD_Conexao/Conexao.c -o conexao.o

caminho.o:
	gcc -g -c ./TAD_Caminho/Caminho.c -o caminho.o

Main:
	gcc -g -c main.c -I ./TAD_Conexao -I ./TAD_Pilha -I ./TAD_Caminho

clean:
	rm *.o pvc