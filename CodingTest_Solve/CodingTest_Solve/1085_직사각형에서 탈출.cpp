#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/1085
	링크
	*/

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int a[4] = { 0,0, w,w };
	int b[4] = { h,0, h,0 };

	int dist = 10000;
	for (int i = 0; i < 4; i++)
	{
		int getDistx = abs(a[i] - x);
		int getDisty = abs(b[i] - y);

		getDistx = getDistx < getDisty ? getDistx : getDisty;
		if (dist > getDistx)
			dist = getDistx;
	}

	cout << dist;
	return 0;
}