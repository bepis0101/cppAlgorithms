/*Dzięki mądrym i podjętym we właściwym czasie decyzjom króla Bajtazara sieć autostrad w Bajtocji osiągnęła imponujące rozmiary. Niestety awaria głównego komputera w kraju spowodowała krach na giełdzie, co wraz z niekorzystnym kursem wymiany bitów na sekundy wymusiło prywatyzację autostrad. W szczególny sposób dotknęło to firmy obsługujące autostrady i niektóre z nich musiały ogłosić upadłość. Wszystkie trasy, których właściciele splajtowali, zostały zamknięte. W tej sytuacji przeciętny obywatel Bajtocji nie był w stanie korzystać z dobrodziejstw rozległego systemu autostrad, a to z kolei odbierało holdingowi Bajtostrady M.Hz znaczną część zysków. Przewodniczący holdingu oskarżył króla Bajtazara o zniszczenie wielu lat ciężkiej pracy wszystkich Bajtocjan i wezwał do demonstracyjnego nieposłuszeństwa wobec władcy. Bajtocjanie wyłączyli komputery. W obliczu wojny domowej król Bajtazar postanowił odwiedzić wszystkie miasta kraju, aby wyrazić zrozumienie dla niepokoju mieszkańców. Jednak tragiczna sytuacja budżetowa Bajtocji wymusza maksymalne oszczędności - miedzy innymi należy zminimalizować koszty podróży autostradami.

Zadanie
Na podstawie opisu połączeń między miastami Bajtocji należy dla każdego miasta wyznaczyć najmniejszy koszt, jaki musi ponieść król jadąc do niego ze stolicy.

Wejście
W pierwszej linii wejścia dane są dwie liczby: n i m, oznaczające odpowiednio ilość miast w Bajtocji oraz ilość połączeń (1 ≤ n ≤ 7000, 1 ≤ m ≤ 300000). Następnie danych jest m trójek liczb a b c. Każda trójka oznacza, że istnieje autostrada łącząca miasta a i b, na której koszt przejazdu wynosi c (1 ≤ a,b ≤ n, 1 ≤ c ≤ 100000). Oczywiście autostrady w Bajtocji są dwukierunkowe. Przyjmujemy, że stolica Bajtocji ma numer 1.

Wyjście
Na wyjściu należy podać n-1 liczb, gdzie i-ta liczba to minimalny koszt przejazdu ze stolicy do miasta i+1.

Przykład
Dla danych wejściowych

6 10
1 2 2
1 6 1
1 5 3
4 1 5
2 6 2
2 3 5
4 3 4
3 5 4
4 5 4
5 6 3
poprawną odpowiedzią jest
2 7 5 3 1 */
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 3e5 + 2;

#define FOR(a, b, c) for (int a = b; a < c; a++)
vector <pair<int, int>> graf[N];
ll dist[N];
const ll inf = 1e18 + 2;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n)
    {
        dist[i] = inf;
    }
    FOR(i, 0, m)
    {
        int a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    priority_queue <pair<ll, int>> q;
    q.push({0, 0});
    dist[0] = 0;

    while (q.size())
    {
        int u = q.top().second;
        ll odl = -q.top().first;
        q.pop();
        if (odl != dist[u])
        {
            continue;
        }
        for (auto e : graf[u])
        {
            if (dist[e.first] > dist[u] + e.second)
            {
                dist[e.first] = dist[u] + e.second;
                q.push({-dist[e.first], e.first});
            }
        }
    }
    FOR(i, 1, n)
    {
        if (dist[i] != inf)
        {
            cout << dist[i] << ' ';
        }
    }

}