#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define SQRT(p) p * p
int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/4153
	링크
	*/
	int A, B, C;
	vector<string> ans;
	while (true)
	{
		cin >> A >> B >> C;
		if (A == 0 && B == 0 && C == 0)
		{
			break;
		}
		else
		{
			A = SQRT(A);
			B = SQRT(B);
			C = SQRT(C);
			if (A == (B + C))
			{
				ans.push_back("right");
			}
			else if (B == (A + C))
			{
				ans.push_back("right");
			}
			else if (C == (B + A))
			{
				ans.push_back("right");
			}
			else
			{
				ans.push_back("wrong");
			}
		}
	}
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
	return 0;
}