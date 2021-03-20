#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> chonsu;
vector<bool> visit;
vector<int> chon;
void bfs(int x, int stack)
{
	visit[x] = true;
	chon[x] = stack;
	while (!chonsu[x].empty())
	{
		int num = chonsu[x].back();
		chonsu[x].pop_back();
		if (!visit[num])
		{
			bfs(num, stack + 1);
		}
	}
}
int main()
{
	/*
	백준 2644번
	촌수계산
	https://www.acmicpc.net/problem/2644

	입력
	9
	7 3
	7
	1 2
	1 3
	2 7
	2 8
	2 9
	4 5
	4 6

	출력
	3
	*/
	int N = 0;
	int iOne, iTwo;
	int m = 0;
	int parent = 0, child = 0;
	cin >> N;
	cin >> iOne >> iTwo;
	cin >> m;
	chonsu.resize(N + 1);
	visit.resize(N + 1, false);
	chon.resize(N + 1, 0);
	for (int i = 0; i < m; ++i)
	{
		cin >> parent >> child;
		chonsu[parent].push_back(child);
		chonsu[child].push_back(parent);
	}

	bfs(iOne, 0);

	if (visit[iTwo])
		cout << chon[iTwo] << endl;
	else
		cout << -1 << endl;
	return 0;
}