#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main() {
  int sum = 0;
  int n = 100;
#pragma omp parallel for
  for (int i = 0; i <= n; i++) {
#pragma omp critical
    sum += i;
  }
  printf("%d", sum);
}