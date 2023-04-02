# Declare the compilation
CC=gcc

# Declare the output
all: main2.1.out main2.2.out main2.3.out main2.4.out

# Create an object file TP2.1
exchange.o: exchange.c
	$(CC) -c exchange.c

# Compile the exercise TP2.1
main2.1.out: main_Uyen_E2.1.c exchange.o
	$(CC) -o main2.1.out main_Uyen_E2.1.c exchange.o

# Compile the exercise TP2.2
main2.2.out: main_Uyen_E2.2.c exchange.o
	$(CC) -o main2.2.out main_Uyen_E2.2.c exchange.o

# Compile the exercise TP2.3
main2.3.out: main_Uyen_E2.3.c exchange.o
	$(CC) -o main2.3.out main_Uyen_E2.3.c exchange.o

# Compile the exercise TP2.4
main2.4.out: main_Uyen_E2.4.c exchange.o
	$(CC) -o main2.4.out main_Uyen_E2.4.c exchange.o

#Clean all executed files
clean:
	rm -f *.o *.out *.hellos