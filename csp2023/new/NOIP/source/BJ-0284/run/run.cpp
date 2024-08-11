#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
const int N=1e5+5,F=2e3+5;
int c,t,n,m,k,d,x[N],y[N],v[N],h[N],sum,ans;
bool flag[N] ;
void good(int cur,int s,int c){
    if(c>k)
        return;
    if(s+sum<=ans)
        return;
    if(cur>n){
        for(int i=1;i<=n;i++){
            h[i]=h[i-1]+flag[i];
        }
        for(int i=1;i<=m;i++){
            if( h[x[i]]-h[x[i]-y[i]] == y[i])
                s+=v[i];
        }
        ans=max(ans,s);
        return;
    }
    flag[cur]=true;
    good(cur+1,s-d,c+1);
    flag[cur]=false;
    good(cur+1,s,0);
}
signed main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>x[i]>>y[i]>>v[i];
            sum+=v[i];
        }
        ans=0;
        good(1,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
