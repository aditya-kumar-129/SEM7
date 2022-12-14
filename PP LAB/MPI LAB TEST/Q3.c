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

// Theoretical Stuffs:- 
// MPI_Gather
// MPI_Gather is the inverse of MPI_Scatter. Instead of spreading elements from one process to many processes, 
// MPI_Gather takes elements from many processes and gathers them to one single process.
// This routine is used in parallel sorting and searching.

// MPI_Gather takes elements from each process and gathers them to the root process. 

// Syntax:-
// MPI_Gather(
//   void* send_data,
//   int send_count,
//   MPI_Datatype send_datatype,
//   int recv_count,
//   MPI_Datatype recv_datatype,
//   int root,
//   MPI_Comm communicator)  


// In MPI_Gather, only the root process needs to have a valid receive buffer. All other calling processes can pass NULL for recv_data. 
// Also, don’t forget that the recv_count parameter is the count of elements received per process, 
// not the total summation of counts from all processes.


// MPI_Scatter
// MPI_Scatter involves a designated root process sending data to all processes in a communicator. 
// The primary difference between MPI_Bcast and MPI_Scatter is that MPI_Bcast sends the same piece of data to all processes 
// while MPI_Scatter sends chunks of an array to different processes. 

// Syntax:- 
// MPI_Scatter(
//   void* send_data,
//   int send_count,            // number of elements in the array divided by the number of processes
//   MPI_Datatype send_datatype,
//   int recv_count,
//   MPI_Datatype recv_datatype,
//   int root,
//   MPI_Comm communicator)