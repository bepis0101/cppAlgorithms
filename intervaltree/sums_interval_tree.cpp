/*Zrealizuj strukturę danych, w której będą możliwe następujące operacje:

A x y - add(x,y) - dodaj do komórki nr x wartość y
S a b - sum(a,b) - zwróć sumę komórek o numerach a, a+1, ..., b
Za pomocą swojej struktury zasymuluj jej działanie dla przykładowych operacji podanych na standardowym wejściu. Instrukcje będą zapisane w osobnych wierszach i oznaczone jak wyżej
Wejście
W pierwszym wierszu dana jest liczba zestawów danych (nie większa niż 30). Każdy zestaw to ciąg instrukcji zapisanych w osobnych wierszach, zakończony instrukcją: K 0 0 Możesz założyć, że zawsze będzie 0 ≤ x, a, b ≤ 1'000'000, -1'000'000 ≤ y ≤ 1'000'000. W każdym teście, wszystkich instrukcji jest co najwyżej 1 000 000.

Wyjście
Dla każdego zestawu danych wypisz wyniki instrukcji S x y.

Przykład
Dla danych wejściowych

2
A 1 5
A 0 9
A 2 3
S 0 2
S 0 1
S 0 0
A 1 -5
S 0 2
S 0 1
S 0 0
K 0 0
S 0 2
S 0 1
S 0 0
A 1 -5
S 0 2
S 0 0
K 0 0
poprawną odpowiedzią jest
17
14
9
12
9
9
0
0
0
-5
0*/


#include <bits/stdc++.h>

using namespace std;

const int T = 1 << 20;

int tree[T*2];

int f(int a, int b) 
{
    return a + b;
}

// l, r = [0, n - 1]
int query(int l, int r) 
{
    if(l > r) return 0; //! pusty przedzial
    l += T, r += T;
    if(l == r) {
        return tree[l]; //! wazne
    }
    int res = f(tree[l], tree[r]);

    while(l / 2 != r / 2) {
        //* jakis warunek na braci
        // r != l + 1

        if(l % 2 == 0) {
            res = f(res, tree[l + 1]);
        }

        if(r % 2 == 1) {
            res = f(res, tree[r - 1]);
        }

        l /= 2, r /= 2;
    }

    return res;
}

// u = [0, n - 1]
void upd(int u, int x) 
{
    u += T;

    tree[u] += x;
    u /= 2;
    while (u >= 1)
    {
        tree[u] += x;
        u /= 2;
    }
   
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'K')
        {
            t--;
            fill(tree, tree + 2*T, 0);
        }
            
        if (c == 'A')
        {
            upd(a, b);
        }
        if (c == 'S')
        {
            cout << query(a, b) << "\n";
        }
    }
}