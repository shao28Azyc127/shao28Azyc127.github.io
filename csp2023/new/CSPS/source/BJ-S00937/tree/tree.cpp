#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20;
int n;
int a[N],b[N],c[N];
vector<int> e[N];
ll f[1<<N][N];
bool ch(ll mid,ll k,ll a,ll b,ll c){
    if(c>=0){
        return (mid-k+1)*b+(k+mid)*(mid-k+1)/2*c>=a;
    }
    ll cc=abs(c);
    ll fj=(b-1)/cc;
    if(fj<k)return mid-k+1>=a;
    if(fj>=mid)return (mid-k+1)*b-(k+mid)*(mid-k+1)/2*cc>=a;
    return (fj-k+1)*b-(fj+k)*(fj-k+1)/2*cc+mid-fj>=a;
}
ll ge(ll k,ll a,ll b,ll c){
    ll l=k,r=1e9+5;
    while(l<r){
        ll mid=l+r>>1;
        if(ch(mid,k,a,b,c))r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;u--;v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(f,0x3f,sizeof(f));
    f[1][1]=ge(1,a[0],b[0],c[0]);
    for(int i=1;i<(1<<n);++i){
        for(int dy=1;dy<=n;++dy){
            for(int j=0;j<n;++j){
                if(i&(1<<j)){
                    for(int k:e[j]){
                        if(i&(1<<k))continue;
                        f[i|(1<<k)][dy+1]=min(f[i|(1<<k)][dy+1],max(f[i][dy],ge(dy+1,a[k],b[k],c[k])));
                    }
                }
            }
        }
    }
    cout<<f[(1<<n)-1][n];
    return 0;
}
