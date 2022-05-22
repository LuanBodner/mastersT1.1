contigua:
	gcc -c pilha_contigua.c -o pilha_contigua.o
	gcc main_contigua.c pilha_contigua.o -o main_contigua

encadeada:
	gcc -c pilha_encadeada.c -o pilha_encadeada.o
	gcc main_encadeada.c pilha_encadeada.o -o main_encadeada

clean:
	rm -f main_encadeada
	rm -f main_contigua
	rm -f *.o