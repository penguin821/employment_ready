#include <iostream>
#include <vector>
using namespace std;

/*
3 x 3 �ʿ� 0,0���� �����ؼ� 4�������� ��ĭ Ž�� �湮�ϸ� ��湮X
�湮�ϴ� ��ǥ���� ���� ���

1 0 1
1 0 1
0 1 1

*/

const int n = 3, m = 3;
int gmap[n][m];
int visited[n][m];

const int dy[] = { -1,0,1,0 }; // ��, ��, �Ʒ�, ��
const int dx[] = { 0,1,0,-1 }; // 4����

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

