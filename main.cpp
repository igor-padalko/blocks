#include <iostream>
#include "field.h"
#include "rectangle.h"

int main()
{
	Shape shape(Shape::T);
	std::cout << shape << std::endl;

	shape = shape.rotateLeft();
	std::cout << shape << std::endl;

	Field field(10, 20);
//	field.setPoint(9,19);
//	std::cout << field << std::endl;

	Shape s(Shape::Line);
	s = s.rotateRight();
	field.addShape(s, 0, 0);
	field.addShape(s, 0, 1);
	std::cout << field << std::endl;

	field.addShape(Shape::LLeft, 0, 3);
	std::cout << field << std::endl;
	field.down();
	std::cout << field << std::endl;

	return 0;
}
