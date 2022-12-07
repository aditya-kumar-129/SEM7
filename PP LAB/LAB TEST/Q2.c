#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define num_steps 1000000 // infinity assumption

int main(int argc, char* argv[]) {
  double pi = 0;

  // Serial Execution
  double start = omp_get_wtime();
  for (int k = 0; k < num_steps; k++) pi += pow(-1, k) / (2 * k + 1);
  pi = 4 * pi;
  double end = omp_get_wtime();
  double time = end - start;
  printf("Value of pi in serial : %lf with time : %lf\n", pi, time);
  
  // Parallel Execution
  pi = 0;
  start = omp_get_wtime();
  double thread[4];
#pragma omp parallel for num_threads(4)
  for (int k = 0; k < num_steps; k++) {
    int t = omp_get_thread_num();
    thread[t] += pow(-1, k) / (2 * k + 1);
  }
  for (int i = 0; i < 4; i++) pi += thread[i];
  pi = 4 * pi;
  end = omp_get_wtime();
  time = end - start;
  printf("value of pi in parallel : %lf with time : %lf\n", pi, time);
  return 0;
}