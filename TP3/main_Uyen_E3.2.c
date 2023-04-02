#include <stdio.h>
#include <stdlib.h>
#include "binary_to_text.h"

int main() {
  binary_to_text("function_data_bin", "function_data_text");

  system("gnuplot --persist -e 'plot \"function_data_text\"'");

  return 0;
}

/*
Compile:
$ gcc -c binary_to_text.c
$ gcc -o main_Uyen_E3.2.out main_Uyen_E3.2.c binary_to_text.o -lm
$ ./main_Uyen_E3.2.out
*/