CC=gcc

all: main2.1.out main2.2.out main2.3.out main2.4.out

exchange.o: exchange.c
	$(CC) -c exchange.c

main2.1.out: main_Uyen_E2.1.c exchange.o
	$(CC) -o main2.1.out main_Uyen_E2.1.c exchange.o

main2.2.out: main_Uyen_E2.2.c exchange.o
	$(CC) -o main2.2.out main_Uyen_E2.2.c exchange.o

main2.3.out: main_Uyen_E2.3.c exchange.o
	$(CC) -o main2.3.out main_Uyen_E2.3.c exchange.o

main2.4.out: main_Uyen_E2.4.c exchange.o
	$(CC) -o main2.4.out main_Uyen_E2.4.c exchange.o