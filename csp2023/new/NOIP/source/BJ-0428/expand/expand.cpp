// 25pts
#include<bits/stdc++.h>
#define ll long long
#define mkp(x,y) make_pair(x,y);
using namespace std;
const int N=5e5+5;
const int M=1e6+5;
const int INF=2e9+5;
template<typename T>
void read(T &x) {
    x=0;
    int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-48;
    x*=f;
}
int c,n,m,q,f[5005][5005];
ll a[N],b[N],aa[N],bb[N];
bool check() {
    if(c==1)return 1;
    if(c==2) {
        if(n==1&&m==1)return 1;
        if(n==1&&m==2)return (1ll*(a[1]-b[1])*(a[1]-b[2])>0);
        if(n==2&&m==1)return (1ll*(a[1]-b[1])*(a[2]-b[1])>0);
        if(n==2&&m==2)return (1ll*(a[1]-b[1])*(a[2]-b[2])>0);
    }
    if(1ll*(a[1]-b[1])*(a[n]-b[m])<=0)return 0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f[i][j]=0;
    f[0][0]=f[0][1]=f[1][0]=1;int zf=(a[1]-b[1]);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(1ll*(a[i]-b[j])*zf>0)f[i][j]=(f[i-1][j]|f[i][j-1]|f[i-1][j-1]);
            else f[i][j]=0;
        }
    }
    return f[n][m];
}
int main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    read(c),read(n),read(m),read(q);
    for(int i=1;i<=n;i++)read(a[i]),aa[i]=a[i];
    for(int i=1;i<=m;i++)read(b[i]),bb[i]=b[i];
    printf("%d",check());
    while(q--) {
        int k1,k2;
        for(int i=1;i<=n;i++)a[i]=aa[i];
        for(int i=1;i<=m;i++)b[i]=bb[i];
        read(k1),read(k2);
        for(int i=1;i<=k1;i++) {
            int x;ll v;
            read(x),read(v);
            a[x]=v;
        }
        for(int i=1;i<=k2;i++) {
            int x;ll v;
            read(x),read(v);
            b[x]=v;
        }
        printf("%d",check());
    }
    return 0;
}
