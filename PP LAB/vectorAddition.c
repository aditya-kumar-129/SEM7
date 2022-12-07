#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

double* vectAdd(double* c, double* a, double* b, int n) {
#pragma omp parallel for
  for (int i = 0; i < n; i++) c[i] = a[i] + b[i];
  return c;
}

int main() {
  int n = 10;
  double a[20], b[20], c[20];

  for (int i = 0; i < n; i++) {
    a[i] = rand() % n;
    b[i] = rand() % n;
  }

  for (int i = 0; i < n; i++)  printf("%f\n", vectAdd(c, a, b, n)[i]);
  return 0;
}