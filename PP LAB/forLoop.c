#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {

  omp_set_num_threads(20);
#pragma omp parallel for
  {
    for (int i = 0; i < 250;i++) {
      printf("%d from thread %d\n", i, omp_get_thread_num());
    }
  }
  return 0;
}