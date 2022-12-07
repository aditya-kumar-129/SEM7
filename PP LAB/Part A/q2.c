#include<stdio.h>
#include<omp.h>

int main() {
  int noOfRows, noOfCols, vectorSize, i, j;
  printf("Enter the number of rows and columns present in the matrix:\t");
  scanf("%d %d", &noOfRows, &noOfCols);
  printf("Enter the number of columns in the vector:\t");
  scanf("%d", &vectorSize);

  int matrix[noOfRows][noOfCols];
  int vector[vectorSize];

  if (noOfRows <= 0 || noOfCols <= 0 || vectorSize <= 0 || noOfCols != vectorSize) {
    printf("Invalid Input");
    return 0;
  }

  for (int i = 0;i < noOfRows;i++)
    for (int j = 0;j < noOfCols;j++)
      matrix[i][j] = i + j;

  for (int i = 0;i < vectorSize;i++) vector[i] = i;

  for (int i = 0;i < noOfRows;i++) {
    for (int j = 0;j < noOfCols;j++)
      printf("%d\t", matrix[i][j]);
    printf("\n");
  }

  int result[noOfRows];
  for (int i = 0;i < noOfRows;i++) result[i] = 0;

  // Main part of thhe program starts from here.
  double t1 = omp_get_wtime();
  omp_set_num_threads(4);
  // The private clause declares the variables in the list to be private to each thread in a team.
  // https://www.ibm.com/docs/en/zos/2.2.0?topic=programs-shared-private-variables-in-parallel-environment
#pragma omp parallel for private(j)
  for (int i = 0;i < noOfRows;i++) 
    for (int j = 0;j < noOfCols;j++) 
      result[i] += matrix[i][j] * vector[j];

  double t2 = omp_get_wtime();
  printf("The time required by the program is:\t%f\n", t2 - t1);

  //We got an NX1 vector which we have stored in an array.
  for (int i = 0;i < noOfRows;i++) printf("%d\t", result[i]);
}