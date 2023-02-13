#include <bits/stdc++.h>

using namespace std;

vector <int> drz[1000001];
bool vis[1000001];
int pre[1000001];
int post[1000001];
int pree, postt;
void dfs(int u)
{
    pree++;
    pre[u] = pree;
    vis[u] = true;
    for (int j = 0; j < drz[u].size(); j++)
    {
        int v = drz[u][j];
        if (vis[v] == 0)
        {
            dfs(v);
        }
    }
    postt++;
    post[u] = postt;    
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        drz[i].push_back(a);
        drz[a].push_back(i);
    }
    /*for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < drz[i].size(); j++)
        {
            cout << drz[i][j] << ' ';
        }
        cout << "\n";
    }*/
    dfs(1);
    /*for (int i = 1; i <= n; i++)
    {
        cout << pre[i] << ' ';
    }
    cout << "\n";
    for (int i = 1; i<= n; i++)
    {
        cout << post[i] << ' ';
    }*/
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (pre[v] <= pre[u] and post[u] <= post[v])
        {
            cout << "TAK" << "\n";
        }
        else 
        {
            cout << "NIE" << "\n";
        }
    }
}