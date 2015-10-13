#include <cstdio>
using namespace std;

int groups = 0;
const int MAX = 100050;
int start[MAX];
int end[MAX];
bool erase[MAX];
int pre[MAX];
int rankage[MAX];
int answer[MAX];
int ind[MAX];

void init(int N);
int findRoot(int x);
void joint(int x, int y);

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++){
		scanf("%d %d", &start[i], &end[i]);
		erase[i] = false;
	}
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++){
		int index;
		scanf("%d", &index);
		ind[i] = index;
		erase[index] = true;
	}
	
	init(N);
	for (int i = 1; i <= M; i++){
		if (!erase[i]){
			joint(start[i], end[i]);
		}
	}
	for (int i = 0; i < Q; i++){
		answer[i] = groups;
		joint(start[ind[Q - 1 - i]], end[ind[Q - 1 - i]]);
	}
	for (int i = Q - 1; i >= 0; i--){
		if (i == 0){
			printf("%d\n", answer[i]);
		}
		else{
			printf("%d ", answer[i]);
		}
	}
	return 0;
}

void init(int N)
{
	for (int i = 0; i <= N; i++){
		pre[i] = i;
		rankage[i] = 0;
	}
	groups = N;
}

int findRoot(int x)
{
	if (pre[x] == x)
		return x;
	pre[x] = findRoot(pre[x]);
	return pre[x];
}

void joint(int x, int y)
{
	int xRoot = findRoot(x),
		yRoot = findRoot(y);
	if (xRoot != yRoot){
		groups--;
		if (rankage[xRoot] < rankage[yRoot]){
			pre[xRoot] = yRoot;
		}
		else{
			pre[yRoot] = xRoot;
			if (rankage[xRoot] == rankage[yRoot])
				rankage[xRoot]++;
		}
	}
}