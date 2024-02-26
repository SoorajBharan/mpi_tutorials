#ifndef VMAT_OPERATIONS_H
#define VMAT_OPERATIONS_H

namespace matrix_vector {

#define SIZE 8

double a[SIZE][SIZE],b[SIZE],c[SIZE];

void
init_matrix(void)
{
	double n = 1;
	for(uint i = 0; i < SIZE; i++)
	{
		for(uint j = 0; j < SIZE; j++)
		{
			a[i][j] = n + 1;
		}
		b[i] = n;
		n++;
	}
}

void
print_matrix(double m[SIZE][SIZE])
{
	for(uint i = 0; i < SIZE; i++)
	{
		std::cout << std::endl;
		for( uint j = 0; j < SIZE; j++)
		{std::cout<<m[i][j]<<'\t';}
	}
}

void
print_vector(double m[SIZE])
{
	for(uint i = 0; i < SIZE; i++)
	{
		std::cout<< m[i] <<'\t';
	}
}

}

#endif // !DEBUG
