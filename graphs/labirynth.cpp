#include <bits/stdc++.h>

using namespace std;

int lab[102][102];
bool wyn;

void f(int a, int b)
{
    if (lab[a][b] == 2)
    {
        wyn = true;
    }
    lab[a][b] = 0;
    if (lab[a+1][b])
    {
        f(a+1, b);
    }
    if(lab[a][b+1])
    {
        f(a, b+1);
    }
    if (lab[a-1][b])
    {
        f(a-1, b);
    }
    if (lab[a][b-1])
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
    int k;
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int h;
            cin >> h;
            if (!h)
            {
                lab[i][j] = 1;
            }
            if (h == 1)
            {
                lab[i][j] = 0;
            }
            if (h == 2)
            {
                lab[i][j] = 2;
            }
        }
    }
    /*for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << lab[i][j] << ' ';
        }
        cout << "\n";
    }*/
    int a = 1, b = 1;
    f(a, b);
    if (wyn == true)
    {
        cout << 1;
    }
    else 
    {
        cout << 0;
    }
    cout << "\n";
}