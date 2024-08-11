# include "bits/stdc++.h"

using namespace std;
const int maxn = 8e2 + 10;
bool f[maxn];
char c;
int n;
int cnt;
int ans;
int a[maxn];
int b[maxn];
int d[maxn];
int e[200010];
int q[20010][maxn];
inline void hw (int c[], int l)
{
    for (int i = 1 ; i <= l ; i++)
        if (c[i] != c[l - i + 1])
            return;
    ans++;
    f[cnt] = true;
    return;
}
int main ()
{
     freopen ("game.in", "r", stdin);
     freopen ("game.out", "w", stdout);
    cin >> n;
    if (n >= 800)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> c;
            e[i] = (c - 'a' + 1);
            if (e[i] == e[i - 1])
                ans++;
        }
        printf ("%d\n", ans);
        return (0);
    }
    ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> c;
        a[i] = (c - 'a' + 1);
    }
    for (int i = 1 ; i <= n ; i++)
        for (int j = i + 1 ; j <= n ; j++)
        {
            if ((j - i) % 2 == 0)
                continue;
            int te = 1;
            cnt++;
            for (int k = i ; k <= j ; k++)
            {
                b[te] = a[k];
                q[cnt][te] = a[k];
                te++;
            }
            te--;
            d[cnt] = te;
            hw (b, te);
        }
    for (int i = 1 ; i <= cnt ; i++)
        for (int j = 1 ; j <= cnt ; j++)
        {
            for (int k = 1 ; k <= cnt ; k++)
            {
                if (d[i] + d[j] != d[k])
                    continue;
                bool f_ = true, F_ = true;
                for (int p = 1 ; p <= d[i] ; p++)
                    if (q[i][p] != q[k][p])
                    {
                        f_ = false;
                        continue;
                    }
                for (int p = 1 ; p <= d[j] ; p++)
                    if (q[j][p] != q[k][p + d[i]])
                    {
                        F_ = false;
                        continue;
                    }
                if (F_ && f_ && f[i] && f[j])
                    ans++;
            }
        }
            
    printf ("%d\n", ans);
    return (0);
}

/*
8
accabccb
*/