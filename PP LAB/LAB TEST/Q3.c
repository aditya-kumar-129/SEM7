#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

//iterns
void main() {
  int iterns, i, itern = 1;
  printf("enter iterns:");
  scanf("%d", &iterns);
#pragma omp parallel for schedule(static,2)
  for (i = 1; i <= iterns; i++) {
    int t = omp_get_thread_num();
    itern += 1;
    itern %= 2;
    printf("thread %d itern %d value: %d\n", t, itern, i);
  }
}