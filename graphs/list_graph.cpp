#include <bits/stdc++.h>

using namespace std;

vector <int> graf[100001];

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
        if (!graf[i].empty())
        {
            cout << "vertex " << i << " has neighbours ";
            for (int j = 0; j < graf[i].size(); j++)
            {
                cout << graf[i][j] << ' ';
            }
            cout << "\n";
        }
        else
        {
            cout << "vertex "<< i << " has no neighbours\n";
        }
    }
}