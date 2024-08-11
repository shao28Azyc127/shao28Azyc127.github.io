#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int n;
char a[N];
int fa[N];
ll dp[N],ans=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=getchar();
        while(a[i]<'a'||a[i]>'z') a[i]=getchar();
        fa[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) fa[i]=i-2;
        else{
            int j=fa[i-1];
            while(fa[j]!=j&&a[j]!=a[i]) j=fa[j];
            if(a[j]==a[i]) fa[i]=j-1;
        }
        if(fa[i]==i) dp[i]=0;
        else dp[i]=dp[fa[i]]+1;
        ans+=dp[i];
        //cout<<fa[i]<<" "<<dp[i]<<"\n";
    }
    cout<<ans;
    return 0;
}

