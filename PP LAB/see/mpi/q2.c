#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

void main(int argc, char* argv[]) {
  int rank, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  char outMessage[100] = "Hey there", inMessage[100];
  int source, destination, tag1 = 1, tag2 = 2, rc, count;
  MPI_Status stat;

  if (rank == 0) {
    source = 1; destination = 1;
    rc = MPI_Send(&outMessage, strlen(outMessage), MPI_CHAR, destination, tag1, MPI_COMM_WORLD);
    rc = MPI_Recv(&inMessage, strlen(outMessage), MPI_CHAR, destination, tag2, MPI_COMM_WORLD, &stat);
  }
  else if (rank == 1) {
    source = 0; destination = 0;
    rc = MPI_Send(&outMessage, strlen(outMessage), MPI_CHAR, destination, tag1, MPI_COMM_WORLD);
    rc = MPI_Recv(&inMessage, strlen(outMessage), MPI_CHAR, destination, tag2, MPI_COMM_WORLD, &stat);
  }
  rc = MPI_Get_count(&stat, MPI_CHAR, &count);
  printf("Task %d, received %d char(s) task from %d with tag %d and msg is %s\n", rank, count, stat.MPI_SOURCE, stat.MPI_TAG, inMessage);
  MPI_Finalize();
}