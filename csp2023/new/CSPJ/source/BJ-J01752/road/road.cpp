#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[100005], b[100005];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, oil = 0, prize = 10000000, meter = 0, ans = 0, yu = 0;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(b[i] < prize)
        {
            prize = b[i];
        }
        a[i] = a[i] - yu;
        yu = 0;
        if(a[i] % m != 0)
        {
            oil = a[i] / m + 1;
            ans += oil * prize;
            yu = oil * m - a[i];
        }
        else
        {
            oil = a[i] / m;
            ans += oil * prize;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
