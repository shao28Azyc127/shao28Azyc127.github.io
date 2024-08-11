#include <bits/stdc++.h>
#define int long long
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
}const int MAXN=1e3+7,MAXM=1e5+7;
int c,T,n,m,k,d;vector<Pair>a[MAXN];int f[MAXN][MAXN];
signed main(){
    fre("run");
    // fre("run//run3");
    qread(c,T);int i,j;
    while(T--){
        qread(n,m,k,d);mem(f,0xcf);f[0][0]=0;
        for(i=1;i<=m;i++){
            int x,y,v;qread(x,y,v);
            a[x].emplace_back(Pair(y,v));
        }for(i=1;i<=n;i++){
            for(j=0;j<=k;j++) f[i][0]=qmax(f[i][0],f[i-1][j]);
            for(j=1;j<=k;j++){
                int sum=-d;
                for(auto t:a[i]) if(t.first<=j) sum+=t.second;
                f[i][j]=f[i-1][j-1]+sum;
            }
        }int ans=f[0][1];for(i=0;i<=k;i++) ans=qmax(ans,f[n][i]);
        printf("%lld\n",ans);for(i=1;i<=n;i++) a[i].clear();
    }
    return 0;
}