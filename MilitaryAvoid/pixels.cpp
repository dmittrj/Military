#include "pixels.h"
#include "MilitaryAvoid.h"
#include <iostream>


city::city(std::string t_name, std::string t_neighbours, int x, int y) {
	name = t_name;
	Point t_point(x, y);
	coord = t_point;
	can_visit = true;
	you_are_here = true;
	radius = 7;
	parse(t_neighbours, neighbours);
}

void city::parse(std::string str_to_parse, int* arr) {
	std::string tmp = "";
	int j = 0;
	for (int i = 0; i < str_to_parse.length(); i++)
	{
		if (str_to_parse[i] == ',') {
			arr[j++] = parse_int(tmp);
			tmp = "";
		}
		else {
			tmp += str_to_parse[i];
		}
	}
}

int city::parse_int(std::string str_to_parse) {
	int len = str_to_parse.length();
	int number = 0;
	for (int i = 0; i < len; i++)
	{
		number += (str_to_parse[i] - 48) * pow(10, len - i - 1);
	}
	return number;
}

bool city::can_be_reached(int city_num) {
	for (int i = 0; i < 6; i++)
	{
		if (neighbours[i] == city_num) {
			return true;
		}
	}
	return false;
}