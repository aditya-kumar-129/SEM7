#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

// OMP:- Open Multi-processing (OpenMP)

int main() {
  // Below line indicates a execution of block of code in Parallel
  #pragma omp parallel	
  {
    // Finding thread number
    int t = omp_get_thread_num();
    printf("Hello world from thread number %d \n", t);
  }
  return 0;
}
// https://stackoverflow.com/questions/1448318/omp-parallel-vs-omp-parallel-for