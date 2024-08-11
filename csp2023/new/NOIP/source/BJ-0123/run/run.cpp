#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int sid,T;
int n,m,k,d;
struct node{
    ll l,r,val;
}a[N];
ll dp[1010];
vector<node> v[1010];
inline void Do(){
    cin>>n>>m>>k>>d;
    for(int i=1;i<=m;i++){
        ll x,y,c; cin>>x>>y>>c;
        a[i]={x-y+1,x,c};
    }
    sort(a+1,a+1+m,[](node x,node y)->bool{
         return x.l<y.l||x.l==y.l&&x.r<y.r;
    });
    ll ans=0;
    if(sid<=9){
        for(int i=1;i<=m;i++){
            v[a[i].l].push_back(a[i]);
        }
        memset(dp,0,sizeof(dp));
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll tmp=0;
            dp[i]=dp[i-1];
            for(int j=1;j<=min(k,i);j++){
                tmp-=d;
                for(node nd:v[i-j+1]){
                    if(nd.r<=i) tmp+=nd.val;
                }
                dp[i]=max(dp[i],(i>j?dp[i-j-1]:0)+tmp);
            }
        }
        cout<<dp[n]<<"\n";
        for(int i=1;i<=n;i++) v[i].clear();
        return;
    }
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>sid>>T;
    while(T--) Do();
    return 0;
}
