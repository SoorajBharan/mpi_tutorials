#include <iostream>
#include <mpi.h>
#include "display.h"
#include "round_robin.h"

int 
main (int argc, char **argv)
{
	int num_procs;
	int rank;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	display(rank);
	round_robin(rank, num_procs);
	display(rank, " exiting");


	MPI_Finalize();

	return 0;
}
