#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: ./a.out mean std_dev num_samples\n");
    return 1;
  }

  double mean = atof(argv[1]);
  double std_dev = atof(argv[2]);
  int num_samples = atoi(argv[3]);

  // Generate samples from a 1D Gaussian distribution
  double samples[num_samples];
  double x_min = mean - 3 * std_dev;
  double x_max = mean + 3 * std_dev;
  double delta_x = (x_max - x_min) / (num_samples - 1);
  for (int i = 0; i < num_samples; i++) {
    double x = x_min + i * delta_x;
    samples[i] = exp(-(x - mean) * (x - mean) / (2 * std_dev * std_dev));
  }

  // Write samples to a data file
  FILE *data_file = fopen("function_data", "w");
  for (int i = 0; i < num_samples; i++) {
    double x = x_min + i * delta_x;
    fprintf(data_file, "%lf %lf\n", x, samples[i]);
  }
  fclose(data_file);

  // Plot samples using gnuplot
  char gnuplot_cmd[1024];
  sprintf(gnuplot_cmd, "gnuplot --persist -e 'plot \"function_data\"'");
  system(gnuplot_cmd);

  return 0;
}

/*
Compile:
gcc -o a.out main_Uyen_E3.1.c -lm
./a.out 3 0.6 20
*/