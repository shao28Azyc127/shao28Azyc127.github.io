#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
long long n, a[MAXN+5];
long long ans = 0;
string s;

long long mi(long long x)
{
    long long ans = 0;
    for(long long i = 1; i <= x; i+=2)
        ans += x - i;
    return ans;
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    while(1)
    {
        long long cnt = 1, len = 1;
        for(long long i = 1; i <= n; i++)
        {
            if(s[i] == s[i-1])
            {
                cnt++;
            }
            else{
                a[len] = cnt;
                len++;
                ans += mi(cnt);
                if(cnt % 2 != 0)
                    cnt--;
                //cout << i << endl;
                i--;
                if(cnt > 1)
                {
                    for(int j = i-1; j+cnt <= n; j++)
                    {
                        s[j] = s[j+cnt];
                    }
                    n -= cnt;
                }
                cnt = 1;
                i++;
            }
        }
        long long deff = 1;
        for(long long i = 1; i < n; i++)
        {
            if(a[i] > 1 && a[i+1] > 1)
            {
                deff++;
            }
            if(a[i] <= 1)
            {
                ans += mi(deff);
                deff = 1;
            }
        }
        memset(a, 0, sizeof(a));
        //for(long long i = 0; i <= n; i++)cout << s[i];
        bool vis = false;
        for(long long i = 1; i <= n; i++)
        {
            if(s[i] == s[i-1])
            {
                vis = false;
                break;
            }
            else{
                vis = true;
            }
        }
        if(vis == true)
        {
            break;
        }
        if(n == 0)
        {
            break;
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
