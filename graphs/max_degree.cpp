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
        int maks = 0, miej = 0;;
        for (int i = 1; i <= n; i++)
        {
            if (ile[i] >= maks)
            {
                maks = ile[i];
                miej = i;
            }
        }
        cout << miej << ' ' << maks;
        cout << "\n";
        ile.clear();
    }
}