#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/1874
	링크
	*/

	int N;
	cin >> N;
	string res = "";
	stack<int> s;
	int iFindNum = 1;
	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> iFindNum;
		if (iFindNum >= cnt)
		{
			while (iFindNum + 1 != cnt)
			{
				s.push(cnt);
				cnt++;
				res += "+\n";
			}
			cout << "pop : "<< s.top() << endl;
			s.pop();
			res += "-\n";
		}
		else
		{
			if (s.top() == iFindNum)
			{
				cout << "pop : " << s.top() << endl;
				s.pop();
				res += "-\n";
				cnt++;
			}
			else
			{
				res = "NO";
				break;
			}
		}
	}

	cout << s.top() << endl;
	cout << res << endl;
	return 0;
}