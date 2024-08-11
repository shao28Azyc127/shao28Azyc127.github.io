#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+5;
ll test,n,m,q,kx,ky,p,v;
ll a[maxn],b[maxn],ans[110],c[maxn],d[maxn];
bool f[2010][2010];
ll read(){
    ll f=1,num=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        num=(num<<3)+(num<<1)+ch-'0';
        ch=getchar();
    }
    return f*num;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    test=read(); n=read(); m=read(); q=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=m;i++){
        b[i]=read();
    }
    bool flag=0;
    if(a[1]<b[1]){
        swap(n,m);
        swap(a,b);
        flag=1;
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]<b[j]) continue;
            f[i][j]=(f[i-1][j-1]|f[i][j-1])|f[i-1][j];
        }
    }
    ans[0]=f[n][m];
    if(flag){
        swap(n,m);
        swap(a,b);
    }
    memcpy(c,a,sizeof(a));
    memcpy(d,b,sizeof(b));
    for(int i=1;i<=q;i++){
        kx=read(); ky=read();
        for(int j=1;j<=kx;j++){
            p=read(); v=read();
            a[p]=v;
        }
        for(int j=1;j<=ky;j++){
            p=read(); v=read();
            b[p]=v;
        }
        int flag=0;
        if(a[1]<b[1]){
            swap(n,m);
            swap(a,b);
            flag=1;
        }
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i]<=b[j]) continue;
                f[i][j]=(f[i-1][j-1]|f[i][j-1])|f[i-1][j];
            }
        }
        ans[i]=f[n][m];
        if(flag){
            swap(n,m);
            swap(a,b);
        }
        memcpy(a,c,sizeof(c));
        memcpy(b,d,sizeof(d));
    }
    for(int i=0;i<=q;i++){
        cout<<ans[i];
    }
    return 0;
}
