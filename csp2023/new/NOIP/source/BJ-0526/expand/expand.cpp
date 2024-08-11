#include <bits/stdc++.h>
#define N 500005

using namespace std;

int a[N], b[N];
string ans;
int c, n, m, q;

void work()
{
    int i, j, k;
    if(a[1] == b[1] || a[n] == b[m])
    {
        ans += "0";
        return ;
    }
    if(a[n] > b[m])
    {
        if(a[1] < b[1])
        {
            ans += "0";
            return ;
        }
        int x = 1;
        for(i=2; i<=m; i++)
        {
            for(j=min(i, n); j>=1; j--)
            {
                if(a[j] > b[i])
                {
                    break;
                }
            }
            if(j < x)
            {
                ans += "0";
                return ;
            }
            if(a[x+1] > b[i] && x <= j)
            {
                x++;
            }
        }
        ans += "1";
        return ;
    }
    if(a[n] < b[m])
    {
        if(a[1] > b[1])
        {
            ans += "0";
            return ;
        }
        int x = 1;
        for(i=2; i<=m; i++)
        {
            for(j=min(i, n); j>=1; j--)
            {
                if(a[j] < b[i])
                {
                    break;
                }
            }
            if(j < x)
            {
                ans += "0";
                return ;
            }
            if(a[x+1] > b[i] && x <= j)
            {
                x++;
            }
        }
        ans += "1";
        return ;
    }
}

int aa[N], bb[N];
int px[N], py[N];

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int i, j, k;
    cin >> c >> n >> m >> q;
    for(i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        aa[i] = a[i];
    }
    for(i=1; i<=m; i++)
    {
        scanf("%d", &b[i]);
        bb[i] = b[i];
    }
    work();
    while(q--)
    {
        int kx, ky;
        cin >> kx >> ky;
        int p, v;
        for(i=1; i<=kx; i++)
        {
            cin >> px[i] >> v;
            a[px[i]] = v;
        }
        for(i=1; i<=ky; i++)
        {
            cin >> py[i] >> v;
            b[py[i]] = v;
        }
        work();
        for(i=1; i<=kx; i++)
        {
           a[px[i]] = aa[px[i]];
        }
        for(i=1; i<=ky; i++)
        {
           b[py[i]] = bb[py[i]];
        }
    }
    cout << ans << endl;
    return 0;
}
