#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[10][6], t[105][6], cnt, ans;
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ll n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= 5; ++j)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= 9; ++i)
    {
        for(int j = 1; j <= 5; ++j)
        {
            copy(a[1] + 1, a[1] + 6, t[cnt] + 1);
            t[cnt++][j] = (a[1][j] + i) % 10;
        }
    }
    for(int i = 1; i <= 9; ++i)
    {
        for(int j = 1; j <= 4; ++j)
        {
            copy(a[1] + 1, a[1] + 6, t[cnt] + 1);
            t[cnt][j] = (a[1][j] + i) % 10;
            t[cnt++][j + 1] = (a[1][j + 1] + i) % 10;
        }
    }
    for(int i = 0; i < cnt; ++i)
    {
        bool v = 0;
        for(int j = 2; j <= n; ++j)
        {
            int f = 0;
            for(int k = 1; k <= 5; ++k)
            {
                if(f && a[j][k] != t[i][k] && (f > 10086 || k - f > 1 || (a[j][k] - t[i][k] + 10) % 10 != (a[j][f] - t[i][f] + 10) % 10))
                {
                    f = 114514;
                    break;
                }
                else if(a[j][k] != t[i][k] && f)
                {
                    f = 10086 + k;
                }
                else if(a[j][k] != t[i][k])
                {
                    f = k;
                }
            }
            if(f == 114514 || f == 0)
            {
                v = 1;
                break;
            }
        }
        if(!v)
        {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
