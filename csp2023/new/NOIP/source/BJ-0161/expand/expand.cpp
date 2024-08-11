#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
using namespace std;
typedef pair<int,int> Pair;
template<class T>inline T qmax(const T &x,const T &y){return x>y?x:y;}
template<class T>inline T qmin(const T &x,const T &y){return x<y?x:y;}
inline void qread(){}template<class T1,class ...T2>
inline void qread(T1 &a,T2 &...b){
    register T1 x=0;register bool f=false;char ch=getchar();
    while(ch<'0') f|=(ch=='-'),ch=getchar();
    while(ch>='0') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    x=(f?-x:x);a=x;qread(b...);
}const int MAXN=5e5+7;
int c,n,m,q,a[MAXN],b[MAXN],lim,x[MAXN],t[MAXN],x1[MAXN],t1[MAXN];
inline int randint(int l,int r){
    mt19937 eng(time(0));uniform_int_distribution<int>dis(l,r);
    return dis(eng);
}bool solve(){
    return (a[1]-b[1])*(a[n]-b[m])>0;
}int main(){
    fre("expand");
    // fre("expand//expand1");
    qread(c,n,m,q);int i,j;
    for(i=1;i<=n;i++) qread(a[i]);for(i=1;i<=m;i++) qread(b[i]);
    putchar(solve()?'1':'0');
    while(q--){
        int kx,ky,v;qread(kx,ky);
        for(i=1;i<=kx;i++) qread(x[i],v),t[x[i]]=a[x[i]],a[x[i]]=v;
        for(i=1;i<=ky;i++) qread(x1[i],v),t1[x1[i]]=b[x1[i]],b[x1[i]]=v;
        // for(i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
        // for(i=1;i<=n;i++) cout<<b[i]<<" ";cout<<endl;
        putchar(solve()?'1':'0');
        for(i=1;i<=kx;i++) a[x[i]]=t[x[i]];
        for(i=1;i<=ky;i++) b[x1[i]]=t1[x1[i]];
    }
    return 0;
}