#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dp[60001] = {};

long long pibo(int n)
{
	if (n < 3)
	{
		return dp[n];
	}

	if (dp[n] != 0)
	{
		return dp[n];
	}
	return dp[n] = (pibo(n - 1) + pibo(n - 2)) % 1000000007;
}

int solution(int n) {
	int answer = 0;

	dp[1] = 1;
	dp[2] = 2;
	pibo(n);
	answer = dp[n];
	return answer;
}
int main()
{
	/*
	프로그래머스 Level 2
	https://programmers.co.kr/learn/courses/30/lessons/12900
	링크
	*/

	int N;
	cin >> N;
	cout << solution(N) << endl;


	/* 테스트
	for (int i = 0; i < 5000; i++)
	{
		printf("%d\n", dp[i]);
	}*/
	return 0;
}