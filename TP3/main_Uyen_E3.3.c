#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packing_NGUYEN.h"
#define MAX_FNAME_LENGTH 256

int main() {
  // Prompt the user to enter the name of the packed file
  char packed_file[MAX_FNAME_LENGTH];
  printf("Enter the name of the packed file: ");
  scanf("%s", packed_file);
  // Prompt the user to enter the number of files to pack
  int num_files;
  printf("Enter the number of files to pack: ");
  scanf("%d", &num_files);
  // Prompt the user to enter the name of each file to be packed
  // Store the names in an array of strings called files
  char *files[num_files];
  for (int i = 0; i < num_files; i++) {
      char file_name[MAX_FNAME_LENGTH];
      printf("Enter the name of file %d: ", i + 1);
      scanf("%s", file_name);
      files[i] = strdup(file_name);
  }
  // Pass in the packed file name, the number of files, and the array of file names.
  file_packing(packed_file, num_files, files);
  // Pass in the packed file name
  file_unpacking(packed_file);
  for (int i = 0; i < num_files; i++) {
      free(files[i]); //Free the memory allocated for the file names.
  }
  return 0;
}
/*
Compile:
$ gcc -c packing_NGUYEN.c
$ gcc -o main_Uyen_E3.3.out main_Uyen_E3.3.c packing_NGUYEN.o -lm
$ ./main_Uyen_E3.3.out
*/ 