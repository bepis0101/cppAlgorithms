/*Struktura drzewa przedziałowego może być reprezentowana w pamięci komputera jako pełne drzewo binarne, pamiętane w tablicy. Poniższy rysunek przedstawia drzewo przedziałowe dla liczb z przedziału [0,7]


W strukturze drzewa przedziałowego, istotne jest to, że każdy przedział [x,y] można rozbić na tzw. przedziały bazowe, tj. takie, które są w wierzchołkach drzewa oraz w sumie dają przedział [x,y]. Oczywiście chodzi o to, aby tych przedziałów było jak najmniej. Tak więc dwa sąsiednie wierzchołki (bracia w drzewie binarnym) nie mogą być jednocześnie przedziałami bazowymi.
Na przykładzie powyższego drzewa, przedział [2,6] zostanie rozbity na [2,3], [4,5], [6,6].

Zadanie
Dla danego rozmiaru drzewa $n$ oraz pewnego przedziału $[x,y]$ należy podać przedziały bazowe, z których się on składa.

Wejście
W pierwszym wierszu dana będą trzy liczby: n, x, y (0 < n ≤ 106, 0 ≤ x ≤ y < n). Możesz założyć, że liczba n będzie potęgą dwójki.

Wyjście
Na wyjściu należy wypisać wszystkie przedziały bazowe, z których składa się przedział [x,y]. Przedziały należy uporządkować po ich początkach. Przed każdym przedziałem należy również podać jego numer w tablicy.

Przykład 1
Dla danych wejściowych

8 2 6
poprawną odpowiedzią jest
5:  [2, 3]
6:  [4, 5]
14: [6, 6]
Przykład 2
Dla danych wejściowych

64 5 40
poprawną odpowiedzią jest
69:  [5, 5]
35:  [6, 7]
9:   [8, 15]
5:   [16, 31]
12:  [32, 39]
104: [40, 40]*/

#include <bits/stdc++.h>

using namespace std;

vector < pair<pair<int, int>, int> > v;

bool comp (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.first.first < b.first.first;
}

void prze (int l, int r, int w, int la, int ra)
{
    if (l > ra or r < la)
    {
        return;
    }

    if (l <= la and r >= ra)
    {
        v.push_back({{la, ra}, w});
        return;
    }
    int mid = (la + ra)/2;
   
    prze(l, r, w*2, la, mid);
 
    prze(l, r, w*2 + 1, mid+1, ra);
    

}

int main ()
{

    int l, r, n;
    cin >> n >> l >> r;
    prze(l, r, 1, 0, n-1);
    sort(v.begin(), v.end(), &comp);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second << ":" << ' ' << "[" << v[i].first.first << ", " << v[i].first.second << "]" << "\n";
    }
}