#include<stdio.h>
#include<stdlib.h>
#include <mpi.h>

int main(int argc, char* argv[]) {

  // argc:- Pointer to the number of arguments
  // argv:- Pointer to the argument vector
  MPI_Init(&argc, &argv);

  int rank, size, locSum = 0, globSum = 0;

  // Determines the rank of the calling process in the communicator
  // int MPI_Comm_rank(MPI_Comm comm, int *rank)
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // Determines the size of the group associated with a communicator
  // int MPI_Comm_size(MPI_Comm comm, int *size)
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  locSum += (2 * rank + 2) + (2 * rank + 1);
  printf("Local sum for rank %d is %d \n", rank, locSum);

  // Reduces values on all processes to a single value
  // MPI_Reduce takes an array of input elements on each process and returns an array of output elements to the root process. 
  // The output elements contain the reduced result. The prototype for MPI_Reduce looks like this:

  // MPI_Reduce( void* send_data, void* recv_data, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm communicator)
  // Input Parameters
  // send_data:- address of send buffer(choice)
  // count :- number of elements in send buffer(integer)
  // datatype :- data type of elements of send buffer(handle)
  // op :- reduce operation(handle)
  // root :- rank of root process(integer)
  // comm :- communicator(handle)

  // Output Parameters
  // recvbuf:- address of receive buffer(choice, significant only at root)
  MPI_Reduce(&locSum, &globSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  
  if (rank == 0) printf("Total sum is %d \n", globSum);
  MPI_Finalize();
  return 0;
}

// Some of the MPI_Operation functions are as follows:- 
// MPI_MAX - Returns the maximum element.
// MPI_MIN - Returns the minimum element.
// MPI_SUM - Sums the elements.
// MPI_PROD - Multiplies all elements.
// MPI_LAND - Performs a logical and across the elements.
// MPI_LOR - Performs a logical or across the elements.
// MPI_BAND - Performs a bitwise and across the bits of the elements.
// MPI_BOR - Performs a bitwise or across the bits of the elements.

// MPI_COMM_WORLD
// The default communicator is called MPI_COMM_WORLD.It basically groups all the processes when the program started.
// https://www.codingame.com/servlet/fileservlet?id=14312022001591