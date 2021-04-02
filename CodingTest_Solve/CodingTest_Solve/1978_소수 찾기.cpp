#include <iostream>
using namespace std;

bool dp[100001] = { true, true, };
int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/
	링크
	*/
	int N;
	int in;
	int count = 0;
	for (int i = 2; i < 100001; i++)
	{
		if (dp[i] == true)
		{
			// 소수가 아님
			continue;
		}
		for (int g = i * 2; g < 100001; g += i)
		{
			if (dp[g] == false)
			{
				dp[g] = true;
			}
		}
	}

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> in;
		if (dp[in] == false)
		{
			cout << "입력: " << in << endl;
			++count;
		}
	}
	cout << count << endl;
	return 0;
}