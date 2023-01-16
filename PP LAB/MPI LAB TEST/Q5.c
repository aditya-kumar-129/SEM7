#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int isprime(int x) {
  if (x == 0 || x == 1) return 0;
  if (x == 2 || x == 3) return 1;
  for (int i = 2;i <= x / 2;i++)
    if (x % i == 0)
      return 0;
  return 1;
}

void main(int argc, char* argv[]) {
  int size, rank, root = 0, n;
  printf("enter n: \n");
  scanf("%d", &n);
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  MPI_Bcast(&n, 1, MPI_INT, root, MPI_COMM_WORLD);
  int* globaldata = malloc(n * sizeof(int));
  for (int i = 0;i < n;i++) globaldata[i] = i + 1;
  int len = (n / size) + 1;
  for (int i = (rank * len);i < ((rank + 1) * len);i++) {
    if (i > n) break;
    if (isprime(globaldata[i])) printf("%d ", globaldata[i]);
  }
  MPI_Finalize();
}