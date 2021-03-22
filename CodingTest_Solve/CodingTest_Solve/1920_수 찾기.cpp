#include <iostream>
#include <vector>
using namespace std;


void SortQuick(vector<int>& arr, int start, int end)
{
	if (start >= end)
		return;

	int pivot = arr[(start + end) / 2];
	int left = start;
	int right = end;

	while (left <= right)
	{
		while (arr[left] < pivot) ++left;
		while (arr[right] > pivot) --right;

		if (left <= right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			++left;
			--right;
		}
	}


	SortQuick(arr, start, right);
	SortQuick(arr, left, end);
}

int QuickFind(vector<int> arr, int start, int end, int find)
{
	if (start > end)
		return 0;

	int mid = (start + end) / 2;
	if (find == arr[mid])
		return 1;
	else if (find > arr[mid])
		return QuickFind(arr, mid + 1, end, find);
	else if(find < arr[mid])
		return QuickFind(arr, start, mid - 1, find);
}

int main()
{
	/*
	백준 번
	https://www.acmicpc.net/problem/1920
	링크
	*/

	int N;
	int M;
	vector<int> ArrN;
	vector<int> ArrM;
	vector<int> ans;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input = 0;
		cin >> input;
		ArrN.push_back(input);
	}
	SortQuick(ArrN, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		ans.push_back(QuickFind(ArrN, 0, N - 1, n));
	}

	for (int i = 0; i < M; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}