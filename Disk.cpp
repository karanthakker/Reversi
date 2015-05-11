#include "stdafx.h"
#include <iostream>


class Disk
{
	Color color;
public:
	Disk(){ }
	Disk(Color c)
	{
		color = c;
	};

public: void flip() {
	if (color == Color::black) {
		color = Color::white;
	}
	else {
		color = Color::black;
	}
}
	Color getColor() {
		return color;
	};

};

