#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> as;
int main()
{
	/*
	백준 17509번
	https://www.acmicpc.net/problem/17509
	링크
	*/
	int a, b;

	for (int i = 0; i < 11; ++i)
	{
		cin >> a >> b;
		as.push_back({ a,b });
	}

	sort(as.begin(), as.end());

	int f = 0, s = 0, ans = 0;
	for (int i = 0; i < 11; i++)
	{
		f += as[i].first;
		s = as[i].second;
		ans += f + 20 * s;
	}

	cout << ans;

	return 0;
}