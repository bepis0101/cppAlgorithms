#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 3e5 + 2;

#define FOR(a, b, c) for (int a = b; a < c; a++)
vector <pair<int, int>> graf[N];
ll dist[N];
const ll inf = 1e18 + 2;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n)
    {
        dist[i] = inf;
    }
    FOR(i, 0, m)
    {
        int a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        graf[a].push_back({b, c});
    }
    priority_queue <pair<ll, int>> q;
    q.push({0, 0});
    dist[0] = 0;

    while (q.size())
    {
        int u = q.top().second;
        ll odl = -q.top().first;
        q.pop();
        if (odl != dist[u])
        {
            continue;
        }
        for (auto e : graf[u])
        {
            if (dist[e.first] > dist[u] + e.second)
            {
                dist[e.first] = dist[u] + e.second;
                q.push({-dist[e.first], e.first});
            }
        }
    }
    FOR(i, 0, n)
    {
        if (dist[i] != inf)
        {
            cout << dist[i] << ' ';
        }
        else 
        {
            cout << -1 << ' ';
        }
    }

}