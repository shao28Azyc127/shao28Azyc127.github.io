#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int n,ans;
char a[N];
int f[N],g[N],h[N],dp[N][26];
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld%s",&n,a+1);
    for(int i=1;i<=n;i++) g[i]=1e9;
    for(int i=1;i<n;i++){
        if(a[i]==a[i+1]){
            g[i]=i+1,f[i]=1;
        }
    }
    for(int i=n-1;i>=1;i--){
        if(g[i+1]==1e9) continue;
        int x=g[i+1]+1;
        while(x<=n&&a[i]!=a[x]) x=g[x]+1;
        if(x>n) continue;
        g[i]=min(g[i],x);
        for(int j=0;j<=25;j++) dp[i][j]=dp[x][j];
        dp[i][a[i]-'a']++;
    }
    for(int i=n;i>=1;i--){
        if(g[i]==1e9) continue;
        f[i]=f[g[i]+1]+1;
    }
    for(int i=1;i<=n;i++){
        if(g[i]==1e9) ans+=dp[i][a[i]-'a'];
        else ans+=f[i];
    }
    printf("%lld\n",ans);
    return 0;
}

