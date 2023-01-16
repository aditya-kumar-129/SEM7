#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main() {
  int n = 99000;
  int vector_a[n], vector_b[n], res_vector[n];
  for (int i = 0;i < n;i++) {
    vector_a[i] = rand() % 10;
    vector_b[i] = rand() % 10;
  }

  double start = omp_get_wtime();
#pragma omp parallel for
  for (int i = 0; i < n; i++)
    res_vector[i] = vector_a[i] + vector_b[i];
  double end = omp_get_wtime();
  printf("Parallel Time %f\n", end - start);
}