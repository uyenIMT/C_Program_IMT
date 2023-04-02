#include <stdio.h>
#include <stdlib.h>

// Read a binary file containing pairs of floating-point values, and write them to a text file in a human-readable format
void binary_to_text(char *binary_file, char *text_file) {
  FILE *binary = fopen(binary_file, "rb"); // Open the binary file specified by the string in the mode of binary read
  FILE *text = fopen(text_file, "w"); // Open text file specified by the string in the mode of write

  // The code then enters a loop that reads two floating-point values from the binary file at a time
  float x, y;
  // Fread() reads data from binary file pointer, store it in &x and &y.
  // Size(float) indicates each value to be read is a 4-byte floating-point number
  // 1 indicates that it reads one value at a time.
  while (fread(&x, sizeof(float), 1, binary) == 1 && fread(&y, sizeof(float), 1, binary) == 1) {
    // For each pair of values, fprintf() writes a formatted string to the specified output stream separated by a space
    fprintf(text, "%f %f\n", x, y);
  }
  // CLose both binary and text file
  fclose(binary);
  fclose(text);
}
