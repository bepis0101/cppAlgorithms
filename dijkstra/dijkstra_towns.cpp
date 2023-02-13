/*Bajtozdrój to znany na całym świecie bajtocki kurort zawdzięczający swą famę pięknej lokalizacji i niespotykanym warunkom uzdrowiskowym. Pięknie położona w samym sercu Bajtogór miejscowość od lat kusi turystów doskonale utrzymanymi, profesjonalnie oświetlonymi, dobrze naśnieżonymi, starannie ubitymi, nie wyjeżdżonymi stokami narciarskimi, szeroką gamą kąpieli leczniczych w przystępnych cenach oraz słynną bazą hotelową - w tym luksusowym apartamentem, w którym zwykł spędzać najwspanialsze chwile sam król Bajtazar. Nadchodzi zima. Ciężkie chmury suną leniwie przez bezkresne przestrzenie niebios rozsiewając nad krainą Bajtazara pierwsze nasiona zimy, jesienne słoty powoli ustępują miejsca zimowemu puchowi, pierwsze kwiaty szronu rozkwitają na ekranach monitorów Bajtocjan, a obniżona temperatura ułatwia pracę komputerowym systemom chłodzenia procesorów. Ciśnienie atmosferyczne spada do 997.5 hektopaskala, temperatura powietrza wynosi -pi/e. W związku z tym do Bajtozdroju napływają pierwsi turyści...

Rada nadzorcza zarządzająca siecią hoteli w Bajtozdroju jest niezwykle przewidująca i nie da się zaskoczyć zimie i masom turystów. W celu predykcji translokacji czynnika ludzkiego do pomieszczeń mieszkalnych pozostających pod jurysdykcją Rady, rozpisano przetarg na wykonanie usługi polegającej na wyznaczeniu minimalnych odległości z każdego miasta Bajtocji do Bajtozdroju. Zwycięzca przetargu w dowodzie wdzięczności otrzyma z rąk samego przewodniczącego Rady dożywotni karnet na pobyt w wybranym przez siebie hotelu korporacji Bajtele-morele™ Jednak najwspanialszą nagrodą jest oczywiście uścisk ręki prezesa i świadomość dobrze wykonanego obowiązku obywatelskiego i przyczynienia się do poprawy sytuacji gospodarczo-społecznej rozwijającej się Bajtocji.

Wejście
W pierwszej linii wejścia dane są dwie liczby: n i m, oznaczające odpowiednio ilość miast w Bajtocji oraz ilość połączeń między miastami (1 ≤ n ≤ 7000, 1 ≤ m ≤ 300000). Następnie danych jest m trójek liczb a b c. Każda trójka oznacza, że istnieje droga z miasta a do b, na której koszt przejazdu wynosi c (1 ≤ a,b ≤ n, 1 ≤ c ≤ 100000). Oczywiście drogi w Bajtocji są jednokierunkowe (w przeciwieństwie do autostrad). Przyjmujemy, że Bajtozdrój ma numer 1.

Wyjście
Na wyjściu należy podać n-1 liczb, gdzie i-ta liczba to minimalny koszt przejazdu do Bajtozdroju z miasta i+1.

Przykład
Dla danych wejściowych

6 14
1 4 4
1 6 10
2 1 4
2 4 3
2 5 9
3 4 6
3 6 4
4 3 6
4 5 10
4 6 9
5 1 4
5 4 2
6 1 6
6 2 6
poprawną odpowiedzią jest
4 10 14 4 6*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 7e3 + 5;

#define FOR(a, b, c) for (int a = b; a < c; a++)
vector <pair<int, int>> graf[N];
ll dist[N];
const ll inf = 1e18 + 2;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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