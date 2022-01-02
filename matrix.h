#pragma once
#include <iostream>

typedef int type;

struct Vector2
{
	unsigned int row, column;
	Vector2(unsigned int row, unsigned int column)
		: row(row), column(column) {}
};

class Matrix
{
private:
	unsigned int m_rowSize;
	unsigned int m_columnSize;
	type* m_matrix;

public:
	void fill(type);

	void setRowSize(size_t size);

	void setColumnSize(size_t size);

	void setSize(size_t row, size_t column);

	void setSize(Vector2);

	void operator=(Matrix&);

	type& operator()(unsigned int, unsigned int);

	Vector2 getSize()
		{ return Vector2(this->m_rowSize, this->m_columnSize); }

	Matrix();

	Matrix(unsigned int, unsigned int);

	~Matrix();

};

std::ostream& operator << (std::ostream& stream, Matrix& other);
