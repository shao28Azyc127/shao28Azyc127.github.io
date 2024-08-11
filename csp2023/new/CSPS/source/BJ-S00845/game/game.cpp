#include<bits/stdc++.h>
// #pragma GCC optimize(2)
#define ll long long
using namespace std;
const int N=2000005;
inline char readchar(){
    char xx=0;
    while(xx<'a' || xx>'z') xx=getchar();
    return xx;
}
int n;
int s[N];
int pre[N],cur[N][26];
ll dp[N],ans=0;
int now[N],nowtot=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        s[i]=readchar()-'a';
    }
    for(int j=0;j<=n;j++){
        for(int i=0;i<26;i++){
            cur[j][i]=0;
        }
    }
    pre[1]=0;
    cur[1][s[1]]=1;
    for(int i=2;i<=n;i++){
        pre[i]=0;
        if(nowtot>0 && now[nowtot]==s[i]) nowtot--;
        else now[++nowtot]=s[i];
        if(s[i]==s[i-1]){
            pre[i]=i-1;
        }
        else if(pre[i-1]){
            pre[i]=cur[i-1][s[i]];
        }
        int p=max(pre[i]-1,0);
        for(int j=0;j<26;j++){
            cur[i][j]=((j==s[i])?i:cur[pre[i]-1][j]);
        }
    }
    // for(int i=2;i<=n;i++) cout<<pre[i]<<" ";
    // cout<<endl;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(pre[i]) dp[i]=dp[pre[i]-1]+1;
        else dp[i]=0;
        ans+=dp[i];
    }
    cout<<ans<<endl;
    return 0;
}