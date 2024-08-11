#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
LL a[N],v[N],n,d,f[N];
LL pa[N],pv[N];
int vdis(int s,int r){

    int dist=pv[r]-pv[s];
    int you;
    if(dist%d==0) you=dist/d;
    else you=dist/d+1;

    return you;
}
int smin(int x){
    int minn=f[1]+vdis(1,x)*a[1];
    for(int i=2;i<x;i++){
        int tmp=f[i]+vdis(i,x)*a[i];

        if(tmp<minn){
            minn=tmp;
        }
    }

    return minn;
}

int Solve(){
    f[0]=0;
    f[1]=0;
    int y;
    if(pv[2]%d==0){
        y=pv[2]/d*a[1];
        f[2]=y;
    }
    else{
        y=(pv[2]/d+1)*a[1];
        f[2]=y;
    }

    for(int i=3;i<=n;i++){
        f[i]=smin(i);

    }
}

bool qiu(){
    int minn=v[1];
    for(int i=2;i<=n;i++){
        if(v[i]<minn) minn=v[i];
    }
    if(minn==v[1]) return 1;
}

int main(){
    freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
    cin>>n>>d;
    for(LL i=1;i<n;i++){
        cin>>v[i];
        pv[i+1]=pv[i]+v[i];
    }
    for(LL i=1;i<=n;i++){
        cin>>a[i];
        pa[i]=pa[i-1]+v[i];
    }
    if(qiu()){
        LL maxn=pv[n];
        LL ans;
        if(maxn%d==0){
            ans=maxn/d*a[1];
        }
        else{
            ans=(maxn/d+1)*a[1];
        }
        cout<<ans;
        return 0;
    }
    Solve();
    cout<<f[n];
    return 0;
}
