#include <bits/stdc++.h>

using namespace std;

vector <int> graf[100001];

int roz[100001];

void dfs(int u, int p)
{
    roz[u] = 1;
    for (int v : graf[u])
    {
        if (v != p)
        {
            dfs(v, u);
            roz[u] += roz[v];
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
        cout << roz[i] << ' ';
    }
}