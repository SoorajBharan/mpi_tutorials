#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <iostream>
#include <cstdlib>
#include <mpi.h>
#include "display.h"

namespace roundRobin {

void
round_robin(int rank, int procs)
{
	long int rand_mine, rand_prev;
	int rank_next = (rank+1) % procs;
	int rank_prev = rank == 0 ? procs-1 : rank-1;


	MPI_Status status;

	srand(time(NULL) + rank);
	rand_mine = rand() / (RAND_MAX / 100);

	MPI_Sendrecv((void *) &rand_mine,1,MPI_LONG,rank_next,1,
		(void *) &rand_prev,1,MPI_LONG,rank_prev,1,
		MPI_COMM_WORLD,
		&status);
	display(rank," generated ",rand_mine,"| Received ",rand_prev, " from ",rank_prev);
}

}
#endif
