#include <stdio.h>
#include<omp.h>
#include<stdlib.h>

// // Question 1 Merge Sort
// void merge(int arr[], int low, int mid, int high) {
//   int n1 = mid - low + 1, n2 = high - mid;
//   int arr1[n1], arr2[n2];

//   for (int i = 0;i < n1;i++)  arr1[i] = arr[low + i];
//   for (int i = 0;i < n2;i++)  arr2[i] = arr[mid + 1 + i];

//   int i = 0, j = 0, k = low;
//   while (i < n1 && j < n2) {
//     if (arr1[i] <= arr2[j]) arr[k++] = arr1[i++];
//     else arr[k++] = arr2[j++];
//   }
//   while (i < n1) arr[k++] = arr1[i++];
//   while (i < n2) arr[k++] = arr2[j++];
// }

// void mergeSortSerial(int arr[], int low, int high) {
//   if (low < high) {
//     int mid = (low + high) / 2;
//     mergeSortSerial(arr, low, mid);
//     mergeSortSerial(arr, mid + 1, high);
//     merge(arr, low, mid, high);
//   }
// }

// void mergeSortParallel(int arr[], int low, int high) {
//   if (low < high) {
//     int mid = (low + high) / 2;
// #pragma omp parallel sections
//     {
// #pragma omp section
//       mergeSortParallel(arr, low, mid);
// #pragma omp section
//       mergeSortParallel(arr, mid + 1, high);
//     }
//     merge(arr, low, mid, high);
//   }
// }

// int main() {
//   int n; scanf("%d", &n);
//   int arr[n];
//   for (int i = 0;i < n;i++)  arr[i] = rand() % 100;

//   // Parallel Execution
//   double start = omp_get_wtime();
//   mergeSortSerial(arr, 0, n - 1);
//   double end = omp_get_wtime();
//   printf("Time needed in Serial Executiion is %f ", end - start);

//   start = omp_get_wtime();
//   mergeSortParallel(arr, 0, n - 1);
//   end = omp_get_wtime();
//   printf("\nTime needed in Parallel Executiion is %f ", end - start);
// }