#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string marks;
	cin >> n >> marks;
	int len = marks.length();
	long result = 1;
	for (int i = n; i > 0; i -= len){
		result *= i;
	}
	cout << result << endl;
	return 0;
}