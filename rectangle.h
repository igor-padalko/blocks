#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <vector>

class Rectangle
{
protected:
	Rectangle(int w, int h, const std::vector<int> data);
public:
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(const Rectangle& other);

	int x() const;
	void setX(int newX);

	int y() const;
	void setY(int newY);

	int w() const;
	void setW(int newW);

	int h() const;
	void setH(int newH);

	int point(int x, int y) const;
	void setPoint(int x, int y, int value = 1);

	Rectangle copy(int x, int y, int w, int h) const;
	bool compare(int x, int y, const Rectangle& other) const;
	bool compare(const Rectangle& other) const;
	void insert(int x, int y, const Rectangle& other, int value = 1);
	void insert(const Rectangle& other, int value = 1);

	Rectangle rotateLeft() const;
	Rectangle rotateRight() const;

protected:
	void setData(const std::vector<int> data);

private:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	std::vector<int> m_data;
};

std::ostream& operator<<(std::ostream& os, const Rectangle& m);

#endif // RECTANGLE_H
