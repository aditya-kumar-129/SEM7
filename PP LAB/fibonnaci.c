#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int fib(int n) {
  return n < 2 ? 1 : fib(n - 1) + fib(n - 2);
}

int main(int argc, char* argv[]) {
  // Argv Output
  printf("%s \n", argv[1]);
  // Setting the number of threads
  omp_set_num_threads(12);
  int n = 34;
#pragma omp parallel
  {
    // Finding thread number
    int t = omp_get_thread_num();
    // Finding total threads running
    if (t == 0) printf("Number of threads are: %d\n", omp_get_max_threads());
    // Fibo output
    printf("%d : %d \n", t, fib(n + t));
  }
  return 0;
}

// gcc a.c -fopenmp
// time ./a.out sample

// https://akarthik10.wordpress.com/2012/11/01/openmp-generating-fibonacci-series/