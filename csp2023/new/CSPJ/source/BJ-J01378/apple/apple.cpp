#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int res = 0, ans, n;
bool flag = true;
int main()
{
    freopen("apple.in", "r", stdin);
    
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(n >= 3)
    {
        res++;
        if(n % 3 == 1 && flag)
        {
            flag = false;
            ans = res;
        }
        n -= (n + 2) / 3;
    }
    if(flag) cout << res + n << ' ' << res + n;
    else cout << res + n << ' ' << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
