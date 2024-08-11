#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define int long long
int c,T,n,m,k,d,out,dp[N],x[N],y[N],v[N];
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;++i) cin>>x[i]>>y[i]>>v[i];
        if(c==17||c==18){
            out=0;
            for(int i=1;i<=m;++i) out+=max(0ll,v[i]-y[i]*d);
            cout<<out<<'\n';
            continue;
        }
    }
}
