#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool Compared(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/1181
	링크
	*/

	int N;
	cin >> N;
	vector<string> v;
	string get = "";
	for (int i = 0; i < N; i++)
	{
		cin >> get;
		v.push_back(get);
	}
	sort(v.begin(), v.end(), Compared);

	vector<string>::iterator iter;
	vector<string>::iterator iterEnd;
	iterEnd = unique(v.begin(), v.end());

	for (iter = v.begin(); iter != iterEnd; ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}