#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <sstream>
#include <mpi.h>

template<typename... Args>
void display(int rank, const Args&... args)
{
	std::ostringstream oss;
	(oss<<...<<args);
	std::cout << "Rank : " << rank << oss.str() << std::endl;
}

void displayMPIStatus(int rank, const MPI_Status& status);

#endif
