#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void f(int i)
{
    if (i == n)
    {
        return;
    }

    s += char('a' + i);
    cout << s << "\n";
    f(i+1);
    s.pop_back();
    f(i+1);
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    f(0);
    return 0;                                                        
}