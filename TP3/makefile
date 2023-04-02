# Declare the compilation
CC = gcc
# Specify the compiler flags for all targets
CFLAGS = -lm
# Specify the header file dependencies for binary_to_text.o and packing_NGUYEN.o
DEPS_BINARY_TO_TEXT = binary_to_text.h
DEPS_PACKING_NGUYEN = packing_NGUYEN.h

# Declare the output
all: main_Uyen_E3.1.out main_Uyen_E3.2.out main_Uyen_E3.3.out

# Compile the exercise TP3.1
main_Uyen_E3.1.out: main_Uyen_E3.1.c
	$(CC) $(CFLAGS) -o $@ $<

# Create an object file TP3.2
binary_to_text.o: binary_to_text.c $(DEPS_BINARY_TO_TEXT)
	$(CC) $(CFLAGS) -c -o $@ $<

# Compile the exercise TP3.2
main_Uyen_E3.2.out: main_Uyen_E3.2.c binary_to_text.o
	$(CC) $(CFLAGS) -o $@ $< binary_to_text.o

# Create an object file tp3.3
packing_NGUYEN.o: packing_NGUYEN.c $(DEPS_PACKING_NGUYEN)
	$(CC) $(CFLAGS) -c -o $@ $<

# Compile the exercise TP3.3
main_Uyen_E3.3.out: main_Uyen_E3.3.c packing_NGUYEN.o
	$(CC) $(CFLAGS) -o $@ $< packing_NGUYEN.o


#Clean all executed files
clean:
	rm -f *.o *.out

