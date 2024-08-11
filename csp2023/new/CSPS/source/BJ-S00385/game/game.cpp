#include <bits/stdc++.h>
using namespace std;
const int maxn=1010;
int dp[maxn][maxn],g[maxn][maxn];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    memset(dp,0,sizeof(dp));
    memset(g,0,sizeof(g));
    int n; string str; cin>>n>>str;
    for(int i=n-1;i>=0;i--) str[i+1]=str[i];
    for(int i=1;i<n;i++)
        if(str[i]==str[i+1]) dp[i][i+1]=g[i][i+1]=1;
    for(int len=2;len<=n;len++)
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1,flag=0;
            for(int k=i;k<j;k++){
                if(g[i][k]&g[k+1][j]) flag=1;
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
            if((str[i]==str[j]&&g[i+1][j-1])||flag){
                g[i][j]=1; dp[i][j]++;
            }
        }
    cout<<dp[1][n]<<endl;
    fclose(stdin); fclose(stdout);
    return 0;
}
