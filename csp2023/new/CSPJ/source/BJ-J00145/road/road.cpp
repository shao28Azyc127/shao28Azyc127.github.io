#include<bits/stdc++.h>
#define int long long
using namespace std;
long long v[100010],a[100010],d,s[100010],ans,vis[100010];
long long n;
/*struct node{
    int cost,oil;
}dp[100010];*/
long long val(int x,int y,int w){
    if(s[y]-s[x]<=w) return 0;
    else{
        int f=(s[y]-s[x]-w)/d;
        if(f*d<s[y]-s[x]-w) f++;
        return f;
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++) cin>>v[i],s[i+1]=s[i]+v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        vis[i]=i;
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]){
                vis[i]=j;
                break;
            }
        }
    }
    int x=1,k=0;
    while(x<n){
        if(vis[x]==x){
            ans+=val(x,n,k)*a[x];
            x=n;
        }
        else{
            ans+=val(x,vis[x],k)*a[x];
            x=vis[x];
            k=val(x,vis[x],k)*d-(s[vis[x]]-s[x]-k);
        }
    }
    cout<<ans;
    return 0;
}
