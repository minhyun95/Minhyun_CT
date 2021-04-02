#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/
	링크
	*/

	vector<string> v;

	v.push_back("z");
	v.push_back("a");
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}


	return 0;
}