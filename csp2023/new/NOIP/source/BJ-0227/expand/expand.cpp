#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,q,ans,x[500005],y[500005],nx[500005],ny[500005];
void dfs(int i,int j){
    if(ans)return;
    if(1ll*(nx[i]-ny[j])*(nx[1]-ny[1])<=0)return;
    if(i<n)dfs(i+1,j);
    if(j<m)dfs(i,1+j);
    if(i<n&&j<m)dfs(i+1,j+1);
    if(i==n&&j==m)ans=1;
}
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){cin>>x[i];nx[i]=x[i];}
    for(int j=1;j<=m;j++){cin>>y[j];ny[j]=y[j];}
    if(1ll*(nx[1]-ny[1])*(nx[n]-ny[m])<=0)ans=0;
    else{
        dfs(1,1);
    }
    cout<<ans;
    while(q--){
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=n;i++)nx[i]=x[i];
        for(int i=1;i<=m;i++)ny[i]=y[i];
        for(int i=1;i<=kx;i++){
            int p,q;
            cin>>p>>q;
            nx[p]=q;
        }
        for(int i=1;i<=ky;i++){
            int p,q;
            cin>>p>>q;
            ny[p]=q;
        }ans=0;
        if(1ll*(nx[1]-ny[1])*(nx[n]-ny[m])<=0)ans=0;
        else{
            dfs(1,1);
        }
        cout<<ans;
    }
    return 0;
}
