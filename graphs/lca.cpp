#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 +2;
vector <int> tree[N];
int father[N];
int depth[N];
void dfs(int gle, int u, int oj)
{
    depth[u] = gle;

    for (auto i : tree[u])
    {
        if (i != oj)
        {
            dfs(gle+1, i, u);
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    father[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        father[i] = a;
        tree[father[i]].push_back(i);
    }
    int m; cin >> m;
    dfs(0, 1, 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        while (u != v)
        {
            if (depth[u] >= depth[v])
            {
                u = father[u];
            }
            else
            {
                v = father[v];
            }
        }
        cout << u << "\n";
    }
    


}