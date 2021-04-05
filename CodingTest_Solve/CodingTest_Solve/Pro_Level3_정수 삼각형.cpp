#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle);
int main()
{
	/*
	https://programmers.co.kr/learn/courses/30/lessons/43105
	링크
	*/

	vector<vector<int>> v = { {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };
	cout << solution(v) << endl;

	return 0;
}


int solution(vector<vector<int>> triangle) {

	// DP vector 생성
	vector<vector<int>> vec;

	// 층의 크기 구하기
	int triSize = triangle.size();

	// DP 각 층 크기 복사
	vec.resize(triSize);
	for (int i = 0; i < triSize; i++)
	{
		vec[i].resize(triangle[i].size());
	}

	// 1층의 가장 큰 수
	vec[0][0] = triangle[0][0];

	/*
	2층의 가장 큰 수 (이해를 위한)
	vec[1][0] = triangle[1][0] + vec[0][0];
	vec[1][1] = triangle[1][1] + vec[0][0];
	*/

	for (int i = 1; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			// 0번째 원소일 경우 받을 수 있는 값이 1개이므로 고정
			if (j == 0)
			{
				vec[i][0] = triangle[i][0] + vec[i - 1][0];
			}

			// 마지막 원소일 경우 받을 수 있는 값이 1개이므로 고정
			else if (j == vec[i].size() - 1)
			{
				vec[i][j] = triangle[i][j] + vec[i - 1][j - 1];
			}

			// 받을 수 있는 값 두개를 비교해서 더 큰 값
			else
			{
				// 더 큰 값을 저장한다
				int temp = vec[i - 1][j - 1] > vec[i - 1][j] ? vec[i - 1][j - 1] : vec[i - 1][j];
				vec[i][j] = triangle[i][j] + temp;
			}
		}
	}

	/*
	출력 테스트용
	for (int i = 0; i < vec.size(); i++)
	{
		cout << i << "층" << endl;
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << endl;
		}
	}
	*/

	// 마지막 층을 정렬 후 반전한 뒤 return
	sort(vec[triSize - 1].begin(), vec[triSize - 1].end());
	reverse(vec[triSize - 1].begin(), vec[triSize - 1].end());
	


	return vec[triSize - 1][0];
}