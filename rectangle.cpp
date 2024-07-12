#include "rectangle.h"

Rectangle::Rectangle()
	: m_x(0)
	, m_y(0)
	, m_w(0)
	, m_h(0)
{

}

Rectangle::Rectangle(int w, int h)
	: m_x(0)
	, m_y(0)
	, m_w(w)
	, m_h(h)
{
	m_data.resize(m_w * m_h);
}

Rectangle::Rectangle(const Rectangle& other)
	: m_x(other.m_x)
	, m_y(other.m_y)
	, m_w(other.m_w)
	, m_h(other.m_h)
	, m_data(other.m_data)
{
}

int Rectangle::x() const
{
	return m_x;
}

void Rectangle::setX(int x)
{
	m_x = x;
}

int Rectangle::y() const
{
	return m_y;
}

void Rectangle::setY(int y)
{
	m_y = y;
}

int Rectangle::w() const
{
	return m_w;
}

void Rectangle::setW(int w)
{
	m_w = w;
}

int Rectangle::h() const
{
	return m_h;
}

void Rectangle::setH(int h)
{
	m_h = h;
}

int Rectangle::point(int x, int y) const
{
	if ((x >= 0) && (x < m_w) &&
		(y >= 0) && (y < m_h))
	{
		return m_data[y * m_w + x];
	}
	else
	{
		return 0;
	}
}

void Rectangle::setPoint(int x, int y, int value)
{
	if ((x >= 0) && (x < m_w) &&
		(y >= 0) && (y < m_h))
	{
		m_data[y * m_w + x] = value;
	}
}

Rectangle Rectangle::copyPart(int x, int y, int w, int h) const
{

}

bool Rectangle::comparePart(int x, int y, const Rectangle& other) const
{

}

void Rectangle::paste(int x, int y, const Rectangle& other)
{

}
