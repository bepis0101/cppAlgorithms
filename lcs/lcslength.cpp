#include <bits/stdc++.h>
using namespace std;
int lcs[102][102];
int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s, se;
	cin >> s >> se;
	for (int i = 1; i <= s.size(); i++)
	{
		for (int j = 1; j <= se.size(); j++)
		{
			if (s[i-1] == se[j-1])
			{
				lcs[i][j] = lcs[i-1][j-1]+1;
			}
			else 
			{
				lcs[i][j] = max (lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	cout << lcs[s.size()][se.size()];

}