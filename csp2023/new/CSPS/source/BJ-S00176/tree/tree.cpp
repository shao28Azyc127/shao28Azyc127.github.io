#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,h[100005],b[100005],f[100005],maxx,c[100005],a[100005],n,x,y,s[100005],vis[100005],t;
vector<ll>vec[100005];
ll jx(ll i,ll d){
    h[i]=0;
    while(h[i]<a[i]){
        if(b[i]+d*c[i]>1){
           h[i]+=b[i]+d*c[i];
        }
        else{
            h[i]++;
        }
        d++;
    }
    d-=1;
    return d;
}
void dfs(ll x,ll d,ll cnt){
    if(cnt==n+1&&s[1]==jx(1,1)){
       ll maxx=0;
       for(int i=1;i<=n;i++){
           if(s[i]>maxx){
              maxx=s[i];
           }
       }
       if(maxx<ans){
          ans=maxx;
       }
       return;
    }
    if(s[x]>ans||s[1]!=jx(1,1)){
        return;
    }
    for(int i=0;i<vec[x].size();i++){
        vis[vec[x][i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1&&f[i]==0){
            f[i]=1;
            s[i]=jx(x,d);
            dfs(i,d+1,cnt+1);
            f[i]=0;
            s[i]=0;
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    t=jx(1,1);
    if(n<=500){
       vis[1]=1;
       s[1]=jx(1,1);
       ans=1e9+7;
       dfs(1,1,1);
    }
    cout<<ans;
    return 0;
}
