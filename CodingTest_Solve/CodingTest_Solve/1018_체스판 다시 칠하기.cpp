#include <iostream>
#include <string>
using namespace std;
string WB[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};
string BW[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};


int Setint(string _str[], int n, int m, int _wb)
{
	int count = 0;
	for (int i = n; i < n + 8; i++)
	{
		for (int j = m; j < m + 8; j++)
		{
			if (_wb == 0)
			{
				if (_str[i][j] != WB[i - n][j - m])
				{
					count++;
				}
			}
			else if (_wb == 1)
			{
				if (_str[i][j] != BW[i - n][j - m])
				{
					count++;
				}
			}
		}
	}
	return count;
}

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/1018
	링크
	*/

	int N, M;
	cin >> N >> M;
	string str[51];
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}

	int ans = 1000000;
	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			int num1 = Setint(str, i, j, 0);
			int num2 = Setint(str, i, j, 1);
			ans = ans > num1 ? num1 : ans;
			ans = ans > num2 ? num2 : ans;
		}
	}

	cout << ans - 1 << endl;
	return 0;
}