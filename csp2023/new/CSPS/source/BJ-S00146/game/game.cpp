#include <bits/stdc++.h>
using namespace std;
int n;
char a[8010];
bool dp[810][810];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%s",&n,a);
    for (int i=1; i<=n; i++){
        if (a[i-1]==a[i])dp[i][i+1]=1;
    }
    for (int len=3; len<=n; len++){
        for (int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            for (int k=l; k<r; k++){
                dp[l][r]|=dp[l][k]&&dp[k+1][r];
            }
            if (a[l-1]==a[r-1]) dp[l][r]|=dp[l+1][r-1];
        }
    }
    int ans=0;
    for (int l=1; l<=n;l++){
        for (int r=l+1; r<=n; r++){
            ans+=(dp[l][r]?1:0);
        }
    }
    cout<<ans<<endl;
    return 0;
}
