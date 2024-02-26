#include <iostream>
#include <sstream>

template<typename... Args>
void display(int rank, const Args&... args)
{
	std::ostringstream oss;
	(oss<<...<<args);
	std::cout << "Rank : " << rank << oss.str() << std::endl;
}
