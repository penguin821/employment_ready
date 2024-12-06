#include <iostream>
#include <vector>

using namespace std;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int m, n, k, y, x, ret, ny, nx, t;
int a[104][104];
bool visited[104][104];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> maps(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num;
			scanf_s("%1d", &num);
			maps[i].push_back(num);
		}
	}
	solution(maps);
}
