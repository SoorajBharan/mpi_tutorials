#include <iostream>
#include <mpi.h>
#include "display.h"
#include "vmat_operations.h"
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

	matrix_vector::start_time = std::chrono::high_resolution_clock::now();
	matrix_vector::display(rank);

	if(rank == 0)
	{
		matrix_vector::init_matrix();
		matrix_vector::print_matrix(matrix_vector::a);
		std::cout<<'\n';
		matrix_vector::print_vector(matrix_vector::b);
		std::cout<<'\n';
	}

	matrix_vector::display(rank, " exiting");

	MPI_Finalize();

	return 0;
}

	
