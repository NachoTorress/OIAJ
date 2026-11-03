#include <bits/stdc++.h>
using namespace std;
#define ll int
#define x first
#define y second
int main()
{
    ll a, b, t;
    cin >> a >> b >> t;
    bool mapa[b][a][4];
    for (int i = 0; i < b; i++)
        for (int j = 0; j < a; j++)
            for (int k = 0; k < 4; k++)
                mapa[i][j][k] = 0;
    vector<vector<ll>> dist(b, vector<ll>(a, INT_MAX));
    while (t--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        if (x1 == x2)
        {
            for (int i = y1; i < y2; i++)
            {
                if (x1 > 0)
                    mapa[i][x1 - 1][1] = 1;
                if (x1 < a)
                    mapa[i][x1][3] = 1;
            }
        }
        else
        {
            for (int i = x1; i < x2; i++)
            {
                if (y1 > 0)
                    mapa[y1 - 1][i][2] = 1;
                if (y1 < b)
                    mapa[y1][i][0] = 1;
            }
        }
    }
    queue<pair<int, int>> cola;
    dist[0][0] = 0;
    cola.push({0, 0});
    while (!cola.empty())
    {
        auto top = cola.front();
        cola.pop();
        ll costo = dist[top.y][top.x];
        if (top.x + 1 < a && !mapa[top.y][top.x][1])
        {
            if (dist[top.y][top.x + 1] > costo + 1)
                dist[top.y][top.x + 1] = costo + 1, cola.push({top.x + 1, top.y});
        }
        if (top.x - 1 >= 0 && !mapa[top.y][top.x][3])
        {
            if (dist[top.y][top.x - 1] > costo + 1)
                dist[top.y][top.x - 1] = costo + 1, cola.push({top.x - 1, top.y});
        }
        if (top.y + 1 < b && !mapa[top.y][top.x][2])
        {
            if (dist[top.y + 1][top.x] > costo + 1)
                dist[top.y + 1][top.x] = costo + 1, cola.push({top.x, top.y + 1});
        }
        if (top.y - 1 >= 0 && !mapa[top.y][top.x][0])
        {
            if (dist[top.y - 1][top.x] > costo + 1)
                dist[top.y - 1][top.x] = costo + 1, cola.push({top.x, top.y - 1});
        }
    }
    if (dist[b - 1][a - 1] != INT_MAX)
        cout << dist[b - 1][a - 1];
    else
        cout << "imposible";
}
