#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100010;
ll c,n,m,t,k,d,dp[N],cnt[N],ans,day[N];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m>>k>>d;
        //if(c==17||c==18){
            ans=0;
            for(int i=1;i<=m;i++){
                ll x,y,v;
                scanf("%lld %lld %lld",&x,&y,&v);
                if(y<=k&&v>=d*y){
                    ans+=(v-d*y);
                }
            }
            cout<<ans<<endl;
        //}
    }
    return 0;
}

