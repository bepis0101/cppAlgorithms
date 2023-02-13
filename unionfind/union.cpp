/*
Po zakończeniu wyborów parlamentarnych nowa opcja polityczna dorwała się do władzy. Nowy minister infrastruktury postanowił spełnić wyborcze obietnice i polepszyć stan dróg w kraju. Kraj składa się z miast, połączonych drogami. Pomiędzy niektórymi miastami prowadzą dwukierunkowe drogi. Drogi nie przecinają się poza miastami, ale mogą wieść przez tunele lub estakady. Powiemy, że dwa miasta są połączone, jeśli można przejechać z jednego do drugiego za pomocą bezpośrednich dróg. Minister postawił sobie za cel połączenie dużej ilości miejscowości, ale wyborcy cały czas śledzą jego poczynania i co chwila dopytują się, czy można już przejechać pomiędzy pewnymi dwoma miastami. Minister rozpisał sobie plan inwestycji i potrzebuje Twojej pomocy, aby odpowiadać szybko zniecierpliwionym obywatelom.

Zadanie
Masz zadany graf, oraz listę kolejnych wydarzeń. Wydarzenie to albo zbudowanie nowej drogi pomiędzy dwoma wskazanymi miastami, albo pytanie o to, czy dwa wskazane miasta są połączone. Napisz program, który odpowie na każde pytanie o połączenie dwóch miast.

Wejście
W pierwszej linii wejścia znajdują się trzy liczby całkowite n, m, q (1 <= n <= 300000, 1 <= m <= 300000, 1 <= q <= 300000). W kolejnych m liniach znajdują się pary liczb całkowitych a, b (1 <= a,b <= n), oznaczające, że przed wyborem ministra miasta a i b były połączone bezpośrednią drogą. W kolejnych q liniach znajdują się trójki liczb całkowitych w, a ,b (1 <= a,b <= n , 0 <= w <= 1) oznaczające kolejne wydarzenia w kalendarzu ministra. Jeśli w = 0, to wydarzenie to zapytanie o połączenie między miastami a i b, jeśli w = 1, to wydarzenie to budowa bezpośredniej drogi pomiędzy miastami a i b. Możliwe, że pomiędzy dwoma miastami będzie więcej niż jedna bezpośrednia droga. Możesz założyć, że na wejściu nie pojawi się droga z miasta do samego siebie, ani że nie padnie pytanie o takie połączenie.

Wyjście
W kolejnych liniach wyjścia powinny znaleźć się odpowiedzi na kolejne zapytania o połączenie między miastami. Jeśli dla danego zapytania w danym momencie miasta były połączone, należy wypisać "TAK". Jeśli zaś nie były, należy wypisać "NIE".

Przykład
Dla danych wejściowych

5 4 3
1 2
2 3
3 1
4 5
0 1 4
1 2 5
0 1 4
poprawną odpowiedzią jest
NIE
TAK

*/







#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 +2;
int lider[N];
int roz[N];
int Find(int x)
{
    if (x == lider[x])
    {
        return x;
    }
    int l = Find(lider[x]);
    return l;
}
bool op2(int x, int y)
{
    if (Find(x) == Find(y))
    {
        return true;
    }
    return false;
}
void Union(int x, int y)
{
    if(!op2(x, y))
    {
        x = Find(x), y = Find(y);
        if(roz[x] < roz[y])
        {
            lider[x] = y;
        }
        else if(roz[x] > roz[y])
        {
            lider[y] = x;
        }
        else
        {
            lider[y] = x, roz[x] += roz[y];
        }
    }
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        lider[i] = i;
        roz[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    for (int i = 0; i < q; i++)
    {
        int t, a, b; 
        cin >> t >> a >> b;
        if (t == 0)
        {
            if (op2(a, b))
            {
                cout << "TAK\n";
            }
            else 
            {
                cout << "NIE\n";
            }
        }
        if (t == 1)
        {
            Union(a, b);
        }
    }
}