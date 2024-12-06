#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
const int max_n = 100, max_m = 100;

int visited[104][104];
int diry[4] = { -1,0,1,0 };
int dirx[4] = { 0,-1,0,1 };

void solution(vector<vector<int>> maze)
{
	int my = maze.size();
	int mx = maze[0].size();

	int sy = 0, sx = 0, y, x;
	queue<pair<int, int>> q;
	visited[sy][sx] = 1; // Ω√¿€¡°
	q.push({ sy, sx });

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + diry[i];
			int nx = x + dirx[i];
			if (ny < 0 || ny >= my || nx < 0 || nx >= mx || maze[ny][nx] == 0)
				continue;
			if (visited[ny][nx] != 0)
				continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	cout << visited[my - 1][mx - 1];
}

int main()
{
	int n, m;
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
