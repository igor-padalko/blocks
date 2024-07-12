#include "shape.h"
#include <iostream>

struct Figure
{
	char width;
	char height;
	std::vector<char> data;
};

std::vector<Figure> figures =
{
	{ 2, 2, { 1, 1,
			  1, 1 } }, //Squape
	{ 1, 4, { 1,
			  1,
			  1,
			  1 } }, //Line
	{ 3, 2, { 0, 1, 0,
			  1, 1, 1 } }, //T
	{ 2, 3, { 0, 1,
			  0, 1,
			  1, 1 } }, //LLeft
	{ 2, 3, { 1, 0,
			  1, 0,
			  1, 1 } }, //LRright
	{ 2, 3, { 0, 1,
			  1, 1,
			  1, 0 } }, //SLeft
	{ 2, 3, { 1, 0,
			  1, 1,
			  0, 1 } }, //SRight
};

int calcAddress(int row, int col, int width)
{
	return row * width + col;
}

Shape::Shape()
	: m_columns(0)
	, m_rows(0)
	, m_data{}
{
}

Shape::Shape(ShapeType shapeType)
	: m_columns(figures[shapeType].width)
	, m_rows(figures[shapeType].height)
	, m_data(figures[shapeType].data)
{
}

void Shape::rotateRight()
{
	std::vector<char> d1(m_data.size());
	for (int row = 0; row < m_rows; ++row)
	{
		for (int col = 0; col < m_columns; ++col)
		{
			d1[calcAddress(col, row, m_rows)] = m_data[calcAddress(m_rows - 1 - row, col, m_columns)]; //по часовой
		}
	}
	m_data.swap(d1);
	std::swap(m_columns, m_rows);
}

void Shape::rotateLeft()
{
	std::vector<char> d1(m_data.size());
	for (int row = 0; row < m_rows; ++row)
	{
		for (int col = 0; col < m_columns; ++col)
		{
			d1[calcAddress(col, row, m_rows)] = m_data[calcAddress(row, m_columns - 1 - col, m_columns)]; //против часовой
		}
	}
	m_data.swap(d1);
	std::swap(m_columns, m_rows);
}

void Shape::show()
{
	for (int row = 0; row < m_rows; ++row)
	{
		for (int col = 0; col < m_columns; ++col)
		{
			std::cout << int(m_data[calcAddress(row, col, m_columns)]);
		}
		std::cout << std::endl;
	}
}

char Shape::rows() const
{
	return m_rows;
}

char Shape::columns() const
{
	return m_columns;
}

char Shape::value(char row, char column) const
{
//	auto adr = calcAddress(row, column, m_columns);
//	auto val = m_data[adr];
	return m_data[calcAddress(row, column, m_columns)];
}

