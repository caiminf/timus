#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;
	while (cin >> num && num != 0){
		int *arr = new int[num + 1];
		int max = 0;
		for (int i = 0; i <= num; i++){
			if (i == 0)
				arr[i] = 0;
			else if (i == 1)
				arr[i] = 1;
			else{
				if (i % 2 == 0)
					arr[i] = arr[i / 2];
				else
					arr[i] = arr[i / 2] + arr[i / 2 + 1];
			}
			if (arr[i] > max)
				max = arr[i];
		}
		cout << max << endl;
	}
	return 0;
}