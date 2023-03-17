#include <stdio.h>
int main() {
	char charType; // Store a single character
	int intType; //Store a whole number (integer) with a range of at least -32,767 to 32,767
	short shortType; //Store a whole number (integer) with a smaller range than int
	unsigned short unsigned_short; //Store a whole number with a range of 0 to 65,535
	long longType; //Store a whole number with a larger range than int
	float floatType; //Store a floating-point number (a number with decimal places) with a range of at least 1.2E-38 to 3.4E+38.
	double doubleType;  //Store a floating-point number with a larger range than float

	printf("Size of char is = %zu\n", sizeof(charType)); //%zu is used to print an unsigned integer of size sizeof(size_t)
	printf("Size of int is = %zu\n", sizeof(intType));
	printf("Size of short is = %zu\n", sizeof(shortType));
	printf("Size of unsigned short is = %zu\n", sizeof(unsigned_short));
	printf("Size of long is = %zu\n", sizeof(longType));
	printf("Size of float is = %zu\n", sizeof(floatType));
	printf("Size of double is = %zu\n", sizeof(doubleType));
	return 0;
}
	