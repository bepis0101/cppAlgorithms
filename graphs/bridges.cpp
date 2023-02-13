#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 2;
int pre[N], low[N], T;
bool vis[N];
vector < pair<int, int> > tab;
vector <int> graf[N];
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

void dfs(int u, int p)
{
    pre[u] = low[u] = T++;
    vis[u] = true;
    for (auto v : graf[u])
    {
        if (v != p)
        {
            if(vis[v])
            {
                low[u] = min(low[u], pre[v]);
            }
            else
            {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (pre[v] == low[v])
                {
                    if (u <= v)
                    {
                        tab.push_back({u, v});
                    }
                    else
                    {
                        tab.push_back({v, u});
                    }
                }
            }
        }
    }
}   


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        graf[u].push_back(v);
        graf[v].push_back(u);
    }

    dfs(1, 1);
    sort(tab.begin(), tab.end(), &comp);

    for (int i = 0; i < tab.size(); i++)
    {
        cout << tab[i].first << ' ' << tab[i].second << "\n";
    }
    
}