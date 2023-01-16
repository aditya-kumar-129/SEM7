#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {
  int iteration; scanf("%d", &iteration);
  int threadValue[8];

#pragma omp parallel for schedule(static,2)
  for (int i = 0; i < iteration; i++) {
    int t = omp_get_thread_num();
    threadValue[t] += 1;
    printf("Thread Number : %d  Iterations = %d\n", t, i);
  }
}