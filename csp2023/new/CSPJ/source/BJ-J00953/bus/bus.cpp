#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,times,need[10010],ans;
int u[20010],v[20010],a[20010];
int s[10010][10010];
void dfs(int x,int y,int z){
    if(x==n){
        if(z%k==0){
            if(y%k==0) ans=min(ans,y);
            else{
                int jntm=y%k;
                jntm=k-jntm;
                //for(int i=1;i<=k;i++){
                //    if((jntm+i)%k==0){
                 //       jntm+=i;
                //       break;
                //    }
                //}
                ans=min(ans,y+jntm);
            }
        }
        return;
    }
    for(int i=x+1;i<=n;i++){
        if(s[x][i]!=0){
            if(y<s[x][i]-1) dfs(i,s[x][i]-1,z+1);
            else dfs(i,y+1,z+1);
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ans=1e9;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>a[i];
        s[u[i]][v[i]]=a[i]+1;
    }
    dfs(1,0,0);
    if(ans==1e9){
        cout<<"-1";
        return 0;
    }
    cout<<ans;
    return 0;
}
