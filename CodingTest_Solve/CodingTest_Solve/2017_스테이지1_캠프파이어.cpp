#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool SetFire(int numx, int numy, vector<vector<int>> _pos, int iSize)
{

	bool Check = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// 범위 벗어나지않게.
			if (numx - i >= 0 && numy - j >= 0 && numx + i < iSize && numy + j < iSize)
			{
				// 직선거리 5이하
				if ((i * i) + (j * j) < 25 && i + j < 8)
				{
					if (_pos[i][j] > 0)
					{
						Check = false;
						break;
					}
				}
			}
		}

		if (!Check)
			break;
	}

	if (Check)
	{
		_pos[numx][numy] = 300;
	}

	return Check;
}

typedef struct xy
{
	int x = 0, y = 0;
};
int main()
{
	/*
	https://nypc.github.io/2017/2017_online_1-2.html
	링크
	*/

	int N;
	int t[10001], x[10001], y[10001];
	vector<bool> bInstall;
	vector<vector<int>> Pos;
	queue<pair<int, xy>> setFires;
	xy _Xy;
	// 입력 구간.
	cin >> N;
	Pos.resize(6001, vector<int>(6001, 0));
	for (int i = 0; i < N; i++)
	{
		int _t, _x, _y;
		cin >> _t >> _x >> _y;
		t[i] = _t;
		x[i] = _x;
		y[i] = _y;
	}
	int nowTime = 0;
	for (int i = 0; i < N; i++)
	{
		int beforetime = nowTime;
		nowTime = t[i];
		if (SetFire(x[i] + 3000, y[i] + 3000, Pos, 6001))
		{
			cout << "S_OK" << endl;
			_Xy.x = x[i] + 3000;
			_Xy.y = y[i] + 3000;
			setFires.push(make_pair(300, _Xy));
		}
		else
			cout << "E_FAILED" << endl;
	}


	return 0;
}