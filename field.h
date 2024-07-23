#ifndef FIELD_H
#define FIELD_H

#include "shape.h"

class Field : public Rectangle
{
public:
	Field(int width, int height);
	void addShape(const Shape& shape);
	void addShape(const Shape& shape, int x, int y);

	void down();

private:
	void draw(const Shape& shape, int value);
	bool isDownAvailable() const;
private:
	Shape m_shape;
};

#endif // FIELD_H
