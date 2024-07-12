#include <iostream>

#include "field.h"

int calcAddress1(int row, int col, int width)
{
	return row * width + col;
}


Field::Field(int rows, int columns)
	: m_rows(rows)
	, m_columns(columns)
{
	m_data.resize(m_rows * m_columns);
}

void Field::addShape(const Shape& shape)
{
	m_shape = shape;
	m_shapeColumn = (m_columns - shape.columns()) / 2;
	m_shapeRow = m_rows - shape.rows();
	draw(shape, 1);
}

void Field::addShape(const Shape& shape, int row, int column)
{
	m_shape = shape;
	m_shapeColumn = column;
	m_shapeRow = row;
	draw(shape, 1);

}

void Field::setPoint(int row, int col, int value)
{
	if ((row >= m_rows) || (col >= m_columns)) { return; }
	m_data[row * m_columns + col] = value;
}

int Field::getPoint(int row, int col) const
{
	return m_data[row * m_columns + col];
}

void Field::down()
{
	// проверить возможность переместить фигуру ниже
	if (isDownAvailable())
	{
		draw(m_shape, 0);
		m_shapeRow -= 1;
		draw(m_shape, 1);
	}
}

void Field::show()
{
	for (int row = m_rows; --row >= 0;)
	{
		for (int col = 0; col < m_columns; ++col)
		{
			std::cout << int(m_data[row * m_columns + col]);
		}
		std::cout << std::endl;
	}
}

void Field::draw(const Shape& shape, int value)
{
	for (int row = 0; row < shape.rows(); ++row)
	{
		for (int col = 0; col < shape.columns(); ++col)
		{
			if (shape.value(row, col) == 1)
			{
				setPoint(m_shapeRow + row, m_shapeColumn + col, value);
			}
		}
	}
}

bool Field::isDownAvailable() const
{
	if (m_shapeRow == 0) { return false; }


//	int uRow = m_shapeRow - 1;
//	for (int uCol = 0; uCol < m_shape.columns(); ++uCol)
//	{
//		if (getPoint(uRow, uCol + m_shapeColumn) == 1)
//		{
//			return false;
//		}
//	}
//	return true;
	for (int uCol = 0; uCol < m_shape.columns(); ++uCol)
	{
		int uRow = 0;
		for (int row = 0; row < m_shape.rows(); ++row)
		{
			if (m_shape.value(row, uCol) == 1)
			{
				uRow = row;
				break;
			}
		}
		if (getPoint(uRow + m_shapeRow - 1, uCol + m_shapeColumn) == 1)
		{
			return false;
		}
	}
	return true;

}
