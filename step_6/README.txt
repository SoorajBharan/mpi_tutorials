Program for calculating the matrix and vector product using mpi.

SIZE-> number of rows/columns of the square matrix
num_procs -> number of process

rows_per_process = SIZE / num_procs

only 'rows_per_process' number of rows are created by each processor.
The MPI_Gather is used assemble the full matrix in recv_buffer before printing

cells_per_process = SIZE / num_procs
only 'cells_per_process' numbers of cells are created by each processor.


