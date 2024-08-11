#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
inline ll read(){
    ll s=0;char ch=getchar();
    while(ch>'9'||ch<'0') ch=getchar();
    while(ch<='9'&&ch>='0'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s;
}
ll a[N],b[N];
ll inita[N],initb[N];
ll maxa[N],maxb[N],mina[N],minb[N];
bool needexa[N],needexb[N];
int c,n,m,q;
bool check(){
    if((a[1]-b[1])*(a[n]-b[m])<=0) return false;
    if(a[1]>b[1]){
        if(maxa[n]<=maxb[m]||mina[n]<=minb[m]) return false;
        for(int i=n+1;i<=m;i++)needexa[i]=0;
        for(int i=m+1;i<=n;i++)needexb[i]=0;
        for(int i=1;i<=n;i++){
            if(a[i]<=minb[i]) needexa[i]=1;
            else needexa[i]=0;
        }
        for(int i=1;i<=m;i++){
            if(b[i]>=maxa[i]) needexb[i]=1;
            else needexb[i]=0;
        }
        for(int i=1;i<=max(m,n);i++){
            if(needexa[i]&&needexb[i]){
                return false;
            }
        }
    }else{
        if(maxb[m]<=maxa[n]||minb[m]<=mina[n]) return false;
        for(int i=n+1;i<=m;i++)needexb[i]=0;
        for(int i=m+1;i<=n;i++)needexa[i]=0;
        for(int i=1;i<=m;i++){
            if(b[i]<=mina[i]) needexb[i]=1;
            else needexb[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(a[i]>=maxb[i]) needexa[i]=1;
            else needexa[i]=0;
        }
        for(int i=1;i<=max(m,n);i++){
            if(needexa[i]&&needexb[i]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    mina[0]=minb[0]=LONG_MAX;
    for(int i=1;i<=n;i++){
        inita[i]=read();
        maxa[i]=max(maxa[i-1],inita[i]);
        mina[i]=min(mina[i-1],inita[i]);
    }
    for(int i=1;i<=m;i++){
        initb[i]=read();
        maxb[i]=max(maxb[i-1],initb[i]);
        minb[i]=min(minb[i-1],initb[i]);
    }
    for(int i=1;i<=n;i++){
        a[i]=inita[i];
    }
    for(int i=1;i<=m;i++){
        b[i]=initb[i];
    }
    if(check()) cout<<1;
    else cout<<0;
    while(q--){
        int kx,ky;
        cin>>kx>>ky;
        while(kx--){
            int x,v;
            x=read();v=read();
            a[x]=v;
        }
        for(int i=1;i<=n;i++){
            maxa[i]=max(maxa[i-1],a[i]);
            mina[i]=min(mina[i-1],a[i]);
        }
        while(ky--){
            int y,v;
            y=read();v=read();
            b[y]=v;
        }
        for(int i=1;i<=n;i++){
            maxb[i]=max(maxb[i-1],b[i]);
            minb[i]=min(minb[i-1],b[i]);
        }
        if(check())
            cout<<1;
        else
            cout<<0;
        for(int i=1;i<=n;i++){
            a[i]=inita[i];
        }
        for(int i=1;i<=m;i++){
            b[i]=initb[i];
        }
    }
    return 0;
}
