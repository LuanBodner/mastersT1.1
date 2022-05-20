contigua:
	gcc -c pilha_encadeada.c -o pilha_encadeada.o
	gcc main.c pilha_encadeada.o -o main_pilhaEncadeada

encadeada:
	gcc -c pilha_encadeada.c -o pilha_encadeada.o
	gcc main.c pilha_encadeada.o -o main_pilhaEncadeada

clean:
	rm *.o
	rm main_pilhaEncadeada
	rm main_pilhaEncadeada