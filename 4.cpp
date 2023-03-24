#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : graph[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
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
    if (isBipartite(graph))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}
