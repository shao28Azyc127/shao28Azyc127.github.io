#include<bits/stdc++.h>
using namespace std;
const int MAXN=500001;
int n,m,q;
int tx[MAXN],ty[MAXN],x[MAXN],y[MAXN];
int fax[MAXN],gax[MAXN],fbx[MAXN],gbx[MAXN],fay[MAXN],gay[MAXN],fby[MAXN],gby[MAXN];
bool solve1(int pn,int pm){
    if(pn<1||pm<1)return 1;
    if(x[fax[pn]]<y[fay[pm]])return solve1(fax[pn]-1,pm);
    if(x[gax[pn]]<y[gay[pm]])return solve1(pn,gay[pm]-1);
    return 0;
}
bool solve2(int pn,int pm){
    if(pn>n||pm>m)return 1;
    if(x[fbx[pn]]<y[fby[pm]])return solve2(fbx[pn]+1,pm);
    if(x[gbx[pn]]<y[gby[pm]])return solve2(pn,gby[pm]+1);
    return 0;
}
bool solve(){
    if(x[1]==y[1])return 0;
    if(x[1]>y[1]){
        for(int i=1;i<=n;i++)x[i]=-x[i];
        for(int i=1;i<=m;i++)y[i]=-y[i];
    }
    for(int i=1;i<=n;i++){
        fax[i]=gax[i]=i;
        if(i>1){
            if(x[fax[i-1]]<x[i])fax[i]=fax[i-1];
            if(x[gax[i-1]]>x[i])gax[i]=gax[i-1];
        }
    }
    for(int i=n;i>=1;i--){
        fbx[i]=gbx[i]=i;
        if(i<n){
            if(x[fbx[i+1]]<x[i])fbx[i]=fbx[i+1];
            if(x[gbx[i+1]]>x[i])gbx[i]=gbx[i+1];
        }
    }
    for(int i=1;i<=m;i++){
        fay[i]=gay[i]=i;
        if(i>1){
            if(y[fay[i-1]]<y[i])fay[i]=fay[i-1];
            if(y[gay[i-1]]>y[i])gay[i]=gay[i-1];
        }
    }
    for(int i=m;i>=1;i--){
        fby[i]=gby[i]=i;
        if(i<m){
            if(y[fby[i+1]]<y[i])fby[i]=fby[i+1];
            if(y[gby[i+1]]>y[i])gby[i]=gby[i+1];
        }
    }
    if(x[fax[n]]>=y[fay[m]])return 0;
    if(x[gax[n]]>=y[gay[m]])return 0;
    return solve1(fax[n]-1,gay[m]-1)&&solve2(fax[n]+1,gay[m]+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c;
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>tx[i];
    for(int i=1;i<=m;i++)cin>>ty[i];
    memcpy(x,tx,sizeof x);
    memcpy(y,ty,sizeof y);
    cout<<solve();
    while(q--){
        memcpy(x,tx,sizeof x);
        memcpy(y,ty,sizeof y);
        int kx,ky;
        cin>>kx>>ky;
        while(kx--){
            int p,v;
            cin>>p>>v;
            x[p]=v;
        }
        while(ky--){
            int p,v;
            cin>>p>>v;
            y[p]=v;
        }
        cout<<solve();
    }
    return 0;
}
