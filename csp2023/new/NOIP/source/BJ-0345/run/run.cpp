
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1000005;

ll rd() {
    ll s=0, f=1;
    char ch=getchar();
    for(; !isdigit(ch); ch=getchar())
        if(ch=='-') f=-1;
    for(; isdigit(ch); ch=getchar())
        s=(s<<1)+(s<<3)+(ch^48);
    return s*f;
}

ll n, m, k, d;

struct chel{
    ll x, y, v;
} c[N];

ll v[N], sum[N], ans;

void check() {
    ll res=0;
    memset(sum, 0, sizeof sum);
    for(ll i=1; i<=n; i++) if(v[i]) res--;
    for(ll i=1; i<=n; i++) if(v[i]) sum[i]=sum[i-1]+v[i];

   // for(ll i=1; i<=n; i++) cout << v[i] <<" "; cout <<endl;
   // for(ll i=1; i<=n; i++) cout << sum[i] <<" ";cout <<endl;

   // cout <<res <<endl;
    for(ll i=1; i<=m; i++) {
        ll x=c[i].x, y=c[i].y;
        if(sum[x]>=y) res+=c[i].v;
    }

 //   cout << res <<endl;

    ans=max(ans, res);

    return;
}

void dfs(ll x, ll s, ll l) {
    if(x>=n+1) {
        check();
        return;
    }
    if(l>=k) v[x]=0, dfs(x+1, s, 0);
    else {
        v[x]=0, dfs(x+1, s, 0);
        v[x]=1, dfs(x+1, s+1, l+1);
    }
}

void work() {
    n=rd(), m=rd(), k=rd(), d=rd();

    ans=-1e9;

    for(ll i=1; i<=m; i++) {
        c[i].x=rd(), c[i].y=rd(), c[i].v=rd();
    }

    dfs(1, 0, 0);

    printf("%lld\n", ans);

}

ll C, T;

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    C=rd(), T=rd();

    while(T--) work();

    return 0;
}
