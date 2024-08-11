#include<bits/stdc++.h>
using namespace std;
int n;
char c;
int a[1000005];
int dp[8005][8005];
long long ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>c;
        a[i] = c - 'a' + 1;
    }
    if(n <= 8000){
        for(int i = 1;i <= n;i++){
            int lastj = 1;
            if(a[i - 1] == a[i])
                ans++, dp[i - 1][i] = 1;
            for(int j = i - 3;j >= 1;j -= 2){//--1 -> - -= 2
                if(a[i] == a[j] && dp[j + 1][i - 1]){
                    ans++, dp[j][i] = 1;
                    lastj = j;
                    continue;
                }
                if(dp[j][lastj - 1]){
                    ans++, dp[j][i] = 1;
                    lastj = j;
                }
            }
        }
        cout<<ans<<endl;
        //cout<<endl;
    }
    return 0;
}


