#include <iostream>

using namespace std;

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/2869
	링크
	*/
	int  A, B, V;
	cin >> A >> B >> V;

	int Day = A - B;
	int LastDay = V - A;
	if (LastDay <= 0)
	{
		cout << 1 << endl;
	}
	else
	{
		int answer = 1;
		if (LastDay % Day == 0)
		{
			answer += LastDay / Day;
		}
		else
		{
			answer += (LastDay / Day) + 1;
		}
		cout << answer << endl;
	}

	return 0;
}