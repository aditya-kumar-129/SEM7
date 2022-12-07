#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

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

void mergeSort(int arr[], int low, int high) {
  int mid = 0;
  if (low < high) {
    mid = (low + high) / 2;

    // The parallel sections construct is a shortcut for specifying a parallel construct containing a sections construct and no other statements. 
    // This basically starts a parallel code with section clause (Please note sections)
    // http://jakascorner.com/blog/2016/05/omp-sections.html
#pragma omp parallel sections
    {
      //This one will run under a section and same for the next one. (section 1)
#pragma omp section
      {
        // printf("\nThread handling left recursion is %d",omp_get_thread_num());
        mergeSort(arr, low, mid);
      }

#pragma omp section //(section 2)
      {
        // printf("\nThread handling right recursion is %d",omp_get_thread_num());
        mergeSort(arr, mid + 1, high);
      }
    }
    merge(arr, low, mid, high);
  }
}

int main() {
  omp_set_num_threads(4);
  int n;
  printf("Enter the number of elements:\t");
  scanf("%d", &n);
  int arr[n];
  for (int i = 0;i < n;i++) arr[i] = rand() % 100;

  // printf("The unsorted array is:\n");
  // for (int i = 0;i < n;i++) printf("%d ",arr[i]);

  // The omp_get_wtime routine returns elapsed wall clock time in seconds. 
  double t1 = omp_get_wtime(); //gets the time
  mergeSort(arr, 0, n - 1);
  double t2 = omp_get_wtime(); //gets the time after func call.

  printf("\nThe time taken is: %f", t2 - t1);

  // printf("\nThe sorted array is:\n");
  // for (int i = 0;i < n;i++) printf("%d ",arr[i]);
  return 0;
}