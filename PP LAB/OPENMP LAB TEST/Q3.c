#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main() {
  int iteration, itern[8];
  printf("enter iteration:");
  scanf("%d", &iteration);
  //ref: http://jakascorner.com/blog/2016/06/omp-for-scheduling.html
  //ref : https://ppc.cs.aalto.fi/ch3/schedule/

#pragma omp parallel for schedule(static,2)
  for (int i = 1; i <= iteration; i++) {
    int t = omp_get_thread_num();
    itern[t] += 1;
    printf("thread %d value: %d\n", t, i);
  }
}