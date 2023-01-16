#include <stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<math.h>

#define num_steps 100000

int main() {
  // Serial Execution
  double pi = 0;
  double start = omp_get_wtime();
  for (int i = 0;i < num_steps;i++) pi += pow(-1, i) / ((2 * i) + 1);
  pi *= 4;
  double end = omp_get_wtime();
  printf("The time in serial Execution is %f", end - start);
  printf("\n The value of pi is %f", pi);

  // Parallel Execution
  pi = 0;
  double thread[4];
  start = omp_get_wtime();
#pragma omp parallel for num_threads(4)
  for (int i = 0;i < num_steps;i++) {
    int t = omp_get_thread_num();
    thread[t] += pow(-1, i) / ((2 * i) + 1);
  }

  for (int i = 0;i < 4;i++) pi += thread[i];
  pi *= 4;
  end = omp_get_wtime();
  printf("\nThe time in parallel Execution is %f", end - start);
  printf("\n The value of pi is %f", pi);
}