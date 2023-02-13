#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << "\n";
    int t;
    cin >> t;
    for (int h = 0; h < t; h++)
    {
        int n, m;
        cin >> n >> m;
        vector <int> ile(n+1);
        int a, b;
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            ile[a]++;
            ile[b]++;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ile[i] << ' ';
        }
        cout << "\n";
        ile.clear();
    }
}