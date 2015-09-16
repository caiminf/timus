#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point
{
private:
	double x;
	double y;
public:
	Point()
	{
		x = 0.0;
		y = 0.0;
	}
	void set(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double distance(Point p)
	{
		return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
	}
};

int main()
{
	const double PI = 3.14159;
	int n;
	double r;
	cin >> n >> r;
	Point *points = new Point[n];
	double distance = 0;
	for (int i = 0; i < n; i++){
		double x, y;
		cin >> x >> y;
		points[i].set(x, y);
		if (i > 0)
			distance += points[i].distance(points[i - 1]);
	}
	distance += points[0].distance(points[n - 1]);
	distance += 2 * PI * r;
	cout << fixed << setprecision(2) << distance << endl;
	return 0;
}