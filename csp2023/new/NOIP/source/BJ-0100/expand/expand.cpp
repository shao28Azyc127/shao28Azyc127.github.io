#include<bits/stdc++.h>
#define int long long
using namespace std;
bool vis[2001][2001],ans[2001][2001];
int c,n,m,q,p,v,kx,ky,x[2001],y[2001],xx[2001],yy[2001];
vector<int>vx,vy;
bool solve1(int cx,int cy){
    if(vis[cx][cy]){
        return ans[cx][cy];
    }
    vis[cx][cy]=1;
    return ans[cx][cy]=cx<n&&x[cx+1]>y[cy]&&solve1(cx+1,cy)||cy<m&&x[cx]>y[cy+1]&&solve1(cx,cy+1)||cx<n&&cy<m&&x[cx+1]>y[cy+1]&&solve1(cx+1,cy+1);
}
bool solve2(int cx,int cy){
    if(vis[cx][cy]){
        return ans[cx][cy];
    }
    vis[cx][cy]=1;
    return ans[cx][cy]=cx<n&&x[cx+1]<y[cy]&&solve2(cx+1,cy)||cy<m&&x[cx]<y[cy+1]&&solve2(cx,cy+1)||cx<n&&cy<m&&x[cx+1]<y[cy+1]&&solve2(cx+1,cy+1);
}
bool solve(){
    memset(vis,0,sizeof(vis));
    vis[n][m]=ans[n][m]=1;
    if(x[1]>y[1]&&solve1(1,1)){
        return 1;
    }
    memset(vis,0,sizeof(vis));
    vis[n][m]=ans[n][m]=1;
    return x[1]<y[1]&&solve2(1,1);
}
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        xx[i]=x[i];
    }
    for(int i=1;i<=m;i++){
        cin>>y[i];
        yy[i]=y[i];
    }
    cout<<solve();
    while(q--){
        memset(ans,0,sizeof(ans));
        cin>>kx>>ky;
        while(kx--){
            cin>>p>>v;
            x[p]=v;
            vx.push_back(p);
        }
        while(ky--){
            cin>>p>>v;
            y[p]=v;
            vy.push_back(p);
        }
        cout<<solve();
        for(auto&it:vx){
            x[it]=xx[it];
        }
        for(auto&it:vy){
            y[it]=yy[it];
        }
    }
    cout<<endl;
}
