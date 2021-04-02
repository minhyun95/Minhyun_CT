#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int I[6] = {};
bool Remote[10] = { true,true,true,true, true,true, true,true, true,true };
int N, M;


int main()
{
	/*
	백준 1107번
	https://www.acmicpc.net/problem/1107
	링크
	*/

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		char Broke;
		cin >> Broke;
		Remote[Broke - '0'] = false;
	}

	// 버튼으로만 이동했을때의 거리
	int Minimum = abs(100 - N);

	// 모든 버튼이 금지면 차이만큼 이동필요
	if (M == 10)
	{
		cout << Minimum << endl;
	}
	else
	{
		for (int i = 0; i <= 1000000; i++)
		{
			bool Can = true;
			string str = to_string(i);
			for (int i = 0; i < str.length(); i++)
			{
				if (Remote[(int)str[i] - 48] == false)
				{
					Can = false;
				}
			}

			if (Can)
			{
				int newMin = to_string(i).length() + abs(N - i);
				Minimum = min(Minimum, newMin);
			}
		}

		cout << Minimum << endl;
	}


	

	return 0;
}