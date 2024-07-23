#ifndef SHAPE_H
#define SHAPE_H

#include "rectangle.h"

class Shape : public Rectangle
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
	Shape(const Rectangle& other);
	Shape(ShapeType shapeType);
};

#endif // SHAPE_H
