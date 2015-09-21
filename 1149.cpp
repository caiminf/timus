#include <iostream>
#include <string>
using namespace std;

string getAn(int n);
string getSn(int n);
string getStrNum(int n);

int main()
{
	int n;
	cin >> n;
	cout << getSn(n) << endl;
	return 0;
}

string getAn(int n)
{
	if (n == 1)
		return "sin(1)";
	else{
		string pre = getAn(n - 1);
		string newStr = "sin(";
		newStr = (n % 2 == 0 ? "-" : "+") + newStr + getStrNum(n) + ')';
		return pre.insert(pre.length() - n + 1, newStr);
	}
}

string getSn(int n)
{
	string result = "";
	for (int j = 1; j < n; j++){
		result += '(';
	}
	for (int i = 1; i <= n; i++){
		result += getAn(i);
		result += '+';
		result += getStrNum(n - i + 1);
		if (i != n)
			result += ')';
	}
	return result;
}

string getStrNum(int n)
{
	string result = "";
	while (n){
		result = char(n % 10 + '0') + result;
		n /= 10;
	}
	return result;
}