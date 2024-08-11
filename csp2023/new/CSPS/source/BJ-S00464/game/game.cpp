#include <bits/stdc++.h>
using namespace std;
const int N=8000+10;
int dp[N][N],n,m;
char str[N];

void test(){
    cin>>n;
    if(n<=800){
        cin>>str+1;int ans=0;
        for(int i=1;i+1<=n;i++)if(str[i]==str[i+1])dp[i][i+1]=1,ans++;
        for(int i=4;i<=n;i+=2){
            for(int j=1;j+i-1<=n;j++){
                int k=j+i-1;
                if(str[j]==str[k]&&dp[j+1][k-1]){
                    dp[j][k]=1;
                }
                else for(int u=j+1;u+1<=k;u++){
                    if(dp[j][u]&&dp[u+1][k]){
                        dp[j][k]=1;break;
                    }
                }
                //cout<<j<<','<<k<<": "<<dp[j][k]<<endl;
                if(dp[j][k])ans++;
            }
        }
        cout<<ans<<endl;return;
    }
    cout<<0<<endl;
}

signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    test();
    return 0;
}
