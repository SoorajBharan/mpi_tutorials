#include "display.h"
void displayMPIStatus(int rank, const MPI_Status& status)
{
	display(rank, " MPI Status \n Source : ", status.MPI_SOURCE, "\n Tag : ", status.MPI_TAG, "\n Error : ",status.MPI_ERROR);
}
