#include<bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& graph)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            dfs(v, visited, graph);
        }
    }
}

int countComponents(vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, graph);
            count++;
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int numComponents = countComponents(graph);
    cout << numComponents << endl;
    return 0;
}
