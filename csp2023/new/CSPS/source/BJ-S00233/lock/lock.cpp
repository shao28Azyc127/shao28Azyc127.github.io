#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ll n, ans = 0;
    cin >> n;
    ll s[n][5], cnt[10];
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < 5; j++)
        {
            cin >> s[i][j];
        }
    }
    if(n == 1)
    {
        cout << "81" << endl;
        return 0;
    }
    while(n == 2)
    {
        for(ll i = 0; i < 5; i++)
        {
            if(s[0][i] != s[1][i]) ans += 10;
        }
        cout << ans << endl;
        return 0;
    }
    for(ll i = 0; i < 5; i++)//digit place
    {
        for(ll j = 0; j < n; j++)// different solution
        {
            cnt[s[j][i]]++;
            if(cnt[s[j][i]] > 1)
            {
                ans += 0;
                break;
            }
            ans += 10 - n;
        }
    }
    cout << ans << endl;
    return 0;
}