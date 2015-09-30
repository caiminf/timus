#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string pos;
		cin >> pos;
		int digit[2];
		if (pos[0] <= 'd')
			digit[0] = pos[0] - 'a' + 1;
		else
			digit[0] = 'h' + 1 - pos[0];
		if (pos[1] <= '4')
			digit[1] = pos[1] - '0';
		else
			digit[1] = '9' - pos[1];
		if (digit[0] + digit[1] <= 3)
			cout << digit[0] + digit[1] << endl;
		else if (digit[0] + digit[1] == 4 || (digit[0] + digit[1] == 5 && (digit[0] == 1 || digit[1] == 1)))
			cout << 4 << endl;
		else if (digit[0] + digit[1] == 5 || (digit[0] + digit[1] == 6 && (digit[0] == 2 || digit[1] == 2)))
			cout << 6 << endl;
		else
			cout << 8 << endl;
	}
	return 0;
}