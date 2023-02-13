#include <bits/stdc++.h>

using namespace std;

bool graf[1001][1001];

int main ()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a  >> b;
        graf[a][b] = true;
        graf[b][a] = true;
    }
    cout << "Macierz:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graf[i][j] == true)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "Lista:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = 1; j <= n; j++)
        {
            if (graf[i][j] == true)
            {
                cout << j << ' ';
            }
        }
        cout << "\n";
    }
}