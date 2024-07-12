#ifndef FIELD_H
#define FIELD_H

#include <vector>

#include "shape.h"

class Field
{
public:
	Field(int rows, int columns);
	void addShape(const Shape& shape);
	void addShape(const Shape& shape, int row, int column);
	void setPoint(int row, int col, int value = 1);
	int getPoint(int row, int col) const;

	void down();

	void show();
private:
	void draw(const Shape& shape, int value);
	bool isDownAvailable() const;
private:
	int m_rows;
	int m_columns;
	std::vector<char> m_data;

	Shape m_shape;
	int m_shapeRow;
	int m_shapeColumn;
};

#endif // FIELD_H
