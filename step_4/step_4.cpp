#include <iostream>
#include <mpi.h>
#include "display.h"
#include "send_and_receive.h"
#include <time.h>
#include <chrono>


int 
main (int argc, char **argv)
{
	int num_procs;
	int rank;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	sync_mpi::start_time = std::chrono::high_resolution_clock::now();
	sync_mpi::display(rank);

	srand(time(NULL) + rank);
	if(rank == 0)
	{
		sync_mpi::send_to_many(num_procs);
	}
	else 
	{
		sync_mpi::receive_from_one(rank);
	}
	sync_mpi::display(rank, " exiting");


	MPI_Finalize();

	return 0;
}

	
