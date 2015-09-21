#include <iostream>
using namespace std;
const int len = 200000;

int main()
{
	bool prime[len];
	for (int i = 0; i < len; i++){
		prime[i] = true;
	}
	prime[0] = prime[1] = prime[2] = true;
	for (int i = 2; i < len;){
		for (int j = i + i; j < len; j += i){
			prime[j] = false;
		}
		do{
			i++;
		} while (!prime[i]);
	}
	int n;
	cin >> n;
	while (n--){
		int index;
		cin >> index;
		int count = 0;
		int i;
		for (i = 2; i < len; i++){
			if (prime[i]){
				count++;
				if (count == index)break;
			}
		}
		cout << i << endl;
	}
	return 0;
}