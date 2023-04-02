#include <stdio.h>
#include <stdlib.h>

void binary_to_text(char *binary_file, char *text_file) {
  FILE *binary = fopen(binary_file, "rb");
  FILE *text = fopen(text_file, "w");

  float x, y;
  while (fread(&x, sizeof(float), 1, binary) == 1 && fread(&y, sizeof(float), 1, binary) == 1) {
    fprintf(text, "%f %f\n", x, y);
  }

  fclose(binary);
  fclose(text);
}
