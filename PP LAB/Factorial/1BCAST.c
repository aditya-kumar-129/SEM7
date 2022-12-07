#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]) {
  MPI_Init(&argc, &argv);
  int rank, size, x = 0, buf;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (rank == x) buf = 777;
  printf("Before: Buffer in %d is %d \n", rank, buf);

  // MPI_Bcast broadcasts a message from a process to all other processes in the same communicator. 
  // This is a collective operation; it must be called by all processes in the communicator.
  // On return, the contents of root’s communication buffer has been copied to all processes.

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
  MPI_Bcast(&buf, 1, MPI_INT, x, MPI_COMM_WORLD);

  printf("After: Buffer in %d is %d \n", rank, buf);
  // fflush() is typically used for output stream only. Its purpose is to clear (or flush) the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream).
  fflush(stdout);
  MPI_Finalize();
  return 0;
}