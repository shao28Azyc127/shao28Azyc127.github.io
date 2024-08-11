#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    int v[n - 1], a[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    double oil = 0;
    int money = 0;
    int place = 0;
    int nowoil = a[0];
    for (; place < n - 1; place++)
    {
        double dis = v[place];
        dis -= oil * d;
        oil = 0;
        nowoil = nowoil < a[place] ? nowoil : a[place];
        dis /= d;
        int nowo = ceil(dis);
        oil += nowo;
        oil -= dis;
        money += nowo * nowoil;
    }
    cout << money << endl;
    return 0;
}