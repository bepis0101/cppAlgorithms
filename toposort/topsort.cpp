#include <bits/stdc++.h>

using namespace std;

const int D = 1e5 + 2;
int in[D];
vector <int> lista;
vector <int> graf[D];
bool czy;

void topsort(int n)
{
    priority_queue <int> q;
    for (int i = 1; i <= n; i++)
    {
        if(in[i] == 0)
        q.push(i);
    }
    while (q.size() > 0)
    {
        int u = q.top();
        q.pop();
        lista.push_back(u);
        for (int v: graf[u])
        {
            in[v]--;
            if (in[v] == 0)
            {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (in[i] > 0)
        {
            czy = true;
        }
    }
}
int main()
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
        in[b]++;
    }
    topsort(n);
    if (czy)
    {
        cout << "NIE";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << lista[i] << ' ';
    }
}