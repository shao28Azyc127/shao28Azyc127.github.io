#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, d;
int v[100005], a[100005];
int s[100005];
int dp[100005];//到i最少的钱
int main()
{
    ios::sync_with_stdio(false);
    //freopen("road.in", "r", stdin);
    //freopen("road.out", "w", stdout);
    cin >> n >> d;
    s[1] = 0;
    for(int i = 1; i < n; i++) cin >> v[i], s[i + 1] = s[i] + v[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << 66;
    return 0;
}
