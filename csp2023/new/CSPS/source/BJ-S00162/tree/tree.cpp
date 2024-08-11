#include <bits/stdc++.h>
#define int long long
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> Pair;
template<class T>inline T qmax(const T &x,const T &y){return x>y?x:y;}
template<class T>inline T qmin(const T &x,const T &y){return x<y?x:y;}
inline void qread(){}template<class T1,class ...T2>
inline void qread(T1 &a,T2 &...b){
    register int x=0;register bool f=false;char ch=getchar();
    while(ch<'0') f|=(ch=='-'),ch=getchar();
    while(ch>='0') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    x=(f?-x:x);a=x;qread(b...);
}const int MAXN=1e5+7;
int n,a[MAXN],b[MAXN],c[MAXN],f[1<<21],mp[21][21];
    int cal(int l,int r,int i){
        if(c[i]>=0) return b[i]*(r-l+1)+c[i]*((l+r)*(r-l+1)/2);
        int t=(b[i]-1)/(-c[i]);
        return b[i]*(t-l+1)+c[i]*((l+t)*(t-l+1)/2)+r-t;
    }
namespace _1{void solve(){
        int i,j;
        for(i=1;i<n;i++){
            int x,y;qread(x,y);
            mp[x][y]=mp[y][x]=1;
        }f[0]=0;
        for(int S=1;S<(1<<n);S++){
            int cnt=__builtin_popcount(S);f[S]=1e9;
            for(i=1;i<=n;i++){
                if(!(S&(1<<(i-1)))) continue;
                bool flag=false;
                for(j=1;j<=n;j++){
                    if((S&(1<<(j-1)))) continue;
                    flag|=mp[i][j];
                }if(!flag) continue;
                int l=n-cnt+1,r=1e9,res=r;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(cal(n-cnt+1,mid,i)>=a[i]) res=qmin(res,mid),r=mid-1;
                    else l=mid+1;
                }//cout<<"#"<<res<<" "<<n-cnt+1<<" "<<i<<endl;
                f[S]=qmin(f[S],qmax(f[S^(1<<(i-1))],res));
            }
        }
        // for(int S=0;S<(1<<n);S++) cout<<f[S]<<endl;
        printf("%d\n",f[(1<<n)-2]);
    }
}
signed main(){
    fre("tree");
    // fre("tree//tree2");
    qread(n);int i,j;for(i=1;i<=n;i++) qread(a[i],b[i],c[i]);
    if(n<=20) _1::solve();
    else{
        int ans=0;
        for(i=1;i<=n;i++){
            int l=i,r=1e9,res=r;
            while(l<=r){
                int mid=(l+r)>>1;
                if(cal(i,mid,i)>=a[i]) res=qmin(res,mid),r=mid-1;
                else l=mid+1;
            }ans=qmax(ans,res);
        }printf("%lld\n",ans);
    }return 0;
}