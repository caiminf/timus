#include <iostream>
using namespace std;

int max(int a, int b){ return a > b ? a : b; }

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	int *w = new int[n + 1];
	for (int i = 1; i <= n; i++){
		cin >> w[i];
		sum += w[i];
	}
	int cap = sum / 2;
	int *dp = new int[cap + 1];
	memset(dp, 0, sizeof(int) * (cap + 1));	
	for (int i = 1; i <= n; i++){
		for (int j = cap; j >= w[i]; j--){
			dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
		}
	}
	cout << sum - 2 * dp[cap] << endl;
	return 0;
}