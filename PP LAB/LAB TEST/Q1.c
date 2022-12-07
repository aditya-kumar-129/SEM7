#include <stdio.h>
#include <stdlib.h>
#include<omp.h>

void merge(int arr[], int l, int m, int h) {
  int n1 = m - l + 1, n2 = h - m;
  int L[n1], M[n2];

  for (int i = 0; i < n1; i++) L[i] = arr[l + i];
  for (int i = 0; i < n2; i++) M[i] = arr[m + 1 + i];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) arr[k++] = L[i++];
    else arr[k++] = M[j++];
  }
  while (i < n1) arr[k++] = L[i++];
  while (j < n2) arr[k++] = M[j++];
}

void mergesortParallel(int a[], int l, int h) {
  if (l < h) {
    int mid = l + (h - l) / 2;
#pragma omp parallel sections
    {
#pragma omp section
      mergesortParallel(a, l, mid);
#pragma omp section
      mergesortParallel(a, mid + 1, h);
    }
    merge(a, l, mid, h);
  }
}

void mergesortSerial(int a[], int l, int h) {
  if (l < h) {
    int mid = l + (h - l) / 2;
#pragma omp parallel sections
    {
#pragma omp section
      mergesortSerial(a, l, mid);
#pragma omp section
      mergesortSerial(a, mid + 1, h);
    }
    merge(a, l, mid, h);
  }
}

void main() {
  int num, i;
  printf("enter number:");
  scanf("%d", &num);
  int a[num];
  printf("array before sorting");
  for (i = 0;i < num;i++) {
    a[i] = rand() % 100;
    printf("%d ", a[i]);
  }

  double start = omp_get_wtime();
  mergesortSerial(a, 0, num - 1);
  double end = omp_get_wtime();
  printf("\narray after sorting\n");
  for (i = 0;i < num;i++) printf("%d ", a[i]);
  double val = end - start;
  printf("\nTime for serial is:%f\n", val);

  start = omp_get_wtime();
  mergesortParallel(a, 0, num - 1);
  end = omp_get_wtime();
  val = end - start;
  printf("Time for parallel execution is %f\n", val);
}