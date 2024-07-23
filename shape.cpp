#include "shape.h"
#include <iostream>

struct Figure
{
	int width;
	int height;
	std::vector<int> data;
};

std::vector<Figure> figures =
{
	{ 2, 2, { 1, 1,
			  1, 1 } }, //Squape
	{ 1, 4, { 1,
			  1,
			  1,
			  1 } }, //Line
	{ 3, 2, { 0, 1, 0,
			  1, 1, 1 } }, //T
	{ 2, 3, { 0, 1,
			  0, 1,
			  1, 1 } }, //LLeft
	{ 2, 3, { 1, 0,
			  1, 0,
			  1, 1 } }, //LRright
	{ 2, 3, { 0, 1,
			  1, 1,
			  1, 0 } }, //SLeft
	{ 2, 3, { 1, 0,
			  1, 1,
			  0, 1 } }, //SRight
};

Shape::Shape()
	: Rectangle()
{
}

Shape::Shape(const Rectangle& other)
	: Rectangle(other)
{
}

Shape::Shape(ShapeType shapeType)
	: Rectangle(figures[shapeType].width, figures[shapeType].height, figures[shapeType].data)
{
}


