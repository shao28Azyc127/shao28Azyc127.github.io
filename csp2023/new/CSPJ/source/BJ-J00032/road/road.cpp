#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, d, mf, cost;
int a[maxn], v[maxn], tc[maxn];

int a1_min()
{
    cout << mf * a[1];
    return ;
}//while a[1] is the cheapest one

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1;i < n;i ++)
    {
        cin >> v[i];
        mf += v[i];
    }
    mf = mf % d ? mf / d + 1 : mf / d;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        tc[i] = a[i];
    }
    sort(tc + 1, tc + n + 1);
    if(tc[1] == a[1])
    {
        a1_min();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
