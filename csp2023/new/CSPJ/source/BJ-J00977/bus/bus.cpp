#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e4+5;
int n,m,k;
int hh[N],nx[M],to[M],wi[M],idx;
void add(int u,int v,int w){
    idx++;
    to[idx]=v;
    wi[idx]=w;
    nx[idx]=hh[u];
    hh[u]=idx;
}
int vis[N][105];
struct nd{
    int x,stp;
};

bool chk(int x){
    idx++;
    queue<nd> q;
    q.push({n,x*k});
    vis[n][0]=idx;
    while(q.size()){
        int u=q.front().x;
        int d=q.front().stp;
        q.pop();
        if(u==1&&(d%k)==0) return 1;
        if(d==0) continue;
        for(int i=hh[u];i;i=nx[i]){
            int v=to[i];
            int w=wi[i];
            if(w>d)continue;

            if(vis[v][(d-1)%k]==idx) continue;
            vis[v][(d-1)%k]=idx;
            q.push({v,(d-1)});
        }
    }
    return 0;
}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(v,u,w);
    }

    int L=1,R=2000003/k+3,mid;
    while(L<R){
        mid=L+R>>1;
        if(chk(mid))
            R=mid;
        else L=mid+1;
    }
    cout<<L*k<<endl;

    return 0;
}
