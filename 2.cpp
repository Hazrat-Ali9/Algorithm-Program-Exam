#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> adj[N];
int flag[N];
bool visited[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    flag[source] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                flag[v] = flag[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < y; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0);
    for (int i = 0; i < x; i++)
    {
        cout << "node " << i << " = level: " << flag[i] << endl;
    }
    return 0;
}
