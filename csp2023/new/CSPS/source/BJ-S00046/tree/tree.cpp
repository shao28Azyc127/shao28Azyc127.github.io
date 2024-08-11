#include<bits/stdc++.h>
using namespace std;
#define ll __int128
#define ld long double
#define y1 y114514
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mk make_pair
#define gc getchar
#define pc putchar
#define TIME 1e3*clock()/CLOCKS_PER_SEC
ll rd() {
    ll x=0,f=0;
    char c=gc();
    while(!isdigit(c)) f=(c=='-'?1:0),c=gc();
    while(isdigit(c)) x=x*10+c-48,c=gc();
    if(f==1) return -x;
    return x;
}
void wr(ll x) {
    if(x<0) pc('-'),wr(-x);
    if(x>9) wr(x/10);
    pc(x%10+'0');
}
bool Mst;

const int N=1e5+5;
ll n,a[N],b[N],c[N];
vector<int> e[N];
namespace solve1{

    void work() {
       // dfs(1,0);
       // cout<<dp[1];
    }

}
namespace solve2{
    ll calc(ll x) {
        ll ed=-1;
        if(c[x]<0) {
            ed=0;
        }
        if(ed!=-1) {
                if(b[x]+c[x]<=0) {
                    return a[x];
                }
                else {
                        ed=b[x]/abs(c[x]);
                        if(b[x]%abs(c[x])==0) ed--;
                                ll l=x,r=ed;
            ll now=b[x]*(r-l+1)+(r+l)*(r-l+1)/2*c[x];
            if(now>=a[x]) {
                ll L=x,R=ed,mid,res=x;
                while(L<=R) {
                    mid=(L+R)/2;
                    if(b[x]*(mid-l+1)+(mid+l)*(mid-l+1)/2*c[x]<a[x]) {
                        L=mid+1;
                    } else {
                    res=mid;
                    R=mid-1;
                    }
                }
                return res;
            } else {
                a[x]-=now;
                return a[x]+ed;
            }
                }

        } else {
            ll l=x;
            ll L=x,R=l+a[x],mid,res=x;
                            while(L<=R) {
                    mid=(L+R)/2;
                    if(b[x]*(mid-l+1)+(mid+l)*(mid-l+1)/2*c[x]<a[x]) {
                        L=mid+1;
                    } else {
                    res=mid;
                    R=mid-1;
                    }
                }
             //   wr(b[x]*(res-l+1)+(res+l)*(res-l+1)/2*c[x]),pc(' '),wr(res),pc(' '),wr(x),pc('\n');
            //    cout<<res<<' '<<x<<endl;
                return res;
        }
        return 1;
    }
    void work() {
        ll ans=0;
        rep(i,1,n) {
            ans=max(ans,calc(i));
          //  wr(calc(i)),pc('\n');
        }
        wr(ans);
    }
}
namespace solve3{
    ll calc(int x) {

    }
    void work() {
        ll ans=0;
        rep(i,1,n) {
            ans=max(ans,i+calc(i));
        }
      //  cout<<ans;
    }
}
namespace solve4{
    void work() {

    }
}


bool Med;
int main() {
  //  fprintf(stderr,"%.3lf MB\n",(&Mst-&Med)/1048576.0);

    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=rd();
    bool ok1=1,ok2=1,ok3=0,ok4=1;
    rep(i,1,n) a[i]=rd(),b[i]=rd(),c[i]=rd();
    rep(i,1,n) if(c[i]!=0) ok1=0;
    rep(i,1,n-1) {
        int u,v;
        cin>>u>>v;
        if(u!=1) ok4=0;
        if(u!=i||v!=i+1) ok2=0;
        e[u].pb(v),e[v].pb(u);
    }
    if(ok1) {
        solve1::work();
        return 0;
    }
    if(ok2) {
        solve2::work();
        return 0;
    }
    if(ok3) {
        solve3::work();
        return 0;
    }
    if(ok4) {
        solve4::work();
        return 0;
    }
  //  cerr<<'\n'<<TIME;
    return 0;
}
