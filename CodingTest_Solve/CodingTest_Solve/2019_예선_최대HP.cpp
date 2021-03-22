#include <iostream>

using namespace std;

int main()
{
	/*
	https://nypc.github.io/2019/2019_online_3.html
	링크
	*/

	int iHealth, T;
	cin >> iHealth >> T;
	int a, h;
	int MaxHealth = 0;
	// 1 체력깍임 2 체력 회복 3 풀피
	for (int i = 0; i < T; i++)
	{
		cin >> a >> h;
		if (a == 1)
		{
			iHealth -= h;
		}
		else if (a == 2)
		{
			iHealth += h;
		}
		else if (a == 3)
		{
			iHealth += h;
			MaxHealth = iHealth;
		}
	}

	cout << MaxHealth << endl;
	return 0;
}