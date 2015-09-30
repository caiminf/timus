#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--){
		double num;
		cin >> num;
		double root = sqrt(num * 8 - 7);
		if (double(int(root)) == root && int(root) % 2 == 1)
			cout << 1;
		else
			cout << 0;
		if (n != 0)
			cout << ' ';
		else
			cout << endl;
	}
	return 0;
}