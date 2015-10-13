#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main ()
{
	string str;
	cin >> str;
	int len = str.length ();
	stack<char> s;
	for (int i = 0; i < len; i++)
	{
		if (s.empty ())
			s.push (str[i]);
		else if (s.top () == str[i])
			s.pop ();
		else
			s.push (str[i]);
	}
	int size = s.size ();
	char *c = new char[size];
	for (int i = 0; i < size; i++)
	{
		c[i] = s.top ();
		s.pop ();
	}
	for (int i = 0; i < size; i++)
		cout << c[size - i - 1];
	cout << endl;
	return 0;	
}