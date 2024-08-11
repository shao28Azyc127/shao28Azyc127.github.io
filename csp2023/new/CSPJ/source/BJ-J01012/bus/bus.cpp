#include<bits/stdc++.h>//O(a/k*n*k)=O(an)=QWQ
#define pb emplace_back
#define ll long long
#define ull unsigned long long
using namespace std;
int n,m,k,u,v,a,vis[10005][105],A=1,maxa,ans=99999999;
vector<int>e[10005],t[10005];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    while(m--){
        cin>>u>>v>>a;
        e[u].pb(v);
        t[u].pb(a);
        if(a!=0)A=0;
        maxa=max(maxa,a);
    }
    for(int i=0;i<=(A==1?0:maxa);i+=k){
        memset(vis,0,sizeof vis);
        queue<int>qx,qdis;
        qx.push(1),qdis.push(i);
        vis[1][0]=1;
        while(!qx.empty()){
            int x=qx.front(),dis=qdis.front();
            qx.pop();qdis.pop();
            for(int i=0;i<e[x].size();i++){
                int y=e[x][i],z=t[x][i];
                if(dis>=z&&vis[y][(dis+1)%k]==0){
                    qx.push(y);
                    qdis.push(dis+1);
                    vis[y][(dis+1)%k]=1;
                    if(y==n&&(dis+1)%k==0){
                        ans=min(ans,dis+1);
                        while(!qx.empty())qx.pop();
                        break;
                    }
                }
            }
        }
    }
    if(ans==99999999)cout<<-1;
    else cout<<ans;
    return 0;
}
//I think my score is : 100+80+100+50=330  by wanlexi at 2023-10-21-Sat-11:11