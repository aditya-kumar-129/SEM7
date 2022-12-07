#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

double* vectAdd(double* c, double* a, double* b, int n) {
#pragma omp parallel for
  for (int i = 0; i < n; i++)
    c[i] = a[i] + b[i];
  return c;
}

void main() {
  int n = 100000;
  int vector_a[100000], vector_b[100000], res_vector[100000];
  for (int i = 0;i < n;i++) {
    vector_a[i] = rand() % 10;
    vector_b[i] = rand() % 10;
  }
  double start = omp_get_wtime();
  vectAdd(res_vector, vector_a, vector_b, n);
  double end = omp_get_wtime();
  printf("The elements of the vector Addition are:- ");
  for(int i = 0; i < n; i++)
    printf("%d", res_vector[i]);
  printf("Parallel Time %f\n", end - start);
}