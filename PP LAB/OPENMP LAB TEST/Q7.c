// Write a program calculate the sum of first 100 Numbers. (Using critical directive)
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main() {
  int n = 100;
  int sum = 0; // global so should use critical while updating
#pragma omp parallel for
  for (int i = 1;i <= n;i++) {
#pragma omp critical
    sum += i;
  }
  printf("sum is %d\n", sum);
}

// Theory:- 
// The critical construct restricts execution of the associated structured block to a single thread at a time.
// The syntax of the critical construct is as follows :
//   #pragma omp critical [(name) [[,] hint(hint-expression)]] new-line 
//   structured - block

// Use OpenMP critical sections to prevent multiple threads from accessing the critical section's code at the same time, 
// thus only one active thread can update the data referenced by the code. Critical sections are useful for a non-nested mutex.

// For more reference:- https://learn.microsoft.com/en-us/cpp/parallel/openmp/reference/openmp-directives?view=msvc-170#critical