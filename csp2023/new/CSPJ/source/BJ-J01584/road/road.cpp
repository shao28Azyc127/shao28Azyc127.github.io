#include<bits/stdc++.h>
using namespace std;
int n,d,ans=1e9+5,sum=0;
int u[100005];
int a[100005];
void dfs(int p,int oil,int money){
    if(p==n){
        ans=min(money,ans);
        return;
    }
    if(money>ans){
        return;
    }
    for(int i=0;i<=(sum/d);i++){
        if(oil+i*d>=u[p]){
            dfs(p+1,oil-u[p]+i*d,money+a[p]*i);
        }
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>u[i];
        sum+=u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
