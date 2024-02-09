#include <iostream>
#include <mpi.h>

int 
main (int argc, char **argv)
{
	int num_procs;
	int rank;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	std::cout<<"Number of processors : "<<num_procs<<", rank : "<<rank<<std::endl;

	MPI_Finalize();

	return 0;
}
