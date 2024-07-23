#include <iostream>

#include "field.h"

Field::Field(int width, int height)
	: Rectangle(width, height)
{
}

void Field::addShape(const Shape& shape)
{
	m_shape = shape;
	m_shape.setX(w() - shape.w() / 2);
	m_shape.setY(h() - shape.h());
	draw(shape, 1);
}

void Field::addShape(const Shape& shape, int x, int y)
{
	m_shape = shape;
	m_shape.setX(x);
	m_shape.setY(y);
	draw(m_shape, 1);

}

void Field::down()
{
	// проверить возможность переместить фигуру ниже
	if (isDownAvailable())
	{
		draw(m_shape, 0);
		m_shape.setY(m_shape.y() - 1);
		draw(m_shape, 1);
	}
}

void Field::draw(const Shape& shape, int value)
{
//	for (int row = 0; row < shape.rows(); ++row)
//	{
//		for (int col = 0; col < shape.columns(); ++col)
//		{
//			if (shape.value(row, col) == 1)
//			{
//				setPoint(m_shapeRow + row, m_shapeColumn + col, value);
//			}
//		}
//	}
	paste(shape.x(), shape.y(), shape);
}

bool Field::isDownAvailable() const
{
//	if (m_shapeRow == 0) { return false; }

//	for (int uCol = 0; uCol < m_shape.columns(); ++uCol)
//	{
//		int uRow = 0;
//		for (int row = 0; row < m_shape.rows(); ++row)
//		{
//			if (m_shape.value(row, uCol) == 1)
//			{
//				uRow = row;
//				break;
//			}
//		}
//		if (getPoint(uRow + m_shapeRow - 1, uCol + m_shapeColumn) == 1)
//		{
//			return false;
//		}
//	}
	return true;

}
