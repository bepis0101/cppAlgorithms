#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int sor[N];

int part(int p, int k)
{
    while (p < k)
    {
        if (sor[p+1] < sor[p])
        {
            swap(sor[p+1], sor[p]);
            p++;
        }
        else
        {
            swap(sor[p+1], sor[k]);
            k--;
        }
    }
    return p;
}

void quick_sort(int p, int k)
{
    int s = part(p, k);
    
    if (p < s-1)
    {
        quick_sort(p, s-1);
    }
    if (s+1 < k)
    {
        quick_sort(s+1, k);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sor[i];
    }
    quick_sort(0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << sor[i] << ' ';
    }
    return 0;

}