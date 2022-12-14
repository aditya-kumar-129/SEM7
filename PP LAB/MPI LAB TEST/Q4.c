#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

// do not give high input because the stack will overflow and no output will be seen (segmentation fault)
// try n = 7 or 8
void main(int argc, char* argv[]) {
  int n, rank, size, root = 0, global;
  scanf("%d", &n);
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  MPI_Bcast(&n, 1, MPI_INT, root, MPI_COMM_WORLD);
  int localProduct = 1;
  int len = (n / size) + 1;
  for (int i = (rank * len) + 1;i <= ((rank + 1) * len);i++) {
    if (i > n) break;
    localProduct *= i;
  }
  printf("LOCAL PROF:%d\n", localProduct);
  MPI_Reduce(&localProduct, &global, 1, MPI_INT, MPI_PROD, root, MPI_COMM_WORLD);
  if (rank == root) printf("Factorial of %d is %d\n", n, global);
  MPI_Finalize();
}

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


// Syntax of MPI_Bcast
// int MPI_Bcast(void* buffer, int count, MPI_Datatype datatype, int emitter_rank, MPI_Comm communicator);

// Parameters
// buffer:- The buffer from which load the data to broadcast if the calling MPI process is the emitter, or the buffer in which store the data broadcasted is the calling MPI process is a receiver.
// count:- The number of elements in the buffer broadcasted.
// datatype:- The type of an element in the buffer broadcasted.
// emitter_rank:- The rank of the MPI process that broadcasts the data, all other processes receive the data broadcasted.
// communicator:- The communicator in which the broadcast takes place.

// Return
// MPI_SUCCESS: The routine successfully completed.