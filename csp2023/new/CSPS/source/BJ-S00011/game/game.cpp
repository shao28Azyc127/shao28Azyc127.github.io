#include <bits/stdc++.h>
#define int long long
#define MAXN 2000005
#define MAXL 29
#define lti(x) ((x) - 'a' + 1)
#define itl(x) ((x) + 'a' - 1)
using namespace std;
int n, cnt[MAXN], ans, bk[MAXN], lst[MAXL];
string s;
/*
int bzfro(int now, int want, int k)
{
    cout << now << " " << want << " " << k;
    if (k < 0)
    {
        cout << " return\n";
        return now;
    }
    cout << " " << bk[now][k];
    if (bk[now][k] - 1 >= want)
    {
        cout << " go " << bk[now][k] << endl;
        return bzfro(bk[now][k] - 1, want, k - 1);
    }
    cout << " go " << now << endl;
    return bzfro(now, want, k - 1);
}
*/
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    s = " " + s;
    /*
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 0; j++)
        {
            bk[i][j] = i + 1;
        }
    }
    */
    for (register int i = 1; i <= n; i++)
    {
        if (lst[lti(s[i])] == 0)
        {
            lst[lti(s[i])] = i;
            continue;
        }
        register int fro = i;
        // int fro = bzfro(i - 1, lst[lti(s[i])], 23);
        while (fro != 0)
        {
            // cout << fro << " ";
            if (s[fro - 1] == s[i])
            {
                break;
            }
            fro = bk[fro - 1];
        }
        // cout << endl;
        if (s[fro - 1] == s[i])
        {
            bk[i] = fro - 1;
        }
        /*
        cout << i << ": " << fro << endl;
        if (fro == lst[lti(s[i])])
        {
            bk[i][0] = lst[lti(s[i])];
            int k = 1;
            while (bk[bk[i][k - 1] - 1][k - 1] != bk[i][k - 1])
            {
                bk[i][k] = bk[bk[i][k - 1] - 1][k - 1];
                k++;
            }
        }
        lst[lti(s[i])] = i;
        */
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            cout << bk[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    for (register int i = 1; i <= n; i++)
    {
        if (bk[i])
        {
            cnt[i] = cnt[bk[i] - 1] + 1;
            ans += cnt[i];
        }
        // cout << cnt[i] << " ";
    }
    // cout << endl;
    cout << ans;
    return 0;
}
