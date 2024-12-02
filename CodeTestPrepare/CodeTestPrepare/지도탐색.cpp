#include <iostream>
#include <vector>
using namespace std;

/*
3 x 3 맵에 0,0부터 시작해서 4방향으로 한칸 탐색 방문하면 재방문X
방문하는 좌표들을 전부 출력

1 0 1
1 0 1
0 1 1

*/

const int n = 3, m = 3;
int gmap[n][m];
int visited[n][m];

const int dy[] = { -1,0,1,0 }; // 위, 오, 아래, 왼
const int dx[] = { 0,1,0,-1 }; // 4방향

void go(int y, int x)
{
	visited[y][x] = 1;
	cout << y << " : " << x << "\n";
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || ny >= m)
			continue;
		if (visited[ny][nx])
			continue;
		if (gmap[ny][nx] == 0)
			continue;
		go(ny, nx);
	}
}

int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> gmap[i][j];
		}
	}
	go(0, 0);
}

