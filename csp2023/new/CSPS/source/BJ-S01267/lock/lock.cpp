#include<bits/stdc++.h>
#define N 100000
using namespace std;

int n, s[10], a[10], p[10], ans = 0;

bool comp(int t)
{
    for(int i = 1; i <= n; ++i)
        if(s[i] == t) return 1;
    return 0;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    p[1] = 1;
    for(int i = 2; i <= 5; ++i)
        p[i] = p[i - 1] * 10;
    for(int i = 1; i <= n; ++i)
    {
        int l = 0;
        for(int j = 1; j <= 5; ++j)
        {
            scanf("%d", &l);
            s[i] = s[i] * 10 + l;
        }
    }
    for(int i = 0; i < N; ++i)
    {
        int t = i;
        int m = 0;
        for(int j = 1; j <= 5; ++j)
        {
            int c = (t / p[j]) % 10;
            for(int k = 1; k <= 9; ++k)
            {
                t = t + ((c + k) % 10 - c) * p[j];
                if(comp(t))++m;
                t = i;
            }
        }
        for(int j = 1; j <= 4; ++j)
        {
            int c1 = (t / p[j]) % 10, c2 = (t / p[j + 1]) % 10;
            for(int k = 1; k <= 9; ++k)
            {
                t = t + ((c1 + k) % 10 - c1) * p[j];
                t = t + ((c2 + k) % 10 - c2) * p[j + 1];
                if(comp(t))++m;
                t = i;
            }
        }
        if(m == n) ans++;
    }
    printf("%d", ans);
    return 0;
}