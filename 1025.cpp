#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *num = new int[n];
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	sort(num, num + n);
	int count = 0;
	for (int i = 0; i <= n / 2; i++){
		count += num[i] / 2 + 1;
	}
	cout << count << endl;
	return 0;
}