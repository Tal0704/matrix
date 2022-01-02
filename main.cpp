#include <iostream>
#include "matrix.h"

int main()
{
	Matrix matrix(3, 3);
	matrix(2, 2) = 5;
	Matrix m2(2, 2);
	m2(1, 1) = 3;
	matrix = m2;

	std::cout << matrix;

	return 0;
}
