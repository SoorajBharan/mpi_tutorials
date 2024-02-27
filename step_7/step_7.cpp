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
	// matrix_vector::display(rank);

	matrix_vector::init_matrix(rank,num_procs);
	matrix_vector::vmult(rank,num_procs,matrix_vector::a,matrix_vector::b,matrix_vector::c);
	matrix_vector::print_matrix(rank,num_procs,matrix_vector::a);
	std::cout<<'\n';
	matrix_vector::print_vector(rank,num_procs,matrix_vector::b);
	matrix_vector::print_vector(rank,num_procs,matrix_vector::c);

	// matrix_vector::display(rank, " exiting");

	MPI_Finalize();

	return 0;
}

	
