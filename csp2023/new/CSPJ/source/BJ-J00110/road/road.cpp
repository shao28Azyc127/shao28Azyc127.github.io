#include<bits/stdc++.h>
using namespace std;
int n, d, flag;
long long dp[100010][1000];
int tst[100010];//to station
int v[100010];

int main(){
    /*ios::sync_with_stdio(false);*/
    freopen("road.in","r", stdin);
    freopen("road.out","w", stdout);
    cin >> n >> d;
    for(int i = 2; i<=n;i++){
        cin >> tst[i];
    }
    for(int i = 1; i<=n; i++){
        cin >> v[i];
    }
    for(int i = 1; i<=n; i++){
        dp[i+1][0] = 2147483647;
        dp[1][i] = 2147483647;
    }
    dp[0][0] = 0;
    for(int i = 1; i<=min(n, 1000); i++){
        int ndw = 0, nowv = v[1], more = 0;
        //cout << "I:"<< i << endl;
        for(int j = 2; j<=n; j++){
            //cout << "  J:" << j << " more:" << more << " tst:" << tst[j];
            ndw = tst[j]-more;

            if(ndw-ndw/d*d>0){
                ndw = ndw/d+1;
            }else{
                ndw = ndw/d;
            }
            //cout << "   ndw:" << ndw << "   v.j-1:" << v[j-1];
            //dp[j][i] = min(dp[j-1][i]+ndw*nowv,dp[j-1][i-1]+ndw*v[i-1]);
            //cout << " %%%%%%%%%" << dp[j][i-1]<< "  %%" << dp[j-1][i-1]+ndw*v[i-1] << "  %%" << dp[j-1][i]+nowv*ndw;

            if(dp[j][i-1]>dp[j-1][i-1]+ndw*v[i-1]){
                dp[j][i] = dp[j-1][i-1]+ndw*v[j-1];
                flag = 1;
            }else{
                dp[j][i] = dp[j][i-1];
            }
            if(dp[j-1][i]+nowv*ndw<dp[j][i]){
                dp[j][i] = dp[j-1][i]+nowv*ndw;
            }
            if(flag == 1){
                nowv = v[j-1];
                flag = 0;
            }
            more = ndw*d+more-tst[j];
            //cout << "  " << dp[j][i] << endl;
        }
    }
    cout << dp[n][min(n, 1000)] << endl;
    return 0;
}
