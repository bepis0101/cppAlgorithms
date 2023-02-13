#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 +2;

int lista[N];
vector <int> graf[N];
int in[N];

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        in[b]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> lista[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (in[lista[i]])
        {
            cout << lista[i];
            return 0;
        }
        else 
        {
            for (int j = 0; j < graf[lista[i]].size(); j++)
            {
                in[graf[lista[i]][j]]--;
            }
        }
    }
    cout << "OK";
}