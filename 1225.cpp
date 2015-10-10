#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n == 1 || n == 2)
		cout << 2 << endl;
	else
	{
		long long num1= 2, num2= 2, temp;
		while(n-- > 2){
			temp = num2;
			num2 += num1;
			num1 = temp;
		}
		cout << num2 << endl;
	}
	return 0;
}