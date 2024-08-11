#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int testcase,n,m,q,k1,k2,siza,sizb;
int a[maxn],b[maxn],a0[maxn],b0[maxn],resa[maxn],resb[maxn];
inline void check(){
    if (a[1]==b[1] || a[n]==b[m]){
        printf("0");
        return ;
    }
    printf("%d",!(a[1]>b[1] ^ a[n]>b[m]));
    return ;
}
inline void solve(){
    scanf("%d%d",&k1,&k2);
    for (int i=1;i<=n;i++) a[i]=a0[i];
    for (int i=1;i<=m;i++) b[i]=b0[i];
    for (int i=1,x,y;i<=k1;i++) scanf("%d%d",&x,&y),a[x]=y;
    for (int i=1,x,y;i<=k2;i++) scanf("%d%d",&x,&y),b[x]=y;
    check();
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&testcase,&n,&m,&q);
    for (int i=1;i<=n;i++) scanf("%d",&a0[i]),a[i]=a0[i];
    for (int i=1;i<=m;i++) scanf("%d",&b0[i]),b[i]=b0[i];
    check();
    while (q--) solve();
    return 0;
}
