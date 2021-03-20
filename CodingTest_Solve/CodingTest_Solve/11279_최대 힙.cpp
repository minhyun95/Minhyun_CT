#include <iostream>
#include <queue>
using namespace std;

int main()
{
	/*
	백준 11279번
	https://www.acmicpc.net/problem/11279
	링크

	입력
	첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
	만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고,
	x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
	입력되는 자연수는 231보다 작다.
	13
	0
	1
	2
	0
	0
	3
	2
	1
	0
	0
	0
	0
	0
	출력
	입력에서 0이 주어진 회수만큼 답을 출력한다.
	만약 배열이 비어 있는 경우인데 가장 큰 값을 출력하라고 한 경우에는 0을 출력하면 된다.
	0
	2
	1
	3
	2
	1
	0
	0
	*/
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int> pq;
	queue<int> out;
	for (int i = 0; i < N; i++)
	{
		int Input;
		cin >> Input;
		if (Input == 0)
		{
			if (pq.size() == 0)
			{
				out.push(0);
			}
			else
			{
				out.push(pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(Input);
		}
	}

	while (out.size() != 0)
	{
		cout << out.front() << "\n";
		out.pop();
	}

	return 0;
}