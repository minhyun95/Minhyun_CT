#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/1259
	링크
	*/

	vector<string> v;
	string input = "";

	while (input != "0")
	{
		cin >> input;
		if (input != "0")
			v.push_back(input);
	}

	for (int i = 0; i < v.size(); i++)
	{
		bool isPalindrome = true;
		for (int j = 0; j < v[i].length() / 2; j++)
		{
			if (v[i][j] != v[i][v[i].length() - 1 - j])
			{
				isPalindrome = false;
				break;
			}
		}
		if (isPalindrome)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}