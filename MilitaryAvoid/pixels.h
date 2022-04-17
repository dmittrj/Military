#pragma once

#ifndef PIXELS_H
#define PIXELS_H
#include <iostream>
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	static const int NUMBEROFTOWNS = 22;

	static Point** workspace = new Point*;
	static float ratio_x;
	static float ratio_y;

	//class city;
	class city {
	public:
		std::string name;
		Point coord;
		bool can_visit;
		int neighbours[6];
		bool you_are_here;

		city(std::string t_name, std::string t_neighbours, int x, int y);
		bool can_be_reached(int city_num);
	private:
		void parse(std::string str_to_parse, int* arr);
		int parse_int(std::string str_to_parse);
	};
#endif // !PIXELS_H
