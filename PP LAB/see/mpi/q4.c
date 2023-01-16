#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

void main(int argc, char* argv[]) {
  int rank, size;
  int n; scanf("%d", &n);

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int root = 0;
  MPI_Bcast(&n, 1, MPI_INT, root, MPI_COMM_WORLD);

  int localProduct = 1;
  int len = (n / size) + 1;   // remember
  for (int i = (rank * len) + 1;i <= ((rank + 1) * len);i++) {    // remember
    if (i > n) break;
    localProduct *= i;
  }

  int globalProduct;
  MPI_Reduce(&localProduct, &globalProduct, 1, MPI_INT, MPI_PROD, root, MPI_COMM_WORLD);
  if (rank == root) printf("Factorial of %d is %d", n, globalProduct);
  MPI_Finalize();
}