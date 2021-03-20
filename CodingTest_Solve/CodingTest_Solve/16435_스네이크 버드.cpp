#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	/*
	백준 16435번
	https://www.acmicpc.net/problem/16435
	링크
	입력 예제 1
	3 10
	10 11 13
	출력
	12

	입력 예제 2
	9 1
	9 5 8 1 3 2 7 6 4
	출력
	10

	첫 번째 줄에 과일의 개수 N (1 ≤ N ≤ 1,000) 과 스네이크버드의 초기 길이 정수 L (1 ≤ L ≤ 10,000) 이 주어집니다.

	두 번째 줄에는 정수 h1, h2, ..., hN (1 ≤ hi ≤ 10,000) 이 주어집니다.
	*/
	int N, L;
	int Input;
	vector<int> Fruit;

	cin >> N >> L;

	Fruit.resize(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> Input;
		Fruit[i] = Input;
	}

	sort(Fruit.begin(), Fruit.end());

	for (int i = 0; i < N; i++)
	{
		if (L >= Fruit[i])
			L++;
		else
			break;
	}
	cout << "최대 길이 : " << L << endl;

	return 0;
}