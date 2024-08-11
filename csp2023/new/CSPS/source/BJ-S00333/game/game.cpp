#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2000010;
int n;
char s[MAXN];
int g[MAXN],f[MAXN][26],dp[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s+1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int c=s[i]-'a';
        g[i]=f[i-1][c];
        if(g[i])for(int j=0;j<26;j++)f[i][j]=f[g[i]-1][j];
        f[i][c]=i;
        if(g[i])dp[i]=dp[g[i]-1]+1;
        ans+=dp[i];
    }
    cout<<ans;
    return 0;
}
