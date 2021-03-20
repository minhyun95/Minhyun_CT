#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	/*
	https://nypc.github.io/2017/2017_online_1-1.html
	링크

	입력 예제
	2
	-5 8
	3 4 5
	-4 8
	4 5 1

	출력 예제
	3
	9.28571
	3
	1.3333
	*/

	int T, State = 1;
	vector<float> a, b, x, y, z;
	float atime = 0, btime = 0, Move = 0;

	// 입력 구간
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		float _a, _b, _x, _y, _z;
		cin >> _a >> _b >> _x >> _y >> _z;
		a.push_back(_a);
		b.push_back(_b);
		x.push_back(_x);
		y.push_back(_y);
		z.push_back(_z);
	}

	// 각 계산 출력.
	for (int i = 0; i < T; i++)
	{
		// 열차사이 거리 b - a (무조건 양수) / (x + y) 열차 이동속도 * z 이동속도
		// 열차가 부딪치기전엔 계속 이동하므로 부딪치는데 걸리는 시간 * 파리의 이동속도를 해주면 이동거리 완료.
		Move = (b[i] - a[i]) / (x[i] + y[i]) * z[i];

		// A와 파리가 만나는데 걸리는 시간 -가 나오면 z가 더 큰거라 if문에 들어갈일이 없어서 상관없음.
		atime = a[i] / (x[i] - z[i]);
		// B와 파리가 만나는데 걸리는 시간 -가 나오면 z가 더 큰거라 if문에 들어갈일이 없어서 상관없음.
		btime = b[i] / (y[i] - z[i]);

		// 두 열차보다 빠를 경우 State = 3
		if (z[i] > x[i] && z[i] > y[i])
		{
			State = 3;
		}
		// b보다 느릴 경우 
		// btime이 총 시간보다 짧다면 State = 2
		else if (z[i] <= y[i])
		{
			if ((b[i] - a[i]) / (x[i] + y[i]) > b[i] / (y[i] - z[i]))
				State = 2;
		}

		// b보다 빠르고 a보다 느릴 경우
		// atime이 총 시간보다 짧다면 State = 1
		else if (z[i] > y[i] && z[i] <= x[i])
		{
			if ((b[i] - a[i]) / (x[i] + y[i]) > a[i] / (x[i] - z[i]))
				State = 1;
		}

		// 출력
		cout << State << endl;
		cout << Move << endl;
	}


	return 0;
}