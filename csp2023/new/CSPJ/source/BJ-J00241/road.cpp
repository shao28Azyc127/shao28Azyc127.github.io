#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e5+10;
const int inf=1e18; 
int n,d,ans;
int dis[maxn],a[maxn];
inline void input(){
    scanf("%lld%lld",&n,&d);
    for(int i=2;i<=n;i++){
        int u;
        scanf("%lld",&u);
        dis[i]=dis[i-1]+u;
    }
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    a[n]=-inf;
}
inline void solve(){
    int x=1,w=0;
    while(x<n){
        int s;
        for(int i=x+1;i<=n;i++){
            if(a[i]<a[x]){
                s=i;
                break;
            }
        }
        int t=dis[s]-dis[x];
        if(w>=t){
            w-=t;
            x=s;
        }
        else{
            int p=(t-w)/d;
            if((t-w)%d)++p;
            w=w+p*d-t;
            ans=ans+p*a[x];
            x=s;
        }
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    input();
    solve();
    return 0;
}