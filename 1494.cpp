#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	stack<int> st;
	int ball = 1;
	for (int i = 0; i < n; i++){
		int current;
		scanf("%d", &current);
		while (st.empty() || (st.top() != current && ball <= n)){
			st.push(ball);
			ball++;
		}
		if(!st.empty() && st.top() == current)
			st.pop();
	}
	if (st.empty())
		printf("Not a proof\n");
	else
		printf("Cheater\n");
	return 0;
}