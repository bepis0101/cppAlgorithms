#include <bits/stdc++.h>

using namespace std;

const int T = 1 << 20;
int tree[T*2];
void upd(int u, int val)
{
    u += T;
    while(u >= 1)
    {
        tree[u] = max(tree[u], val);
        u /= 2;
    }
}

int get(int a, int b)
{
    a += T; b += T;
    if (a==b) return tree[a];
    int res = max(tree[a], tree[b]);
    while (a/2 != b/2)
    {
        if (a%2 == 0) res = max(res,tree[a+1]);
        if (b%2 == 1) res = max(res,tree[b-1]);
        a /= 2; b /= 2;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        int length = get(0, a);
        upd(a, length+1);
    }

    cout << get(0, T-1) << "\n";
}