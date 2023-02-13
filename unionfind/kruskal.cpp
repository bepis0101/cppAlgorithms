#include <bits/stdc++.h>

using namespace std;
bool comp(pair<pair<int,int>, pair<int, int>> a, pair<pair<int,int>, pair<int, int>> b)
{
    if (a.second.first == b.second.first)
    {
        return a.second.second < b.second.second;
    }
    return a.second.first < b.second.first;
}
const int N = 7e3 + 3;
const int M = 3e5 + 3;

vector <int> wagi;
vector < pair <pair <int,int>, pair<int, int>> > v(M);

int lider[N];
int roz[N];
int Find(int x)
{
    if (x == lider[x])
    {
        return x;
    }
    int l = Find(lider[x]);
    lider[x] = l;
    return l;
}

bool Union(int x, int y)
{
    x = Find(x), y = Find(y);
    if (x == y)
    {
        return false;
    }
    if(roz[x] > roz[y])
    {
        swap(x, y);
    }
    lider[x] = y;
    roz[y] += roz[x];
    return true;
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        lider[i] = i;
        roz[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[i].first.first = a;
        v[i].first.second = b;
        v[i].second.first = c;
        v[i].second.second = i+1;
    }
    sort (v.begin(), v.begin() + m, &comp);
    int k = 0;
    for (int i = 0; i < m and k < n-1; i++)
    {
        if (Union(v[i].first.first, v[i].first.second) == true)
        {
            wagi.push_back(v[i].second.second);
            k++;
        }
    }
    for (int i = 0; i < wagi.size(); i++)
    {
        cout << wagi[i] << "\n";
    }

}