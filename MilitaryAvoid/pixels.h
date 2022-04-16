#pragma once

#ifndef PIXELS_H
#define PIXELS_H
#include <iostream>
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
#define NUMBEROFTOWNS 2;

	static Point** workspace = new Point*;
	static float ratio_x;
	static float ratio_y;

	//class city;
	class city {
	public:
		std::string name;
		Point coord;
		bool can_visit;

		city(std::string t_name, int x, int y);
	};
#endif // !PIXELS_H
