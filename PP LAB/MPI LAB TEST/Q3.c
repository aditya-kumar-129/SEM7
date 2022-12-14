#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

void main(int argc, char* argv[]) {
  int rank, size, root = 0, n = 10;
  int a[100], b[100], c[100];
  for (int i = 0;i < n;i++) {
    a[i] = rand() % 10;
    b[i] = rand() % 10;
  }

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int subsize = n / size;
  int* ap = malloc(sizeof(int) * subsize);
  int* bp = malloc(sizeof(int) * subsize);
  int* cp = malloc(sizeof(int) * subsize);

  MPI_Scatter(a, subsize, MPI_INT, ap, subsize, MPI_INT, root, MPI_COMM_WORLD);
  MPI_Scatter(b, subsize, MPI_INT, bp, subsize, MPI_INT, root, MPI_COMM_WORLD);

  for (int i = 0;i < subsize;i++) cp[i] = ap[i] + bp[i];

  MPI_Gather(cp, subsize, MPI_INT, c, subsize, MPI_INT, root, MPI_COMM_WORLD);
  if (rank == root) {
    printf("res:\n");
    for (int i = 0;i < n;i++) printf("%d ", c[i]);
  }
  MPI_Finalize();
}