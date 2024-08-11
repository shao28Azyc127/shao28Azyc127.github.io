#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, v[100010], a[100010];
int dp[100010];
double oil[100010];
const int inf = INT_MAX;
int d;
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for(int i = 2; i <= n; i++){
        int x;
        scanf("%lld", &x);
        v[i] = v[i-1] + x;
        dp[i] = inf;
    }
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    dp[1] = 0;
    oil[1] = 0;
    for(int i = 2; i <= n; i++){
        int mi = inf;
        int di;
        int fe;
        for(int j = 1; j < i; j++){
            int dis = v[i] - v[j];
            //cout << a[j] << endl;
            //cout << dis * 1.0 / d - oil[j] << endl;
            int fee = (dis * 1.0 / d - oil[j] > 0) ? ceil(dis * 1.0 / d - oil[j]) * a[j] : 0;
            //cout << i << ' ' << j << ' ' << dis << ' ' << fee << endl;
            dp[i] = min(dp[i], dp[j] + fee);
            if(dp[i] == dp[j]+fee){
                mi = j;
                di = dis;
                fe = fee;
            }
        }
        oil[i] = oil[mi];
        oil[i] += fe * 1.0 / a[mi];
        oil[i] -= di * 1.0 / d;
        //cout << "oil:" << oil[i]  << ' ' << fe * 1.0 / a[mi] << ' '  << di * 1.0 / d - oil[mi] << endl;
    }/*
    for(int i = 1; i <= n; i++){
        cout << dp[i] << ' ';
    }
    cout << endl;*/
    printf("%lld", dp[n]);
    return 0;
}
