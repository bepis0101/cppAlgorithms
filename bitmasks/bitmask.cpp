#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n; cin >> n;
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        suma += 1 << x-1;
    }
    cout << suma;
} 