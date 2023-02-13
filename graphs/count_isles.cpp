#include <bits/stdc++.h>

using namespace std;

bool wys[102][102];

void f(int a, int b)
{
    wys[a][b] = false;
    if (wys[a+1][b])
    {
        f(a+1, b);
    }
    if (wys[a][b+1])
    {
        f(a, b+1);
    }
    if (wys[a-1][b])
    {
        f(a-1, b);
    }
    if (wys[a][b-1])
    {
        f(a, b-1);
    }     
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> wys[i][j];
        }
    }
    int suma = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (wys[i][j])
            {
                suma++;
                f(i, j);
            }
        }
    }
    cout << suma << "\n";
}