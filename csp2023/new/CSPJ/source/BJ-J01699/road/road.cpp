#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, d;
int ds[100010], v[100010];
int sum[100010];
int f[N][N * 10];
int minn = 0x3f3f3f3f, id = -1;
int gets(int a, int b)
{
    if(a % b == 0) return (a / b);
    return (a / b) + 1;
}
int dfs(int u, int la, int co)
{
    //cout << u << ' ' << la << ' ' << co << endl;
    if(f[u][la] != -1) return f[u][la] + co;
    if(u == n) return co;
    int ans = 0x3f3f3f3f;
    for(int i = u + 1; i <= n; i ++ ) 
    {
        int l = sum[i - 1] - sum[u - 1] - la;
        int t = gets(l, d);
        //cout << "   " << l << ' ' <<  t << endl;
        ans = min(ans, dfs(i, t * d - l, co + t * v[u]));
    }
    f[u][la] = ans - co;
    return ans;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(f, -1, sizeof f);
    cin >> n >> d;
    for(int i = 1; i < n; i ++) cin >> ds[i];
    sum[1] = ds[1];
    for(int i = 2; i < n; i ++) sum[i] = sum[i - 1] + ds[i];
    for(int i = 1; i < n; i ++) cin >> v[i];
    for(int i = 1; i < n; i ++)
        if(v[i] < minn)
        {
            minn = v[i];
            id = i;
        }
    if(id == 1 && n > 1000) cout << gets(sum[n - 1], d) * minn << endl; 
    else cout << dfs(1, 0, 0) << endl;
    return 0;
} 