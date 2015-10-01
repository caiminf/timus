#include <iostream>
using namespace std;

int main()
{
	int num[26];
	num[0] = 1;
	num[15] = 1;
	num[14] = 1;
	num[17] = 1;
	num[1] = 2;
	num[12] = 2;
	num[18] = 2;
	num[3] = 3;
	num[6] = 3;
	num[9] = 3;
	num[10] = 3;
	num[19] = 3;
	num[22] = 3;
	int n;
	cin >> n;
	int pos = 1;
	int step = 0;
	while (n--){
		char name[10];
		cin >> name;
		int newPos = num[name[0] - 'A'];
		int move = newPos > pos ? (newPos - pos) : (pos - newPos);
		step += move;
		pos = newPos;
	}
	cout << step << endl;
	return 0;
}