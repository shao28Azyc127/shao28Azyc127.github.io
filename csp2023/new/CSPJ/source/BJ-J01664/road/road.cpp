#include<bits/stdc++.h>

using namespace std;

long long n,d,v[100005],a[100005],s[100005],dp[100005][1005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    s[1] = 0;
    cin >> n >> d;
    memset(dp,0x3f,sizeof(dp));
    for(int i = 1;i < n;i++){
        cin >> v[i];
        s[i + 1] = s[i] + v[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 0;i <= ceil(s[n]/d);i++){
        dp[1][i] = a[1] * i;
    }
    long long l = 0;
    for(int i = 2;i<=n;i++){
        for(int j = 0;j <= ceil(s[n]/d);j++){
            for(int k = 0;k <= ceil(s[n]/d);k++){
                if((l + k)*d >= s[i]){
                    dp[i][j] = min(j * a[i] + dp[i-1][k],dp[i][j]);
                }
            }
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}
