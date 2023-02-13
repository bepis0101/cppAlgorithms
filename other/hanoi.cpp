#include <bits/stdc++.h> 
using namespace std; 

void hanoi(int n, int a,int c, int b) 
{ 
	if (n == 1) 
	{ 
		cout << a << ' ' << c << "\n";
		return; 
	} 
	hanoi(n - 1, a, b, c); 
	cout << a  << ' ' << c << "\n";
	hanoi(n - 1, b, c, a); 
} 
int main() 
{ 
	int n;
    cin >> n;
    int a = 1, b = 2, c = 3; 
	hanoi(n, a, c, b); 
	return 0; 
}