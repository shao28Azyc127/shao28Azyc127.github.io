#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=500005;
int n,m,T,buf1[maxn],buf2[maxn],x[maxn],y[maxn],st[maxn],top;
int calc(){
    if(x[1]==y[1])return 0;
    if(x[1]>y[1]){
        for(int i=1;i<=n;++i)x[i]=999999999-x[i];
        for(int i=1;i<=m;++i)y[i]=999999999-y[i];
    }
    if(x[n]>=y[m])return 0;
    top=0;
    for(int i=1;i<=n;++i)if((i==1||x[i-1]>=x[i])&&(i==n||x[i+1]>x[i])){
        while(top>1&&x[st[top-1]]<=x[st[top]]&&x[st[top]]>=x[i])top--;
        st[++top]=i;
    }
    int pos=0;
    for(int i=1;i<=top;++i)if(pos==0||x[st[i]]<x[st[pos]])pos=i;
    int mn=0x3f3f3f3f;
    for(int i=1;i<=m;++i)mn=min(mn,y[i]);
    if(mn<=x[st[pos]])return 0;
    int g1=1,g2=m;
    for(int i=1;i<pos;++i){
        int mx=0;
        for(int j=st[i];j<=st[i+1];++j)mx=max(mx,x[j]);
        for(;g1<=m;++g1){
            if(y[g1]>mx)break;
            if(y[g1]<=x[st[i]])return 0;
        }
    }
    for(int i=top;i>pos;--i){
        int mx=0;
        for(int j=st[i-1];j<=st[i];++j)mx=max(mx,x[j]);
        for(;g2>=1;--g2){
            if(y[g2]>mx)break;
            if(y[g2]<=x[st[i]])return 0;
        }
    }
    if(g1<=g2)return 1;
    else return 0;
}
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;cin>>n>>m>>T;
    for(int i=1;i<=n;++i)cin>>buf1[i];
    for(int i=1;i<=m;++i)cin>>buf2[i];
    for(int i=1;i<=n;++i)x[i]=buf1[i];
    for(int i=1;i<=m;++i)y[i]=buf2[i];
    cout<<calc();
    while(T--){
        int kx,ky;cin>>kx>>ky;
        for(int i=1;i<=n;++i)x[i]=buf1[i];
        for(int i=1;i<=m;++i)y[i]=buf2[i];
        while(kx--){
            int p,v;cin>>p>>v;
            x[p]=v;
        }
        while(ky--){
            int p,v;cin>>p>>v;
            y[p]=v;
        }
        cout<<calc();
    }
    return 0;
}