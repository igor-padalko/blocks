#include <iostream>
#include "field.h"

using namespace std;

int main()
{
//	Shape shape(Shape::T);
//	shape.show();
//	shape.rotateLeft();
//	shape.show();
	Field field(20, 10);
//	field.setPoint(20,10);

	Shape s(Shape::Line);
	s.rotateRight();
	field.addShape(s, 0, 0);
	field.addShape(s, 1, 0);

	field.addShape(Shape::LLeft, 0, 3);
	field.show();
	field.down();
	cout << endl;
	field.show();
	return 0;
}
