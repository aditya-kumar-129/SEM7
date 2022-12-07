#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]) {
  int myRank, size, fact, lower, upper, i;
  double local_result = 1.0;
  double total;

  MPI_Init(&argc, &argv);
  /* get my rank and the size of the communicator */
  MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  /* get the input. (only if i have rank 0) */
  if (myRank == 0) {
    printf("Enter a number:");
    scanf("%d", &fact);
  }
  // since only the process with rank 0 has the input, we must pass it to all the other processes.
  MPI_Bcast(&fact, 1, MPI_INT, 0, MPI_COMM_WORLD);

  // calculate the upper and lower boundaries for each process
  if (myRank == 0) lower = 1;
  else lower = myRank * (fact / size) + 1;
  if (myRank == (size - 1)) upper = fact;
  else upper = (myRank + 1) * (fact / size);

  // now that we know upper and lower, do the multiplication in our local area
  for (i = lower;i <= upper;i++) local_result = local_result * (double)i;
  // combine all the local results by multiplying them together
  MPI_Reduce(&local_result, &total, 1, MPI_DOUBLE, MPI_PROD, 0, MPI_COMM_WORLD);

  if (myRank == 0) printf("The factorial of %d is %lf, and was calculated using %d processes\n", fact, total, size);
  MPI_Finalize();
  return 0;
}