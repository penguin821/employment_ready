#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <tuple>

using namespace std;

vector<int> answer;
int visited[104][104];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void bfs(vector<string> maps, int y, int x)
{
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({ y,x });

    int result = 0;


    while (!q.empty())
    {
        int y, x;
        tie(y, x) = q.front();
        result += (maps[y][x] - '0');
        q.pop();

        for (int i = 0; i < 4; i++) 
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (nx < 0 || ny < 0 || ny >= maps.size() || nx >= maps[y].size() || maps[ny][nx] == 'X')
                continue;
            if (visited[ny][nx])
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }
    answer.push_back(result);
}

vector<int> solution(vector<string> maps)
{
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] != 'X' && visited[i][j] == 0)
            {
                bfs(maps, i, j);
            }
        }
    }

    sort(answer.begin(), answer.end());

    if (answer.size() == 0)
        answer.push_back(-1);

    for (int i : answer)
        cout << i << ' ';
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> maps(n);

    for (int i = 0; i < n; i++)
    {
        cin >> maps[i];
    }
    solution(maps);
}

