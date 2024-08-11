# include <bits/stdc++.h>
using namespace std;
int n,d;
int v[100005];
int a[100005];
int dp[10005][10005];
int h[10005];
int js(double t,int i){
    int h = int(double(v[i]/d)-t);
    if(double(double(t+h)*h)<v[i]) h++;
    return (int)h;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int v_num = 0;
    int a_min = 1e9;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        v_num += v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a_min = min(a_min,a[i]);
    }
    if(a_min==a[1]){
        int x = v_num/d;
        if(x*d<v_num) x++;
        printf("%d",x*a[1]);
        return 0;
    }
    double t = 0;
    dp[1][1] = 0;
    for(int i=1;i<=n-1;i++){
        h[i] = js(t,i);
        t = t + double(h[i]);
        t = t - double(v[i]/double(d));
    }
    for(int j=2;j<=n;j++){
        dp[1][j] = dp[1][j-1]+h[j-1]*a[1];
    }
    for(int i=2;i<=n-1;i++){
        int j = i+1;
        dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]+a[i]*h[j-1]);
        for(int j = i+2;j<=n;j++){
            dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1]+a[i]*h[j-1],dp[i][j-1]+a[i]*h[j-1]));
        }
    }
    cout<<dp[n-1][n];
    return 0;
}
