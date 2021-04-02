#include <iostream>
#include <queue>
using namespace std;

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/11866
	링크
	*/
	int N, K;
	cin >> N >> K;

	queue<int> q;
	for (int i = 1; i <= N; ++i) { q.push(i); }

	int Count = 0;
	cout << "<";
	while (q.size() > 1)
	{
		++Count;
		if (Count % K == 0)
		{
			int out = q.front();
			q.pop();
			cout << out << ", ";
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
	}
	cout << q.front();
	cout << ">";
	return 0;
}