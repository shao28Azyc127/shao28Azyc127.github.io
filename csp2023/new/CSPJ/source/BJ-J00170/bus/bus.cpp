#include<bits/stdc++.h>
using namespace std;

int l[21][21];
bool f[21];
int n,m,k;

int dfs(int beg,int ss){
    if(ss==n&&beg%k==0)
        return beg;
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(l[ss][i]<0x2f3f3f3f&&!f[i]&&beg>=l[ss][i]){
            f[i]=1;
            ans=min(ans,dfs(beg+1,i));
            f[i]=0;
        }
    }
    return ans;
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int ans=0x3f3f3f3f;
    memset(l,0x3f3f3f3f,sizeof(l));
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int u,v,a;
        cin>>u>>v>>a;
        l[u][v]=a;
    }
    f[1]=1;
    for(int i=0;i<m*2;i++){
        ans=min(ans,dfs(i,1));
    }
    if(ans>=0x2f3f3f3f)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
