#pragma once

#ifndef PIXELS_H
#define PIXELS_H
#include <iostream>
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	static const int NUMBEROFTOWNS = 22;
	static const int NUMBEROFVOENKOMS = 3;

	static Point** workspace = new Point*;
	static float ratio_x;
	static float ratio_y;
	static int visible_voenkomat = 0;

	//class city;
	class city {
	public:
		std::string name;
		Point coord;
		bool can_visit;
		int neighbours[6];
		int radius;
		bool you_are_here;

		city(std::string t_name, std::string t_neighbours, int x, int y);
		bool can_be_reached(int city_num);
	private:
		void parse(std::string str_to_parse, int* arr);
		int parse_int(std::string str_to_parse);
	};

	class voenkomat {
	public:
		int city_number;
		int intellect;
		bool visible;
		voenkomat(int t_city_number);
		int go(int depth, int* t_weights);
	};
#endif // !PIXELS_H
