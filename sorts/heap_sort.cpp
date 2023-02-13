#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;
const int INF = INT_MAX;

int tree[N];

void up(int u)
{
    while (u > 1 and tree[u] < tree[u/2])
    {
        swap(tree[u], tree[u/2]);
        u /= 2;
    }
}
void down(int size, int u = 1)
{
    while ((tree[u] > tree[u*2] or tree[u] > tree[u*2+1]) and u < size)
    {
        if (tree[u*2] <= tree[u*2+1])
        {
            swap(tree[u], tree[u*2]);
            u *= 2;
        }
        else if (tree[u*2] > tree[u*2+1])
        {
            swap(tree[u], tree[u*2+1]);
            u = u*2 + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    fill(tree, tree + N - 2, INF);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        tree[i] = a;
        up(i);
    }
    int size = n;
    for (int i = 1; i <= n; i++)
    {
        cout << tree[1] << ' ';
        swap(tree[1], tree[size]);
        tree[size] = INF;
        size--;
        down(size);

    }

}