/*you can do it*/
#include<bits/stdc++.h>
#define fr(ii,xx,yy) for(int ii=xx;ii<=yy;ii++)
#define rf(ii,xx,yy) for(int ii=xx;ii>=yy;ii--)
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define pt printf
#define int long long
inline void rd() {} template<typename T,typename...args>inline void rd(T&x,args&...y) {
    char ch;
    bool f=0;
    for(ch=getchar(); !isdigit(ch); ch=getchar())if(ch=='-')f=1;
    for(x=0; isdigit(ch); ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
    if(f)x=-x;
    rd(y...);
}
using namespace std;
const int N=1e6+33;
int n,m,k,d,a[N],s[N];
struct V {
    int x,y,z;
} v[N];
void so() {
    rd(n,m,k,d);
    fr(i,1,m) {
        rd(v[i].x,v[i].y,v[i].z);
    }
    sort(v+1,v+m+1,[](V a,V b) {
        return a.x<b.x;
    });
    int Z=(1<<n)-1,ans=0;
    fr(z,0,Z) {
        int maxx=0,cnt=0;
        fr(i,1,n) {
            a[i]=bool(z&(1<<i-1));
            if(a[i]==1)cnt++;
            else cnt=0;
            maxx=max(maxx,cnt);
        }
        if(maxx>k)continue;

        fr(i,1,n) {
            s[i]=s[i-1]+a[i];
        }

        int it=1,cur=0;
        fr(i,1,n){
            if(a[i]){
                cur-=d;
            }
            while(it<=m&&v[it].x==i){
                if(s[i]-s[i-v[it].y]==v[it].y){
                    cur+=v[it].z;
                }
                it++;
            }
          //  pt("%d:%d ",a[i],cur);
            ans=max(ans,cur);
        }//pt("\n");



    }
    pt("%lld\n",ans);
}
signed main() {
    freopen("run.in","r",stdin);
   freopen("run.out","w",stdout);
    int c,t;
    rd(c,t);
    while(t--) {
        so();
    }
    return 0;
}
