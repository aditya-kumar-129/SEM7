#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

void main(int argc, char* argv[]) {
  int rank, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int source, destination, count, rc, root = 1;
  char outMessage[100] = "welcome to ise!", inMessage[100];
  MPI_Status stat;
  if (rank == 0) {
    destination = 1;
    rc = MPI_Send(&outMessage, strlen(outMessage), MPI_CHAR, destination, root, MPI_COMM_WORLD);
  }
  else if (rank == 1) {
    source = 0;
    rc = MPI_Recv(&inMessage, strlen(outMessage), MPI_CHAR, source, root, MPI_COMM_WORLD, &stat);
  }
  rc = MPI_Get_count(&stat, MPI_CHAR, &count);
  printf("msg is %s\n", inMessage);
  MPI_Finalize();
}