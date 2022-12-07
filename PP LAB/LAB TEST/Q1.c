#include <stdio.h>
#include <stdlib.h>
#include<omp.h>

void merge(int arr[], int low, int mid, int high) {
  int n1 = mid - low + 1, n2 = high - mid;
  int L[n1], M[n2];

  for (int i = 0; i < n1; i++) L[i] = arr[low + i];
  for (int i = 0; i < n2; i++) M[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = low;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) arr[k++] = L[i++];
    else arr[k++] = M[j++];
  }
  while (i < n1) arr[k++] = L[i++];
  while (j < n2) arr[k++] = M[j++];
}

void mergesortParallel(int a[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
#pragma omp parallel sections
    {
#pragma omp section
      mergesortParallel(a, low, mid);
#pragma omp section
      mergesortParallel(a, mid + 1, high);
    }
    merge(a, low, mid, high);
  }
}

void mergesortSerial(int a[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    mergesortSerial(a, low, mid);
    mergesortSerial(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}

void main() {
  int num, i;
  printf("enter number: ");
  scanf("%d", &num);
  int a[num];
  for (i = 0;i < num;i++) a[i] = rand() % 100;

  double start = omp_get_wtime();
  mergesortSerial(a, 0, num - 1);
  double end = omp_get_wtime();
  double val = end - start;
  printf("\nTime for Serial Execution is:%f\n", val);

  start = omp_get_wtime();
  mergesortParallel(a, 0, num - 1);
  end = omp_get_wtime();
  val = end - start;
  printf("Time for Parallel Execution is %f\n", val);
}