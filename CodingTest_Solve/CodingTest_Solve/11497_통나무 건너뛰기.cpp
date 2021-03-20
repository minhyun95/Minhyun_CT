#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	/*
	백준 11497번
	https://www.acmicpc.net/problem/11497
	링크

	3
	7
	13 10 12 11 10 11 12
	5
	2 4 5 7 9
	8
	6 6 6 6 6 6 6 6

	1
	4
	0
	*/
	int T;

	cin >> T;

	int N[10001];
	vector<priority_queue<int>> Li;
	vector<int> Test;
	for (int i = 0; i < T; i++)
	{
		cin >> N[i];
		for (int y = 0; y < N[i]; y++)
		{
			int num = 0;
			cin >> num;
			Li[i].push(num);
		}
	}

	for (int i = 0; i < T; i++)
	{
		Test.resize(Li[i].size(), 0);

	}

	return 0;
}