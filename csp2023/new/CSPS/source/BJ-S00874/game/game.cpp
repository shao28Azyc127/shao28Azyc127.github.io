#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int l=0;l<n;l++){
        string dp[200005];
        dp[l]=s[l];
        for(int r=l+1;r<n;r++){
            if(dp[r-1][dp[r-1].size()-1]==s[r]){
                dp[r]=dp[r-1];
                dp[r].erase(dp[r-1].size()-1);
                if(dp[r].empty()) ans++;
            }
            else dp[r]=dp[r-1]+s[r];
        }
    }
    cout<<ans;
    return 0;
}
