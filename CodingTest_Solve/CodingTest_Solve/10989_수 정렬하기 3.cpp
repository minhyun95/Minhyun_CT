#include <iostream>
using namespace std;


int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/10989
	링크
	*/

	int N = 0;
	cin >> (N);
	int Arr[10002] = {};

	for (int i = 0; i < N; i++)
	{
		int in = 0;
		cin >> in;
		Arr[in] += 1;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < Arr[i]; j++)
		{
			printf("%d", i);
		}
	}
	return 0;
}