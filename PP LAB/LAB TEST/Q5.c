#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

// FUnction to check if the given number is prime number or not.
int isprime(int n) {
  for (int i = 2;i <= n / 2;i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

void main() {
  int i = 0, n = 1000, x = 2, primes[1100];

  // Using Parallel Execution
  double start = omp_get_wtime();
#pragma omp parallel
  while (i < n) {
    if (isprime(x)) {
      primes[i] = x;
#pragma omp atomic 
      i++;
    }
#pragma omp atomic
    x++;
  }
  double end = omp_get_wtime();
  printf("Parallel Execution time: %f\n", end - start);

  // Using Serial Execution
  i = 0;x = 2;
  start = omp_get_wtime();
  while (i < n) {
    if (isprime(x)) {
      primes[i] = x;
      i++;
    }
    x++;
  }
  end = omp_get_wtime();
  printf("Serial Execution time: %f\n", end - start);
}

// Theory:-

// The atomic construct ensures that a specific storage location is accessed atomically, rather than exposing it to the possibility of multiple, 
// simultaneous reading and writing threads that may result in indeterminate values.
// For more information:- https://www.openmp.org/spec-html/5.0/openmpsu95.html