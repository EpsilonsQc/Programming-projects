// Calculate's the distance between points.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2);

int main()
{
	double x1 = 0.0;
	double y1 = 0.0;
	double x2 = 0.0;
	double y2 = 0.0;

	cout << ":: CALCULATES THE DISTANCE BETWEEN POINTS ::" << endl << endl;

	cout << "POINT 1 (COORDINATE x1, y1)" << endl << "Please enter the coordinate of x1: ";
	cin >> x1;
	cout << "Please enter the coordinate of y1: ";
	cin >> y1;
	cout << endl;

	cout << "POINT 2 (COORDINATE x2, y2)" << endl << "Please enter the coordinate of x2: ";
	cin >> x2;
	cout << "Please enter the coordinate of y2: ";
	cin >> y2;
	cout << endl;

	cout << fixed << setprecision(2) << "The distance between those two points is: " << distance(x1, y1, x2, y2) << endl << endl;

	system("pause");

	return 0;
}

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}