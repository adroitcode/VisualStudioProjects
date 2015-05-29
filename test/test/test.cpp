#include "stdafx.h"
#include <iostream>
#include <math.h>       

using namespace std;



double my_function(double x){
	//Define math function here
	return 4 + (4 * pow(x, 2));
}



int main()
{

	//# of rectangles 
	int n = 6;

	double start_point = 0;

	double end_point = 36;

	double rectangle_width = (end_point - start_point) / n;

	cout << "rectangle width" << endl;
	cout << rectangle_width << endl;



	double total_area = 0;


	//Loop N times and calculate the area of each rectangle
	for (int x = 0; x < n; x++) {


		//x val of this rectangle
		double rectangle_left = start_point + (x * rectangle_width);





		//Get the y value of the left point
		//double rectangle_height = my_function(rectangle_left);

		//Get the y value of the right point
		//double rectangle_height = my_function(rectangle_left + rectangle_width);

		//get the y value of the middle point
		double rectangle_height = my_function(rectangle_left + (rectangle_width / 2));


		//Calculate the area for this individual rectangle
		double this_rectangle_area = rectangle_width * rectangle_height;

		//Add the area of this rectangle to the total area
		total_area += this_rectangle_area;
	}

	cout << "total area" << endl;
	cout << total_area << endl;

	getchar();
	return 0;
}