all: conexao.o caminho.o lista_conexoes.o lista_caminhos.o Main
	gcc -g main.o caminho.o conexao.o lista_caminhos.o lista_conexoes.o -o PCV -std=c99 -pedantic-errors -Wall -lm

run: 
	./PCV

test: 
	valgrind --leak-check=full --show-leak-kinds=all ./PCV < ./Tests/Teste10.in > ./Tests/Teste10.out

caminho.o:
	gcc -g -c ./TAD_Caminho/Caminho.c -o caminho.o

conexao.o:
	gcc -g -c ./TAD_Conexao/Conexao.c -o conexao.o

lista_conexoes.o:
	gcc -g -c ./TAD_Lista/Lista_Conexao.c -o lista_conexoes.o -I ./TAD_Conexao

lista_caminhos.o:
	gcc -g -c ./TAD_Lista/Lista_Caminho.c -o lista_caminhos.o -I ./TAD_Caminho

Main:
	gcc -g -c main.c -I ./TAD_Conexao -I ./TAD_Caminho

clean:
	rm *.o PCV