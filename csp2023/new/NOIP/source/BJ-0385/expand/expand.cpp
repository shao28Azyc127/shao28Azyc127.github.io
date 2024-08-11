#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    x*=f;
}
const int N=5e5+10;
int a[N],b[N],c,n,m,q,tmpa[N],tmpb[N],maxa,maxb,mina,minb;
void solve(){
    bool f=1;
    if(a[1]<b[1]) f=0;
    if(a[1]==b[1]||a[n]==b[n]){printf("0");return;}
    if(f&&a[n]<b[m]){printf("0");return;}
    if(!f&&a[n]>b[m]){printf("0");return;}
    maxa=0;maxb=0;
    for(int i=1;i<=n;++i) maxa=max(maxa,a[i]);
    for(int i=1;i<=m;++i) maxb=max(maxb,b[i]);
    if(maxa==maxb){printf("0");return;}
    if(f&&maxa<maxb){printf("0");return;}
    if(!f&&maxa>maxb){printf("0");return;}
    printf("1");
    return;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    read(c);read(n);read(m);read(q);
    for(int i=1;i<=n;++i) read(a[i]),tmpa[i]=a[i];
    for(int i=1;i<=m;++i) read(b[i]),tmpb[i]=b[i];
    solve();
    while(q--){
        int k1,k2;read(k1);read(k2);
        for(int i=1;i<=n;++i) a[i]=tmpa[i];
        for(int i=1;i<=m;++i) b[i]=tmpb[i];
        for(int i=1;i<=k1;++i){
            int p,x;read(p);read(x);
            a[p]=x;
        }
        for(int i=1;i<=k2;++i){
            int p,x;read(p);read(x);
            b[p]=x;
        }
        solve();
    }
    return 0;
}
/*
* sadly, it's impossible to print "no, commander" or "yes, commander" to get some points this time
*
* but our friend timswn is good at these kind of problem
*
* he must have solve this now
*
* so strong wow
*/

