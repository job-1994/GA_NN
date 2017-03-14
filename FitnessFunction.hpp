#ifndef FITNESSFUNCTION_HPP
#define FITNESSFUNCTION_HPP
#include <stdio.h>
#include <cstdlib>
#include <math.h>

class FitnessFunction
{
public:
	FitnessFunction();
	~FitnessFunction();
	void return_visited();
	void initialise();
	bool get_visited(double x_coordinate, double z_coordinate, double y_coordinate, double x_coordinate_past, double y_coordinate_past);
private:
	bool visited[11][11];
	//bool check_visited(double x_coordinate, double y_coordinate);
	bool update_location(double x_coordinate, double y_coordinate, double x_coordinate_past, double y_coordinate_past);
};
#endif
