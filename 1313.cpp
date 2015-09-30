#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int **img = new int*[n + 1];
	for (int i = 1; i <= n; i++){
		img[i] = new int[n + 1];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> img[i][j];
		}
	}
	for (int i = 2; i <= 2 * n; i++){
		if (i <= n){
			for (int j = 1; j < i; j++)
				cout << img[i - j][j] << ' ';
		}
		else{
			for (int j = i - n; j <= n; j++){
				cout << img[i - j][j];
				if (i == 2 * n)
					cout << endl;
				else
					cout << ' ';
			}
		}
	}
	return 0;
}