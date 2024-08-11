#include<iostream>
#include<cstdint>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

string s;
int n;
vector<vector<bool>> dp;
uint64_t ans=0;

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    dp.resize(n);
    for(int i=0;i<n;i++){
        dp[i].resize(n,0);
        if(i>0){
            dp[i-1][i]=(s[i-1]==s[i]);
            ans+=dp[i-1][i];
        }
    }

    for(int l=3;l<=n;l++){
        int j;
        for(int i=0;(j=i+l-1)<n;i++){
            dp[i][j]=(dp[i+1][j-1]&&(s[i]==s[j]));
            for(int k=i+1;(k+1<=j-1)&&(!dp[i][j]);k++){
                dp[i][j]=(dp[i][j]||(dp[i][k]&&dp[k+1][j]));
            }
            if(dp[i][j])ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}