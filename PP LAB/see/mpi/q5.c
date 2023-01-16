#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int isPrime(int x) {
  if (x == 0 || x == 1) return 0;
  if (x == 2 || x == 3) return 1;
  for (int i = 2;i <= x / 2;i++)
    if (x % i == 0) return 0;
  return 1;
}

void main(int argc, char* argv[]) {
  int rank, size;
  int n; scanf("%d", &n);
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int* globalData = malloc(sizeof(int) * n);

  int root = 0;
  MPI_Bcast(&n, 1, MPI_INT, root, MPI_COMM_WORLD);
  for (int i = 0;i < n;i++) globalData[i] = i + 1;

  int len = (n / size) + 1;
  for (int i = (rank * len); i < ((rank + 1) * len); i++) {  // important (different from q4) i= rank*len is used instead of (rank*len)+1
    if (i > n) break;
    if (isPrime(globalData[i])) printf("d", globalData[i]);
  }
  MPI_Finalize();
}