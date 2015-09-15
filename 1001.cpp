#include <iostream>
#include <cmath>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	stack<double> num;
	double temp;
	int count = 0;
	while(cin >> temp){
		num.push(sqrt(temp));
		count++;
	}
	while(!num.empty())
	{
		printf("%.4lf\n", num.top());
		num.pop();
	}
	return 0;
}
