#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
  // Provide 3 arguments: the mean, standard deviation, and number of samples for a normal distribution.
  if (argc < 4) {
    printf("Usage: ./a.out mean std_dev num_samples\n");
    return 1;
  }
  // The mean. atof() converts a string argument to a double precision floating-point value
  double mean = atof(argv[1]);
  // The standard deviation
  double std_dev = atof(argv[2]);
  // The number of samples. atoi() converts a string argument to an integer value.
  int num_samples = atoi(argv[3]);

  // Generate samples from a 1D Gaussian distribution
  double samples[num_samples]; // Declare the array
  double x_min = mean - 3 * std_dev; // Calculate minimum value for the range of values
  double x_max = mean + 3 * std_dev; // Calculate maximum value for the range of values
  double delta_x = (x_max - x_min) / (num_samples - 1); // Ensure the intervals cover the entire range of values

  for (int i = 0; i < num_samples; i++) {
    // Calculate the value of x corresponding to the ith sample
    double x = x_min + i * delta_x;
    // Calculate the value of the probability density function (PDF) of the normal distribution at x
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
$ gcc -o main_Uyen_E3.1.out main_Uyen_E3.1.c -lm
$ ./main_Uyen_E3.1.out 3 0.6 20
*/