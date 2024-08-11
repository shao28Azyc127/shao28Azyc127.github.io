#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,i,j,k,L;
string s;
bool dp[8005][8005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>s;
    s=" "+s;
    for(i=1;i<n;i++){
        dp[i][i+1]=(s[i]==s[i+1]);
    }
    for(L=4;L<=n;L+=2){
        for(i=1;i+L-1<=n;i++){
            j=i+L-1;
            if(s[i]==s[j]&&dp[i+1][j-1]){
                dp[i][j]=1;
                continue;
            }
            for(k=i+1;k<j;k+=2){
                if(dp[i][k]&&dp[k+1][j]){
                    dp[i][j]=1;
                    break;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            if(dp[i][j]) ans++;
        }
    }
    cout<<ans;
    return 0;
}