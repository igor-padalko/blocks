#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

class Shape
{
public:
	enum ShapeType
	{
		Square,
		Line,
		T,
		LLeft,
		LRight,
		SLeft,
		SRight,
	};
	Shape();
	Shape(ShapeType shapeType);

	void rotateRight();
	void rotateLeft();
	void show();

	char rows() const;
	char columns() const;
	char value(char row, char column) const;
private:
	char m_columns;
	char m_rows;
	std::vector<char> m_data;
};

#endif // SHAPE_H
