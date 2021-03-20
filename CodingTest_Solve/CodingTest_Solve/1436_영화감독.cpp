#include <iostream>
#include <string>
using namespace std;

int main()
{
	/*
	백준 1436번
	https://www.acmicpc.net/problem/1436
	링크
	*/

	int N;
	cin >> N;
	string str;
	int num = 665;
	while (N > 0)
	{
		str = to_string(num);
		num += 1;
		for (int i = 0; i < str.length() - 2; i++)
		{
			if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6')
			{
				N -= 1;
				break;
			}
		}
	}

	cout << num - 1 << endl;
	return 0;
}