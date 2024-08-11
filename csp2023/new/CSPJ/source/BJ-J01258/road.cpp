#include <bits/stdc++.h>
using namespace std;
int dp[100000],price[100000],dist[100000],n,d;
int main(void){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=0;i<n-1;i++){
        cin >> dist[i];
    }
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            dp[i]=min(dp[i-j]+(dist[i]*price[i]),dp[i]);
        }
    }
    cout << dp[n-1];
    return 0;
}
