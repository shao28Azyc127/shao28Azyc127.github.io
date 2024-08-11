#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=100005;

ll n;
ll a[maxn], b[maxn], c[maxn];
ll u[maxn], v[maxn];

vector<ll> vec[maxn];

bool Af=1, Bf=1, Df=1;

ll ans;

bool vis[maxn];
ll nd[maxn];
void dfs(ll u, ll d) {
    vis[u]=d;
    for(ll i=0; i<vec[u].size(); i++) {
        ll v=vec[u][i];
        dfs(v, d+1);
    }
}
void workA() {
    dfs(1, 1);
    ans=-1e9;
    for(ll i=1; i<=n; i++) {
        ll nd;
        if(b[i]<1) nd=a[i];
        else {
            if(a[i]%b[i]==0) nd=a[i]/b[i];
            else nd=a[i]/b[i]+1;
        }
        ans=max(ans, nd);
    }
}

void workB() {
    //cout<<"B"<<endl;
    ans=-1e9;
    for(ll i=1; i<=n; i++) {
        ll nd=(i-1);
        //a[i]/max(b[i]+c[i]*i, 1);
        ll S=max(b[i]+c[i]*i, 1ll);
        if(a[i]%S==0) nd=a[i]/S+i-1;
        else nd=a[i]/S+i;
        ans=max(ans, nd);
    }
}

int main() {

    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i=1; i<=n; i++) {
        scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
    //    if(c[i]!=0) Af=0;
    }
    for(ll i=1; i<n; i++) {
        scanf("%lld %lld", &u[i], &v[i]);
        vec[u[i]].push_back(v[i]);
  //      if(u[i]!=1) Df=0;
//        if(u[i]!=i || v[i]!=i+1) Bf=0;
    }
    //out<<Af<<" "<<Bf<<" "<<Df<<endl;
    workB();
    printf("%lld", ans);
    return 0;
}
