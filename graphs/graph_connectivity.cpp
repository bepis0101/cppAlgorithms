#include <bits/stdc++.h>

using namespace std;

vector <int> graf[1000001];
bool vis[1000001];

void dfs(int u)
{
    vis[u] = true;
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
    int t;
    cin >> t;
    for (int h = 0; h < t; h++)
    {
        int n, m;
        cin >> n >> m;
        
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graf[a].push_back(b);
            graf[b].push_back(a);
        }
        dfs(1);
        /*for (int i = 1; i <= n; i++)
        {
            cout << vis[i] << ' ';
        }*/
        cout << "\n";
        int suma = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == true)
            {
                suma++;
            }
        }
        if (suma == n)
        {
            cout << "TAK\n";
        }
        else
        {
            cout << "NIE\n";
        }
        for (int i = 0; i <= n; i++)
        {
            graf[i].clear();
            vis[i] = false;
        }
    }
}