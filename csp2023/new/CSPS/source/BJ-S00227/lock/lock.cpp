#include<bits/stdc++.h>
using namespace std;

int n, t;
int a[10];
bool vis[100005];
bool check(int x)
{
    int cnt = 0, y = x;
    while(y)    cnt += (y % 10 != 0), y /= 10;
    if(cnt == 1)    return true;
    if(cnt > 2) return false;
    while(x)
    {
        if(x % 10 && (x / 10) % 10 == x % 10) return true;
        x /= 10;
    }
    return false;
}
int dis(int a, int b)
{
    int cnt = 0, power = 1;
    if(a > b)   swap(a, b);
    while(a || b)
    {
        int as = a % 10, bs = b % 10;
        if(as < bs) cnt += power * (bs - as);
        else if(as > bs)    cnt += power * (bs + 10 - as);
        power *= 10, a /= 10, b /=10;
    }
    return cnt;
}
bool compare(int x)
{
    for(int i = 1; i <= n; i++)
        if(!check(dis(x, a[i])))
            return false;
    return true;
}
int ans = 0;
int main()
{
    ios::sync_with_stdio(false);
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 5; j++)
            cin >> t, a[i] = a[i] * 10 + t;
    for(int i = 0; i <= 99999; i++)
        if(compare(i))
            vis[i] = 1;
    for(int i = 0; i <= 99999; i++) ans += (int)vis[i];
    cout << ans;
    return 0;
}
/*
1
0 0 1 1 5
*/
