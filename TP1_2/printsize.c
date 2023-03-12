#include <stdio.h>
int main() {
	char charType;
	int intType;
	short shortType;
	unsigned short unsigned_short;
	long longType;
	float floatType;
	double doubleType;

	printf("Size of char is = %zu\n", sizeof(charType));
	printf("Size of int is = %zu\n", sizeof(intType));
	printf("Size of short is = %zu\n", sizeof(shortType));
	printf("Size of unsigned short is = %zu\n", sizeof(unsigned_short));
	printf("Size of long is = %zu\n", sizeof(longType));
	printf("Size of float is = %zu\n", sizeof(floatType));
	printf("Size of double is = %zu\n", sizeof(doubleType));
	return 0;
}
	