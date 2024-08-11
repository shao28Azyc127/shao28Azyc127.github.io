#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
char c[100005];
char cx[15], cy[15], c2[15];
int a[15], b[15];
void f(int t)
{
    if(t != 0) cy[t] = cx[t];
    if(t == n)
    {
        for(int i = 1;i <= m;i++)
        {
            if(c2[i] != '+' && c2[i] != '-')
            {
                cy[a[i]] = c2[i];
            }
            else if(c2[i] == '+')
            {
                cy[a[i]] = cy[b[i]];
            }
            else
            {
                char c3 = cy[b[i]];
                if(c3 == 'T') cy[a[i]] = 'F';
                else if (c3 == 'f') cy[a[i]] = 'T';
                else cy[a[i]] = 'U';
            }
        }
        bool fl = true;
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            if(cy[i] != cx[i]) fl = false;
            if(cx[i] == 'U') cnt++;
        }
        if(fl) ans = min(ans, cnt);
        return ;
    }
    cx[t + 1] = 'T';
    f(t + 1);
    cx[t + 1] = 'F';
    f(t + 1);
    cx[t + 1] = 'U';
    f(t + 1);
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int T;
    cin >> n;
    cin >> T;
    for(int j = 1;j <= T;j++)
    {
        ans = 0;
        cin >> n >> m;
        if(n <= 10)
        {
            ans = 10;
            for(int i = 1;i <= m;i++)
            {
                cin >> c2[i];
                if(c2[i] != '+' && c2[i] != '-')
                {
                    cin >> a[i];
                }
                else
                {
                    cin >> a[i] >> b[i];
                }
            }
            f(0);
            cout << ans;
            continue;
        }
        for(int i = 1;i <= m;i++)
        {
            char c1;
            int k;
            cin >> c1 >> k;
            if(c1 != '+') c[k] = c1;
            else
            {
                int l;
                cin >> l;
                c[k] = c[l];
            }
        }
        for(int i = 1;i <= n;i++)
        {
            if(c[i] == 'U') ans++;
            c[i] = '1';
        }
        cout << ans;
    }
    return 0;
}