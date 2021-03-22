#include <iostream>

using namespace std;

int N;
int L;
int W;
int H;
double ans = 0;

void Search(double start, double end)
{
	if (start > end)
		return;
	double mid = (start + end) / 2;
	if (mid <= 0)
		return;
	double num = (long long)(L / mid) * (long long)(W / mid) * (long long)(H / mid);
	if (num >= N)
	{
		ans = mid > ans ? mid : ans;
		return Search(mid + 1, end);
	}
	else
	{
		return Search(start, mid - 1);
	}
}

int main()
{
	/*
	백준 1166번
	https://www.acmicpc.net/problem/1166
	링크
	*/

	cin >> N >> L >> W >> H;

	Search(0, 1000000000);

	printf("%.10lf", ans);
	return 0;
}