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
	if (!isDownAvailable()) { return; }

	Shape shape = m_shape;
	shape.setY(shape.y() - 1);
	if (isDrawAvailable(shape))
	{
		draw(m_shape, 0);
		addShape(shape);
	}
}

void Field::draw(const Shape& shape, int value)
{
	insert(shape, value);
}

bool Field::isDownAvailable() const
{
	return m_shape.y() != 0;
}

bool Field::isDrawAvailable(const Shape& shape) const
{
	// 0) запоминаем поле field в новую переменную
	Field field = *this;
	// 1) стираем предыдущую фигуру m_shape
	field.insert(m_shape, 0);
	// 2) запоминаем поле под новой фигурой shape
	Rectangle uShape1 = field.copy(shape.x(), shape.y(), shape.w(), shape.h());
	// 3) рисуем новую фигуру shape
	field.insert(shape);
	// 4) стираем фигуру shape
	field.insert(shape, 0);
	// 5) запоминаем поле снова под новой фигурой shape
	Rectangle uShape2 = field.copy(shape.x(), shape.y(), shape.w(), shape.h());
	// 6) сравниваем запомненную в 2 и 5
	bool isEqual = uShape1.compare(uShape2);
	// 7) если разные, то рисовать нельзя, иначе можно рисовать
	return isEqual;
}
