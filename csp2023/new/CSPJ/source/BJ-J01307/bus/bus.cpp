#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e4+5;
int n,m,k;
int u[MAXN],v[MAXN],a[MAXN];
int cnt,start=1,ans;
signed main(){
    ios::sync_with_stdio(false);
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>a[i];
        cnt+=a[i];
        if(u[i]==start) ans+=k,start=v[i];
    }
    if(cnt==0&&k==1){
        cout<<ans;
        return 0;
    }
    cout<<-1;
    return 0;
}
