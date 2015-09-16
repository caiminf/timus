#include <iostream>
#include <vector>
using namespace std;

vector<int> getFactors(int n);

int main()
{
	int n;
	cin >> n;
	vector<int> factors = getFactors(n);
	for (vector<int>::reverse_iterator rit = factors.rbegin(); rit != factors.rend(); ++rit){
		cout << *rit;
	}
	cout << endl;
	return 0;
}

vector<int> getFactors(int n)
{
	vector<int> factors;
	if (n == 0){
		factors.push_back(10);
		return factors;
	}
	else if (n == 1){
		factors.push_back(1);
		return factors;
	}
	int f = 9;
	while (f > 1){
		if (n%f == 0){
			factors.push_back(f);
			n /= f;
		}
		else{
			f--;
		}
	}
	if (n != 1){
		factors.clear();
		factors.push_back(-1);
	}
	return factors;
}