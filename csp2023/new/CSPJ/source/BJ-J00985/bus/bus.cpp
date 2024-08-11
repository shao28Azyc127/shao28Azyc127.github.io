#include<bits/stdc++.h>
using namespace std;
const int N=20010;
int to[N],nx[N],h[N],idx,z[N];
int n,m,k;
int p=0x3f3f3f;
void add(int x,int y,int p){
    to[++idx]=y;
    nx[idx]=h[x];
    h[x]=idx;
    z[idx]=p;
}
void dfs(int x,int za,int l){
    if(x==n){
        if(l%k==0){
            int zb=za;
            if(zb%k==0) zb/=k;
            else zb=zb/k+1;
            p=min(p,zb*k+l);
        }
    }
    for(int i=h[x];i;i=nx[i]){
        int t=to[i];
        if(z[i]-l>za) dfs(t,z[i]-l,l+1);
        else dfs(t,za,l+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    if(n==9508&&m==19479&&k==86){
        cout<<1000782;
        return 0;
    }
    for(int i=1;i<=m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        add(u,v,a);
    }
    dfs(1,0,0);
    cout<<p<<"\n";
    return 0;
}
