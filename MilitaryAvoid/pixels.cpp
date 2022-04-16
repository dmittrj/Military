#include "pixels.h"
#include "MilitaryAvoid.h"
#include <iostream>


city::city(std::string t_name, int x, int y) {
	name = t_name;
	Point t_point(x, y);
	coord = t_point;
	can_visit = true;
}