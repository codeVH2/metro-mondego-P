all: mm

mm: main.c linha.c paragem.c ficheiros.c
	gcc -o mm main.c linha.c paragem.c ficheiros.c -I.

clean:
	rm -r mm teste.bin