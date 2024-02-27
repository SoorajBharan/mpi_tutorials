#include "display.h"
#include <mpi.h>
#include <iostream>

#ifndef VMAT_OPERATIONS_H
#define VMAT_OPERATIONS_H

namespace matrix_vector {

#define SIZE 8

double a[SIZE][SIZE],b[SIZE],c[SIZE];

void
init_matrix(int rank, int num_procs)
{
	int rows_per_process = SIZE / num_procs;
	int start_row = rank * rows_per_process;
	int end_row = start_row + rows_per_process;
	double n = start_row + 1;
	for(uint i = start_row; i < end_row; i++)
	{
		for(uint j = 0; j < SIZE; j++)
		{
			a[i][j] = n;
		}
		b[i] = n;
		n++;
	}
}

void print_matrix(int rank, int num_procs, double m[SIZE][SIZE]) {
    double recv_buffer[SIZE][SIZE];
    int rows_per_process = SIZE / num_procs;
    MPI_Gather(&m[rank * rows_per_process][0], SIZE * rows_per_process, MPI_DOUBLE,
               recv_buffer, SIZE * rows_per_process, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    if (rank == 0) 
	{
		for (uint i = 0; i < SIZE; i++) 
		{
			 std::cout << std::endl;
			for (uint j = 0; j < SIZE; j++) 
			{
				std::cout << recv_buffer[i][j] << '\t';
			}
        }
    }
    MPI_Barrier(MPI_COMM_WORLD); // Ensure all processes finish printing before continuing
}

void
print_vector(int rank, int num_procs, double m[SIZE])
{
	double recv_buffer[SIZE];
	int cells_per_process = SIZE / num_procs;
	MPI_Gather(&m[rank * cells_per_process], cells_per_process, MPI_DOUBLE, recv_buffer,cells_per_process, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	if(rank == 0)
	{
		for(uint i = 0; i < SIZE; i++)
		{
			std::cout<< recv_buffer[i] <<'\t';
		}
		std::cout<<std::endl;
	}
	MPI_Barrier(MPI_COMM_WORLD);
}

void 
vmult(int rank, int num_procs, double m[SIZE][SIZE], double x[SIZE], double y[SIZE])
{
	int rows_per_process = SIZE / num_procs;
	double recv_buffer[SIZE];
	int start_row = rank * rows_per_process;
	int end_row = start_row + rows_per_process;
	for(uint row_block = 0; row_block < num_procs; row_block++)
	{
		if(row_block!=rank)
		{
			MPI_Send(&x[rank*rows_per_process],rows_per_process,MPI_DOUBLE,row_block,1,MPI_COMM_WORLD);
			// display(rank," sending row block to ",row_block);
		}else{
			MPI_Allgather(&x[rank*rows_per_process],rows_per_process, MPI_DOUBLE, recv_buffer, rows_per_process, MPI_DOUBLE,  MPI_COMM_WORLD);
			// display(rank," gathered the vector");
			for (uint i = start_row; i < end_row; i++)
			{
				recv_buffer[i] = x[i];
			}

			for(uint i = start_row; i < end_row; i++)
			{
				y[i] = 0;
				for(uint j = 0; j < SIZE; j++)
				{
					y[i] += m[i][j] * recv_buffer[j];
				}
			}
			MPI_Barrier(MPI_COMM_WORLD);
		}

	}
}


}

#endif // !DEBUG
