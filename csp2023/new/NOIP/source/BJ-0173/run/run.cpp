#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 100005
typedef long long ll;
typedef pair<int,int> pii;
int n,m,k,d,c,T;
namespace work1{
    vector<pii> g[MAXN];
    ll f[1005][1005];
    void init(){
        for(int i=1;i<=n;i++) g[i].clear();
        memset(f,-0x3f3f3f3f,sizeof(f));
    }
    void solve(){
        init();
        for(int x,y,c,i=1;i<=m;i++){
            cin>>x>>y>>c;
            g[x].push_back({y,c});
        }
        for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
        f[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++) f[i][0]=max(f[i][0],f[i-1][j]);
            ll sum=0;
            for(int p=0,j=1;j<=k;j++){
                f[i][j]=f[i-1][j-1]-d;
                while(p<g[i].size()&&j>=g[i][p].first){
                    sum+=g[i][p].second;
                    p++;
                }
                f[i][j]+=sum;
            }
        }
        ll ans=0;
        for(int i=0;i<=k;i++) ans=max(ans,f[n][i]);
        cout<<ans<<endl;
    }
}
namespace work2{
    struct node{
        int x,y,c;
    }ask[MAXN];
    void solve(){
        ll ans=0;
        for(int i=1;i<=m;i++){
            cin>>ask[i].x>>ask[i].y>>ask[i].c;
            if(ask[i].y<=k) ans+=ask[i].c;
        }
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>m>>k>>d;
        if(c<=9) work1::solve();
        else work2::solve();
    }
    return 0;
}