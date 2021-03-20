
#include <vector>
#include <iostream>

using namespace std;

int M, N, H;
int Tom[100][100][100];
vector<int> m, n, h;
vector<int> newM, newN, newH;

void dfs(int x, int y, int z, int stack)
{

	Tom[x][y][z] = stack;
	newH.push_back(x);
	newN.push_back(y);
	newM.push_back(z);
}
int main()
{
	/*
	백준 7569번
	https://www.acmicpc.net/problem/7569

	5 3 1
	0 -1 0 0 0
	-1 -1 0 1 1
	0 0 0 1 1

	-1
	링크
	*/
	int num = 0;
	cin >> M >> N >> H;
	bool EveryBodyHit = false;

	for (int a = 0; a < H; ++a)
	{
		for (int b = 0; b < N; ++b)
		{
			for (int c = 0; c < M; ++c)
			{
				cin >> num;
				Tom[a][b][c] = num;
				if (num == 1)
				{
					newH.push_back(a);
					newN.push_back(b);
					newM.push_back(c);
				}
				if (!EveryBodyHit && (num == 0 || num == -1))
				{
					EveryBodyHit = true;
				}
			}
		}
	}
	int day = 1;

	do
	{
		day += 1;
		h = newH;
		n = newN;
		m = newM;
		newH.clear();
		newN.clear();
		newM.clear();
		while (!m.empty())
		{
			int popm, popn, poph;
			poph = h.back(); h.pop_back();
			popn = n.back(); n.pop_back();
			popm = m.back(); m.pop_back();

			if (poph >= 1 && Tom[poph - 1][popn][popm] == 0)
			{
				dfs(poph - 1, popn, popm, day);
			}
			if (poph < H - 1 && Tom[poph + 1][popn][popm] == 0)
			{
				dfs(poph + 1, popn, popm, day);
			}
			if (popn >= 1 && Tom[poph][popn - 1][popm] == 0)
			{
				dfs(poph, popn - 1, popm, day);
			}
			if (popn < N - 1 && Tom[poph][popn + 1][popm] == 0)
			{
				dfs(poph, popn + 1, popm, day);
			}
			if (popm >= 1 && Tom[poph][popn][popm - 1] == 0)
			{
				dfs(poph, popn, popm - 1, day);
			}
			if (popm < M - 1 && Tom[poph][popn][popm + 1] == 0)
			{
				dfs(poph, popn, popm + 1, day);
			}
		}
	} while (!newM.empty());

	bool Check = true;
	for (int a = 0; a < H; ++a)
	{
		for (int b = 0; b < N; ++b)
		{
			for (int c = 0; c < M; ++c)
			{
				if (Tom[a][b][c] == 0)
				{
					Check = false;
					break;
				}
			}
		}
	}
	if (!EveryBodyHit)
		cout << 0;
	else if (Check)
		cout << day - 2;
	else
		cout << -1 << endl;

	cout << endl;
	for (int a = 0; a < H; ++a)
	{
		for (int b = 0; b < N; ++b)
		{
			for (int c = 0; c < M; ++c)
			{
				cout << Tom[a][b][c] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}