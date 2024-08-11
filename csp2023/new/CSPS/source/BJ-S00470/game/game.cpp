#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int dp[2000006],s[2000006],f[2000006],nb[26],det[2000007];
string st;
int chck(int x,int y){
    if((y-x)%2==0) return 0;
    if(det[y-1]>x+1) return 0;
    return 1;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>st;
    for(int i=1;i<=n;++i){
        s[i]=st[i-1]-'a';
        dp[i]=nb[s[i]];
        nb[s[i]]=i;
        det[i]=i;
    }
    for(int i=1;i<=n;++i){
        if(dp[i]==0) continue;
        if(chck(dp[i],i)){
            f[i]=f[dp[i]-1]+1;
            if(f[dp[i]-1]==0) det[i]=dp[i];
            else det[i]=det[dp[i]-1];
        }
    }
    for(int i=1;i<=n;++i){
        ans+=f[i]*1ll;
    }
    printf("%lld",ans);
    return 0;
}
