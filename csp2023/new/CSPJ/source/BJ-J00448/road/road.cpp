#include <bits/stdc++.h>
using namespace std;

int a[100001];
long long d[100001];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    if(n == 1)
    {
        printf("%d\n", 0);
        return 0;
    }
    d[1] = 0;
    for(int i = 2;i <= n;i++)
    {
        int v;
        scanf("%d", &v);
        d[i] = d[i - 1] + v;
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    long long sum = 0, pos = 0;
    int mina = a[1];
    for(int i = 2;i <= n;i++)
    {
        if(d[i] > pos)
        {
            long long add = (d[i] - pos + m - 1) / m;
            sum += add * mina;
            pos += add * m;
        }
        mina = min(mina, a[i]);
    }
    printf("%lld\n", sum);
    return 0;
}
