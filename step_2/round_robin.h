#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <iostream>
#include <cstdlib>
#include <mpi.h>
#include "display.h"

void
round_robin(int rank, int procs)
{
	long int rand_mine, rand_prev;
	int rank_next = (rank+1) % procs;
	int rank_prev = rank == 0 ? procs-1 : rank-1;


	MPI_Status status;

	srand(time(NULL) + rank);
	rand_mine = rand() / (RAND_MAX / 100);
	display(rank, " generated : ", rand_mine);

	if(rank % 2 == 0)
	{
		display(rank," sending ", rand_mine, " to ", rank_next);
		MPI_Send((void *) &rand_mine,
			1,
			MPI_LONG,
			rank_next,
			1,
			MPI_COMM_WORLD);

		MPI_Recv((void *) &rand_prev,
			1,
			MPI_LONG,
			rank_prev,
			1,
			MPI_COMM_WORLD,
			&status);
		display(rank, " received ", rand_prev, " from ", rank_prev);
	//	displayMPIStatus(rank,status);
	}
	else {
		MPI_Recv((void *) &rand_prev,
			1,
			MPI_LONG,
			rank_prev,
			1,
			MPI_COMM_WORLD,
			&status);
		
		display(rank, " will received ", rand_prev, " from ", rank_prev);
	//	displayMPIStatus(rank,status);
		
		MPI_Send((void *) &rand_mine,
			1,
			MPI_LONG,
			rank_next,
			1,
			MPI_COMM_WORLD);

		display(rank," sending ", rand_mine, " to ", rank_next);
	}
}

#endif
