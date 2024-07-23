#include <iostream>
#include "field.h"
#include "rectangle.h"

using namespace std;

int main()
{
	Rectangle r(10,15);
	r.setPoint(2, 2);
	std::cout << r;
	Rectangle c = r.copyPart(2, 2, 5, 6);
	std::cout << std::endl;
	std::cout << "comapre: " << r.comparePart(2, 2, c) << std::endl;
	c.setPoint(4, 4);
	std::cout << c;
	std::cout << "comapre: " << r.comparePart(2, 2, c) << std::endl;
	std::cout << std::endl;
	r.paste(5, 5, c);
	std::cout << r << std::endl;
	c.setPoint(0, 4);
	std::cout << c << std::endl;
	Rectangle rotatedLeft = c.rotateLeft();
	std::cout << rotatedLeft << std::endl;

	Rectangle rotatedRight = c.rotateRight().rotateRight();
	std::cout << rotatedRight << std::endl;

//	Shape shape(Shape::T);
//	shape.show();
//	shape.rotateLeft();
//	shape.show();
//	Field field(20, 10);
////	field.setPoint(20,10);

//	Shape s(Shape::Line);
//	s.rotateRight();
//	field.addShape(s, 0, 0);
//	field.addShape(s, 1, 0);

//	field.addShape(Shape::LLeft, 0, 3);
//	field.show();
//	field.down();
//	cout << endl;
//	field.show();

	return 0;
}
