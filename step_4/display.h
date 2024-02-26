#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <sstream>
#include <mpi.h>
#include <ctime>
#include <chrono>

namespace sync_mpi {

std::chrono::time_point<std::chrono::high_resolution_clock> start_time;

template<typename... Args>
void display(int rank, const Args&... args)
{
	std::ostringstream oss;
	(oss<<...<<args);

	auto current_time = std::chrono::high_resolution_clock::now(); // displays the time in seconds
	auto elapse_time = std::chrono::duration_cast<std::chrono::duration<double>>(current_time - start_time).count();


	std::cout << elapse_time << "\t | rank : " << rank << oss.str() << std::endl;
}

void displayMPIStatus(int rank, const MPI_Status& status)
{
	display(rank, " MPI Status \n Source : ", status.MPI_SOURCE, "\n Tag : ", status.MPI_TAG, "\n Error : ",status.MPI_ERROR);
}

}
#endif
