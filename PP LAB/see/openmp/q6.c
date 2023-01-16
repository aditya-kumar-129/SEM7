#include <stdio.h>
#include<omp.h>
#include<stdlib.h>

#define num_Steps 100000

int main() {
  int n;
  scanf("%d", &n);
  float v1[n], v2[n];
  for (int i = 0;i < n;i++) {
    v1[i] = rand() % 100;
    v2[i] = rand() % 100;
  }

  float ans[n];
  double start = omp_get_wtime();
#pragma omp parallel for
  for (int i = 0;i < n;i++) {
    ans[i] = v1[i] + v2[i];
  }
  double end = omp_get_wtime();
  printf("The time needed is : %f", end - start);
}