#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/10250
	링크
	*/
	int T;
	cin >> T;
	vector<int> ans;
	for (int i = 0; i < T; i++)
	{
		int H, W, N;
		cin >> H >> W >> N;

		int iFloor = ((N - 1) % H) + 1;
		int iRoom = ((N - 1) / H) + 1;

		iFloor *= 100;
		ans.push_back(iFloor + iRoom);
	}

	for (int i = 0; i < T; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}