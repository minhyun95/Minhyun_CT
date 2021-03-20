#include <algorithm>
#include <iostream>

using namespace std;
void bfs(int x, bool(*line)[101], int* visit)
{
	for (int i = 1; i < 101; ++i)
	{
		if (line[x][i] == true && visit[i] == 0)
		{
			line[x][i] = false;
			if (i != 1)
				visit[i] = 1;
			bfs(i, line, visit);
		}
	}
}

int main()
{
	/*
	백준 2606번
	바이러스
	https://www.acmicpc.net/problem/2606


	입력 예시
	7
	6
	1 2
	2 3
	1 5
	5 2
	5 6
	4 7
	*/
	int iCom = 0, iNet = 0;
	bool iLine[101][101] = {};
	int iVisit[101] = {};

	cin >> iCom >> iNet;

	int a, b;
	for (int i = 0; i < iNet; ++i)
	{
		cin >> a >> b;
		iLine[a][b] = true;
		iLine[b][a] = true;
	}

	bfs(1, iLine, iVisit);

	int sum = 0;
	for (int i = 1; i < 101; i++)
	{
		if (iVisit[i] == 1)
			sum += 1;
	}
	cout << sum;
	return 0;
}