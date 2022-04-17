#include "pixels.h"
#include "MilitaryAvoid.h"
#include <iostream>


city::city(std::string t_name, std::string t_neighbours, int x, int y) {
	name = t_name;
	Point t_point(x, y);
	coord = t_point;
	can_visit = true;
	you_are_here = false;
	radius = 7;
	for (int i = 0; i < 6; i++)
	{
		neighbours[i] = -1;
	}
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

voenkomat::voenkomat(int t_city_number) {
	city_number = t_city_number;
	visible = true;
	intellect = 1;
}

int voenkomat::go(int depth, int* t_weights) {
	int weights[6] = { 0 };
	if (depth <= 0) return 0;
	for (int i = 0; i < 6; i++)
	{
		city* tmp = MilitaryAvoid::MilitaryAvoidForm::cities[this->city_number];
		if (tmp->neighbours[i] != -1) {
			if (tmp->you_are_here) {
				weights[i]++;
			}
			int new_weights[6] = { 0 };
			this->go(depth - 1, new_weights);
			for (int j = 0; j < 6; j++)
			{
				weights[j] += new_weights[j];
			}
		}
	}
	int max_num = 0;
	int max_value = weights[0];
	for (int i = 1; i < 6; i++)
	{
		if (weights[i] > max_value) {
			max_value = weights[i];
			max_num = i;
		}
	}
	this->intellect++;
	return MilitaryAvoid::MilitaryAvoidForm::cities[this->city_number]->neighbours[max_num];
}