#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mpi.h>

void main(int argc, char* argv[]) {
  int size, rank;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  char outMessage[100] = "welcome to ise!", inMessage[100];
  int destination, source, rc, count, root = 1;
  MPI_Status stat;
  if (rank == 0) {
    destination = 1; //setting destination as rank 1
    //source=1;
    rc = MPI_Send(&outMessage, strlen(outMessage), MPI_CHAR, destination, root, MPI_COMM_WORLD);
  }
  else if (rank == 1) {
    //destination = 0;
    source = 0; // mentioning source as rank 0
    rc = MPI_Recv(&inMessage, strlen(outMessage), MPI_CHAR, source, root, MPI_COMM_WORLD, &stat);
  }
  rc = MPI_Get_count(&stat, MPI_CHAR, &count);
  printf("TASK %d, received %d char(s) task from %d with root %d and msg is %s\n", rank, count, stat.MPI_SOURCE, stat.MPI_TAG, inMessage);
  MPI_Finalize();
}