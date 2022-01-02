#include "matrix.h"
#include <ostream>

Matrix::Matrix()
	: m_rowSize(0), m_columnSize(0), m_matrix(nullptr){}

Matrix::Matrix(unsigned int rowSize, unsigned int columnSize)
	: m_rowSize(rowSize), m_columnSize(columnSize)
{
	this->m_matrix = new type[columnSize * rowSize];
}

Matrix::~Matrix()
{
	delete[] this->m_matrix;
}

type& Matrix::operator()(unsigned int row, unsigned int column)
{
	return this->m_matrix[row + this->m_rowSize * column];
}

std::ostream& operator << (std::ostream& stream, Matrix& other)
{
	try
	{
		for(unsigned int row = 0; row < other.getSize().row; row++)
		{
			for(unsigned int column = 0; column < other.getSize().column; column++)
				stream << other(row, column);
			stream << "\n";
		}
		return stream;
	}
	catch(const char * e)
	{
		throw "Can't log current type to console";
	}
}

void Matrix::fill(type value)
{
	for(size_t i = 0; i < this->m_rowSize * this->m_columnSize; i++)
		this->m_matrix[i] = value;
}

void Matrix::setRowSize(size_t size)
{
	this->m_rowSize = size;
	this->m_matrix = new type[this->m_rowSize * this->m_columnSize];
}

void Matrix::setColumnSize(size_t size)
{
	this->m_columnSize = size;
	this->m_matrix = new type[this->m_rowSize * this->m_columnSize];
}

void Matrix::setSize(size_t row, size_t column)
{
	this->m_rowSize = row;
	this->m_columnSize = column;
	this->m_matrix = new type[this->m_rowSize * this->m_columnSize];
}

void Matrix::setSize(Vector2 size)
{
	this->m_rowSize = size.row;
	this->m_columnSize = size.column;
	this->m_matrix = new type[this->m_rowSize * this->m_columnSize];
}

void Matrix::operator=(Matrix& other)
{
	if(other.getSize().row != this->m_rowSize || other.getSize().column != this->m_columnSize)	
		this->setSize(other.getSize());
	for(size_t row = 0; row < this->m_rowSize; row++)
		for(size_t column = 0; column < this->m_columnSize; column++)
			this->m_matrix[row + this->m_rowSize * column] = other(row, column);
}
