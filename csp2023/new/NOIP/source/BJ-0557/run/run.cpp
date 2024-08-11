#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,T;
int n,m,k,d;
ll f[10][100001];
struct challenge{
    ll x,y,v,u;
}a[100001];
bool cmp(challenge A,challenge B){
    return A.u<B.u;
}
ll ans;
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>T;
    for(int K=1;K<=T;K++){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>a[i].x>>a[i].y>>a[i].v;
            if(a[i].y<=k&&a[i].v>a[i].y*d) ans+=a[i].v-a[i].y*d;
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
