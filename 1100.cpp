#include <iostream>
#include <algorithm>
using namespace std;

struct Team{
	int id;
	int score;
};

bool compare(Team a, Team b)
{
	return a.score > b.score;
}

int main()
{
	int n;
	cin >> n;
	Team *teams = new Team[n];
	for (int i = 0; i < n; i++){
		cin >> teams[i].id >> teams[i].score;
	}
	stable_sort(teams, teams + n, compare);
	for (int i = 0; i < n; i++){
		cout << teams[i].id << ' ' << teams[i].score << endl;
	}
	return 0;
}