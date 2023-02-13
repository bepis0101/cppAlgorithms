#include <bits/stdc++.h>
using namespace std;
int tab[1000001];
stack <int> s; 
int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tab[i];
    } 
    for (int i = 0; i < n; i++) 
    {  
        while (!s.empty() && s.top() >= tab[i]) 
        {
            s.pop();
        }  
        if (s.empty()) 
        {
            cout << 0 << ' '; 
        }
        else 
        {
            cout << s.top() << ' '; 
        }
        s.push(tab[i]); 
    }  
    return 0; 
} 