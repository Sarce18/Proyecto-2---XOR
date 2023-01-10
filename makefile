CFLAGS = -I

all: XOR.o main.o 
	gcc -g XOR.o main.o -o project
	./project

XOR.o: XOR.c
	gcc -c XOR.c -o XOR.o

main.o: main.c
	gcc -c main.c -o main.o

XOR: 
	gcc -o XOR project.o XOR.o 
	
