#include <bits/stdc++.h>
using namespace std;

int n , m , k , mp[10003][10003] = {} , a , b , c , ans = 1e9;

void dfs (int p , int t)
{
    if (p == n)
    {
        ans = min(ans , t);
        return;
    }
    for (int i = 1 ;i <= n ; i++)
    {
        if (mp[p][i] != -1) dfs(i , mp[p][i]);
    }
}

int main()
{
    freopen("bus.in" , "r" , stdin);
    freopen("bus.out" , "w" , stdout);
    cin >> m >> n >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            mp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n ; i++)
    {
        cin >> a >> b >> c;
        mp[a][b] = c;
    }
    dfs(1 , 0);
    if (ans == 1e9) cout << -1;
    else cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
