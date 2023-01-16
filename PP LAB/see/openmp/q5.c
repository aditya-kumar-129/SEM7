#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int isPrime(int n) {
  for (int i = 2;i <= n / 2;i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

void parallelExecution(int n) {
  int x = 2;
#pragma omp parallel
  while (x <= n) {
    if (isPrime(x)) {
      printf("%d ", x);
    }
#pragma omp atomic
    x++;
  }
}

void serialExecution(int n) {
  int x = 2;
  while (x <= n) {
    if (isPrime(x)) {
      printf("%d ", x);
    }
    x++;
  }
}

int main() {
  int n; scanf("%d", &n);
  double start = omp_get_wtime();
  parallelExecution(n);
  double end = omp_get_wtime();
  printf("\nTime needed for paralled Execution is %f\n", end - start);

  start = omp_get_wtime();
  serialExecution(n);
  end = omp_get_wtime();
  printf("\nTime needed for serial Execution is %f\n", end - start);
}