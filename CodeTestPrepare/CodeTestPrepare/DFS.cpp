#include <iostream>
#include <vector>
using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

void DFS(int u)
{
	visited[u] = 1;
	cout << u << "\n";
	for (int v : adj[u])
	{
		if (visited[v] == 0)
			DFS(v);
	}
}

void DFS_CheckAndGo(int here)
{
	visited[here] = 1;
	cout << here << "\n";
	for (int there : adj[here])
	{
		if (visited[there])
			continue;
		DFS(there);
	}
}

void DFS_JustGoAndCheck(int here)
{
	if (visited[here]) 
		return;
	visited[here] = 1;
	cout << here << "\n";
	for (int there : adj[here])
	{
		DFS(there);
	}
}

int main()
{
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[4].push_back(2);
	adj[2].push_back(5);
	DFS(1);

	return 0;
}