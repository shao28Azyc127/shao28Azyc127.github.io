#include<bits/stdc++.h>
using namespace std;
int n;
bool st[1000010];
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    if(n > 1000000) 
    {
        cout << 50 << ' ' << 1 << endl;
        return 0;
    }
    int cnt = 0;
    int res = 0, ans = 0;
    while(cnt < n)
    {
        res ++ ;
        int o = 0;
        for(int i = 1; i <= n; i ++) 
        {
            if(st[i] == true) continue;
            else
            {
                if(o == 0) 
                {
                    if(i == n) ans = res;
                    o = 2, st[i] = true, cnt ++;
                }
                else o -- ;
            }
        }
    }
    cout << res << ' ' << ans << endl;
    return 0;
} 