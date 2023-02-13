#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int temp = 0;
    cin >> n;
    n = 2*n +1;
    while (n--)
    {
        int a;
        cin >> a;
        temp ^= a;
    }
    cout << temp;
}