#ifndef SEND_AND_RECEIVE_H
#define SEND_AND_RECEIVE_H

#include "display.h"
#include <cstdlib>
#include <mpi.h>

namespace sync_mpi {

void await_request(int rank, MPI_Request *request);

void
send_to_many(int num_procs)
{
	long rand_value = rand() / ( RAND_MAX / 100 );
	display(0," generated ", rand_value);
	MPI_Request send_request;

	for( int to_rank; to_rank < num_procs; to_rank++)
	{
		long value_sent = rand_value + to_rank;
		MPI_Isend((void *) &value_sent, 1, MPI_LONG, to_rank, 1, MPI_COMM_WORLD, &send_request);

		await_request(0, &send_request);
		display(0," sent ",value_sent, " to ",to_rank);
	}
}

void
receive_from_one(int rank)
{
	long recv_buffer;
	MPI_Request recv_request;

	MPI_Irecv((void *) &recv_buffer, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, &recv_request);

	await_request(rank, &recv_request);
	display(rank, " received ", recv_buffer);
}

void
await_request(int rank, MPI_Request *request)
{
	int wait_count = 0;
	int flag = 0;
	MPI_Status status;

	do {
		wait_count++;
		MPI_Test(request, &flag, &status);
	}while (!flag);

	display(rank, " tested ",wait_count,"times");
}

}

#endif // !SEND_AND_RECEIVE_H
