#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> adj[N];
bool visited[N];
bool rec_stack[N];

bool dfs(int u)
{
    visited[u] = true;
    rec_stack[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            if (dfs(v))
            {
                return true;
            }
        }
        else if (rec_stack[v])
        {
            return true;
        }
    }
    rec_stack[u] = false;
    return false;
}

bool flag_cycle(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    if (flag_cycle(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
