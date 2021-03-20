#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	/*
	백준 20921번
	https://www.acmicpc.net/problem/20921
	링크
	*/

	int Narr[4243] = {};
	int N, K;
	// 2~4242,   0~N(N-1)/2
	cin >> N >> K;

	int EN = 0;
	int Start = 0;
	EN = N - 1;
	while (K > 0)
	{
		if (K > EN)
		{
			Narr[Start] = EN + 1;
			K -= EN;
			Start += 1;
			EN -= 1;
		}
		else
		{
			Narr[N - 1 - K] = EN + 1;
			K = 0;
			Start += 1;
		}
	}

	int ans = 1;
	for (int i = 0; i < N; i++)
	{
		if (Narr[i] == 0)
		{
			Narr[i] = ans;
			ans++;
		}
	}

	cout << "-- 결과 --" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << Narr[i] << '\t';
	}

	return 0;
}