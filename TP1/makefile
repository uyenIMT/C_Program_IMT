# Declare the compilation
CC=gcc

# Declare the output
all: myprog.hello main_Uyen_E1.2.out main_Uyen_E1.3.1.out main_Uyen_E1.3.2.out main2.4.1.out main2.4.2.out

# Compile the exercise TP1.1
myprog.hello: main_1_myfirstprogram.c
	$(CC) -o myprog.hello main_1_myfirstprogram.c

# Compile the exercise TP1.2
main_Uyen_E1.2.out: main_2_printsize.c
	$(CC) -o main_Uyen_E1.2.out main_2_printsize.c

# Compile the exercise TP1.3.1
main_Uyen_E1.3.1.out: main_3.1_logical_use.c
	$(CC) -o main_Uyen_E1.3.1.out main_3.1_logical_use.c

# Compile the exercise TP1.3.2
# Create an object file
logical.o: logical.c
	$(CC) -c logical.c

main_Uyen_E1.3.2.out: logical.o main_3.2.c
	$(CC) -o main_Uyen_E1.3.2.out main_3.2.c logical.o

# Compile the exercise TP1.4.1
main2.4.1.out: main_4.1_print_character.c
	$(CC) -o main_Uyen_E1.4.1.out main_4.1_print_character.c

# Compile the exercise TP1.4.2
main2.4.2.out: main_4.2_cur_ex.c
	$(CC) -o main_Uyen_E1.4.2.out main_4.2_cur_ex.c

#Clean all executed files
clean:
	rm -f *.o *.out *.hello