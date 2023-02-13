#include <bits/stdc++.h>

using namespace std;

int odl[500001];
vector <int> graf[100001];

void bfs (int i, int n)
{
    fill(odl, odl+n+1, -1);
    queue <int> q;
    q.push(i);
    odl[i] = 0;
    while (q.size() > 0)
    {
        int u = q.front();
        q.pop();

        for (int j = 0; j < graf[u].size(); j++)
        {
            int v = graf[u][j];
            if (odl[v] == -1)
            {
                q.push(v);
                odl[v] = odl[u] + 1;
            }
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, d, s;
    cin >> n >> m >> s >> d;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    bfs(s, n);
    for (int i = 1; i <= n; i++)
    {
        if (odl[i] == d)
        {
            cout << i << ' ';
        }
    }
    cout << "\n";

}