#include <stdio.h>
#include<omp.h>
#include<stdlib.h>

int fib(int n) {
  int a = 0, b = 1, temp;
#pragma omp parallel for schedule(static,2)
  for (int i = 0;i < n;i++) {
#pragma omp critical
    {
      temp = a + b;
      a = b;
      b = temp;
    }
  }
  return a;
}
int main() {
  int n = 20;
  double start = omp_get_wtime();
  #pragma omp parallel for 
  for (int i = 0;i < n;i++) {
    int t = omp_get_thread_num();
    printf("Thread num : %d , fib(%d) = %d\n", t, i, fib(i));
  }
  double end = omp_get_wtime();
  printf("time taken is : %f", end - start);
}