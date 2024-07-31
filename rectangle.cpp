#include "rectangle.h"

Rectangle::Rectangle(int w, int h, const std::vector<int> data)
	: m_x(0)
	, m_y(0)
	, m_w(w)
	, m_h(h)
	, m_data(data)
{
}

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

Rectangle Rectangle::copy(int x, int y, int w, int h) const
{
	Rectangle result(w, h);
	for (int xx = 0; xx < w; ++xx)
	{
		for (int yy = 0; yy < h; ++yy)
		{
			result.setPoint(xx, yy, point(x + xx, y + yy));
		}
	}
	return result;
}

bool Rectangle::compare(int x, int y, const Rectangle& other) const
{
	for (int xx = 0; xx < other.w(); ++xx)
	{
		for (int yy = 0; yy < other.h(); ++yy)
		{
			int p1 = point(x + xx, y + yy);
			int p2 = other.point(xx, yy);
			if (p1 != p2)
			{
				return false;
			}
		}
	}
	return true;
}

bool Rectangle::compare(const Rectangle& other) const
{
	return compare(other.x(), other.y(), other);
}

void Rectangle::insert(int x, int y, const Rectangle& other, int value)
{
	// TODO: неоюходимо проверять не выходит ли other за пределы this
	for (int xx = 0; xx < other.w(); ++xx)
	{
		for (int yy = 0; yy < other.h(); ++yy)
		{
			if (other.point(xx, yy) != 0)
			{
				setPoint(x + xx, y + yy, value);
			}
		}
	}
}

void Rectangle::insert(const Rectangle& other, int value)
{
	insert(other.x(), other.y(), other, value);
}

Rectangle Rectangle::rotateLeft() const
{
	Rectangle result(m_h, m_w);
	for (int y = 0; y < m_h; ++y)
	{
		for (int x = 0; x < m_w; ++x)
		{
			result.setPoint(y, x, point(x, m_h - 1 - y));
		}
	}
	return result;
}

Rectangle Rectangle::rotateRight() const
{
	Rectangle result(m_h, m_w);
	for (int y = 0; y < m_h; ++y)
	{
		for (int x = 0; x < m_w; ++x)
		{
			result.setPoint(y, x, point(m_w - 1 - x, y));
		}
	}
	return result;
}

void Rectangle::setData(const std::vector<int> data)
{
	m_data = data;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
	for (int yy = r.h(); --yy >= 0;)
	{
		for (int xx = 0; xx < r.w(); ++xx)
		{
			os << r.point(xx, yy);
		}
		os << std::endl;
	}
	return os;
}
