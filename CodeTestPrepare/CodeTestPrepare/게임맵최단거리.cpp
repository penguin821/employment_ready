#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int diry[4] = { -1,0,1,0 };
int dirx[4] = { 0,1,0,-1 };
int visited[104][104];

int solution(vector<vector<int> > maps)
{
    int answer;
    int my = maps.size();
    int mx = maps[0].size();
    int y, x, sy = 0, sx = 0;

    visited[sy][sx] = 1;
    queue<pair<int, int>> q;
    q.push({ sy,sx });

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + diry[i];
            int nx = x + dirx[i];
            if (ny < 0 || ny >= my || nx < 0 || nx >= mx || maps[ny][nx] == 0)
                continue;
            if (visited[ny][nx])
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }
    if (visited[my - 1][mx - 1])
        answer = visited[my - 1][mx - 1];
    else
        answer = -1;
    return answer;
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
