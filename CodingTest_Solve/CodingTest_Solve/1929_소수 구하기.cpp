#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000001

bool dp[MAX] = {};
int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/1929
	링크

	3 16
	*/


	// 소수 구하기
	// 큰 수부터 나눠서 나눠진다면 모두 소수
	int M, N;
	cin >> M >> N;

	int SetNum = 2;
	while (SetNum < MAX)
	{
		for (int i = 2; i * SetNum < MAX; ++i)
		{
			dp[i * SetNum] = true;
		}
		++SetNum;
	}

	dp[1] = true;
	for (int i = M; i <= N; ++i)
	{
		if (dp[i] == false)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}