#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/10828
	링크
	*/
	
	int N;
	cin >> N;
	stack<int> S;
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		int size = str.length();

		// push
		if (str == "push")
		{
			int num;
			cin >> num;
			S.push(num);
		}
		else if (str == "pop")
		{
			if (S.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << S.top() << endl;
				S.pop();
			}
		}
		else if (str == "size")
		{
			cout << S.size() << endl;
		}
		else if (str == "empty")
		{
			cout << S.empty() << endl;
		}
		else if (str == "top")
		{
			if (S.empty())
				cout << "-1" << endl;
			else
			{
				cout << S.top() << endl;
			}
		}
	}
	return 0;
}