#include <bits/stdc++.h>

using namespace std; 

const int T = 1 << 17; //? przesuniecia bitowe
// 0000001
// << 1 == * 2
// 0000010
// >> 1 == / 2

int tree[T * 2];

int f(int a, int b) 
{
    return a;
}

// l, r = [0, n - 1]
int query(int u) 
{
    u += T;
    int res = tree[u];
    u /= 2;
    while(u >= 1) 
    {
        res += tree[u];
        u /= 2;
    }
    return res;
}

// u = [0, n - 1]
void upd(int l, int r,  int x) 
{
    if (l > r)
    {
        return;
    }
   l += T;
   r += T;
   if (l == r)
   {
       tree[l] += x;
       return;
   }
   tree[r] += x; tree[l] += x;
    while (r/2 != l/2)
    {
        if (l % 2 == 0)
        {
            tree[l+1] += x;
        }
        if (r % 2 == 1)
        {
            tree[r-1] += x;
        }
        l /= 2; r /= 2;
    }

}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        bool q;
        cin >> q;
        if (q)
        {
            int a, b, c;
            cin >> a >> b >> c;
            upd(a, b, c);
        }
        if (!q)
        {
            int a;
            cin >> a;
            cout << query(a) << "\n";
        }

    }
    
}