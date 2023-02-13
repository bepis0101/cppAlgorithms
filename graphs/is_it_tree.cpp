#include<bits/stdc++.h>

using namespace std;

vector <int> graf[100001];
bool vis[100001];
bool d;
void dfs(int u, int p)
{
    vis[u] = true;
    for (int j = 0; j < graf[u].size(); j++)
    {
        int v = graf[u][j];
        if (vis[v] == 0 and v != p)
        {
            dfs(v, u);
        }
        else if (v != p)
        {
            cout << "NIE";
            exit(0);
        }
    }
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n-1 != m)
    {
        cout << "NIE";
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NIE";
            return 0;
        }
    }
    cout << "TAK";
}