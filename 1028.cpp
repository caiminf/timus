#include <cstdio>
using namespace std;

const int MAX = 32005;
int tree[MAX] = { 0 };
int level[MAX] = { 0 };

void update(int i, int num)
{
	while (i <= MAX){
		tree[i] += num;
		i += (i&-i);
	}
}

int sum(int i)
{
	int ans = 0;
	while (i > 0){
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x++;
		level[sum(x)]++;
		update(x, 1);
	}
	for (int i = 0; i < n; i++){
		printf("%d\n", level[i]);
	}
	return 0;
}