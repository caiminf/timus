#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int big, small;
	if (num < 1){
		small = num;
		big = 1;
	}
	else{
		small = 1;
		big = num;
	}
	int sum = 0;
	for (int i = small; i <= big; i++){
		sum += i;
	}
	cout << sum << endl;
	return 0;
}