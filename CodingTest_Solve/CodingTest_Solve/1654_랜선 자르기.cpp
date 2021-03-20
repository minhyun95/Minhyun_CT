#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Set(vector<long long> _v, int mid, int _n)
{
	int cnt = 0;
	for (long long i = 0; i < _v.size(); i++)
	{
		cnt += _v[i] / mid;
	}

	if (cnt >= _n)
		return true;
	else
		return false;
}

int N; // 필요한 랜선의 개수
int main()
{
	/*
	백준 1654번
	https://www.acmicpc.net/problem/1654
	링크
	*/

	int K; // 가진 랜선의 개수
	cin >> K >> N;
	vector<long long> v;
	for (int i = 0; i < K; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	// 오름차순 정렬
	sort(v.begin(), v.end());
	// Reverse 내림차순

	long long low = 1;
	long long high = v.back();
	long long ans = 0;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		if (Set(v, mid, N))
		{
			if (ans < mid)
				ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout << ans << endl;
	return 0;
}