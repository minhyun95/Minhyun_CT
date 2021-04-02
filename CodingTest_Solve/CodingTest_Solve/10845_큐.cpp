#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/10845
	링크
	*/

	int N;
	queue<int> q;
	queue<int> answer;
	cin >> N;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (str == "pop")
		{
			if (q.empty())
			{
				num = -1;
			}
			else
			{
				num = q.front();
				q.pop();
			}
			answer.push(num);
		}
		else if (str == "size")
		{
			answer.push(q.size());
		}
		else if (str == "front")
		{
			if (q.empty())
			{
				answer.push(-1);
			}
			else
			{
				answer.push(q.front());
			}
		}
		else if (str == "back")
		{
			if (q.empty())
			{
				answer.push(-1);
			}
			else
			{
				answer.push(q.back());
			}
		}
		else if (str == "empty")
		{
			answer.push(q.empty());
		}
	}

	int iSize = answer.size();
	for (int i = 0; i < iSize; i++)
	{
		int p = answer.front();
		answer.pop();
		printf("%d\n", p);
	}
}