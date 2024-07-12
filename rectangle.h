#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>

class Rectangle
{
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

	Rectangle copyPart(int x, int y, int w, int h) const;
	bool comparePart(int x, int y, const Rectangle& other) const;
	void paste(int x, int y, const Rectangle& other);


private:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	std::vector<int> m_data;
};

#endif // RECTANGLE_H
