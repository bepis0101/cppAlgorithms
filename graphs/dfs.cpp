#include <bits/stdc++.h>

using namespace std;

bool vis[100001];
vector <int> graf[100001];

void dfs(int u)
{
    vis[u] = true;
    cout << u << ' ';
    for (int j = 0; j < graf[u].size(); j++)
    {
        int v = graf[u][j];
        if (vis[v] == 0)
        {
            dfs(v);
        }        
    }
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}